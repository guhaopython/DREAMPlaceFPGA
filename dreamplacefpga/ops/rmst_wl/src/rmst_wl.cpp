/**
 * @file   rmst_wl.cpp
 * @author Yibo Lin (DREAMPlace)
 * @date   Jun 2018
 */
#include "utility/src/torch.h"
#include "utility/src/Msg.h"

extern "C" 
{
#include <flute.h>
}

DREAMPLACE_BEGIN_NAMESPACE

template <typename T>
int computeRMSTWLLauncher(
        const T* x, const T* y, 
        const int* flat_netpin, 
        const int* netpin_start, 
        const int ignore_net_degree, 
        int num_nets, 
        int read_lut_flag, 
        const char* POWVFILE, 
        const char* POSTFILE, 
        T* rmst_wl 
        );

#define CHECK_FLAT(x) AT_ASSERTM(!x.is_cuda() && x.ndimension() == 1, #x "must be a flat tensor on CPU")
#define CHECK_EVEN(x) AT_ASSERTM((x.numel()&1) == 0, #x "must have even number of elements")
#define CHECK_CONTIGUOUS(x) AT_ASSERTM(x.is_contiguous(), #x "must be contiguous")

int rmst_wl_forward(
        at::Tensor pos,
        at::Tensor flat_netpin,
        at::Tensor netpin_start, 
        int ignore_net_degree, 
        int read_lut_flag, 
        const char* POWVFILE, 
        const char* POSTFILE, 
        at::Tensor rmst_wl) 
{
    CHECK_FLAT(pos); 
    CHECK_EVEN(pos);
    CHECK_CONTIGUOUS(pos);
    CHECK_FLAT(flat_netpin);
    CHECK_CONTIGUOUS(flat_netpin);
    CHECK_FLAT(netpin_start);
    CHECK_CONTIGUOUS(netpin_start);
    CHECK_FLAT(rmst_wl);
    CHECK_CONTIGUOUS(rmst_wl);

    int ret = 0; 
    DREAMPLACE_DISPATCH_FLOATING_TYPES(pos, "computeRMSTWLLauncher", [&] {
            computeRMSTWLLauncher<scalar_t>(
                    DREAMPLACE_TENSOR_DATA_PTR(pos, scalar_t), DREAMPLACE_TENSOR_DATA_PTR(pos, scalar_t)+pos.numel()/2, 
                    DREAMPLACE_TENSOR_DATA_PTR(flat_netpin, int), 
                    DREAMPLACE_TENSOR_DATA_PTR(netpin_start, int), 
                    ignore_net_degree, 
                    netpin_start.numel()-1, 
                    read_lut_flag, 
                    POWVFILE, 
                    POSTFILE, 
                    DREAMPLACE_TENSOR_DATA_PTR(rmst_wl, scalar_t)
                    );
            });
    return ret; 
}

template <typename T>
int computeRMSTWLLauncher(
        const T* x, const T* y, 
        const int* flat_netpin, 
        const int* netpin_start, 
        const int ignore_net_degree, 
        int num_nets, 
        int read_lut_flag, 
        const char* POWVFILE, 
        const char* POSTFILE, 
        T* rmst_wl 
        )
{
    // read look-up table for flute 
    if (read_lut_flag)
    {
        readLUT(POWVFILE, POSTFILE);
    }
    // temporary store x and y positions 
    std::vector<int> vx (ignore_net_degree, 0); 
    std::vector<int> vy (ignore_net_degree, 0); 
    int scale = 1000; // scale factor, flute only supports integer  
    for (int i = 0; i < num_nets; ++i)
    {
        int degree = netpin_start[i+1]-netpin_start[i];
        // ignore large degree nets 
        if (degree >= ignore_net_degree)
        {
            rmst_wl[i] = 0; 
            continue; 
        }

        std::fill(vx.begin(), vx.end(), 0);
        std::fill(vy.begin(), vy.end(), 0);
        for (int j = netpin_start[i], k = 0; j < netpin_start[i+1]; ++j, ++k)
        {
            vx[k] = x[flat_netpin[j]]*scale;
            vy[k] = y[flat_netpin[j]]*scale;
        }
        int wl = flute_wl(degree, vx.data(), vy.data(), ACCURACY);
        rmst_wl[i] = wl/(T)scale; 
    }

    return 0; 
}

DREAMPLACE_END_NAMESPACE

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("forward", &DREAMPLACE_NAMESPACE::rmst_wl_forward, "RMSTWL forward");
}
