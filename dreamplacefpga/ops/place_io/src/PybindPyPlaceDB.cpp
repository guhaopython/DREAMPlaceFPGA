/**
 * @file   PybindPyPlaceDB.cpp
 * @author Yibo Lin (DREAMPlace), Rachel Selina Rajarathnam (DREAMPlaceFPGA)
 * @date   Mar 2021
 * @brief  Python binding for PyPlaceDB 
 */

#include "PyPlaceDB.h"

void bind_PyPlaceDB(pybind11::module& m) 
{
    pybind11::class_<DREAMPLACE_NAMESPACE::PyPlaceDB>(m, "PyPlaceDB")
        .def(pybind11::init<>())
        .def_readwrite("node_names", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_names)
        .def_readwrite("node_size_x", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_size_x)
        .def_readwrite("node_size_y", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_size_y)
        .def_readwrite("node_types", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_types)
        .def_readwrite("flop_indices", &DREAMPLACE_NAMESPACE::PyPlaceDB::flop_indices)
        .def_readwrite("node2fence_region_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::node2fence_region_map)
        .def_readwrite("node_x", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_x)
        .def_readwrite("node_y", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_y)
        .def_readwrite("node_z", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_z)
        .def_readwrite("node2pin_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::node2pin_map)
        .def_readwrite("flat_node2pin_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_node2pin_map)
        .def_readwrite("flat_node2pin_start_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_node2pin_start_map)
        .def_readwrite("node2pincount_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::node2pincount_map)
        .def_readwrite("net2pincount_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::net2pincount_map)
        .def_readwrite("node2outpinIdx_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::node2outpinIdx_map)
        .def_readwrite("lut_type", &DREAMPLACE_NAMESPACE::PyPlaceDB::lut_type)
        .def_readwrite("node_name2id_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_name2id_map)
        .def_readwrite("num_terminals", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_terminals)
        .def_readwrite("num_movable_nodes", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_movable_nodes)
        .def_readwrite("num_physical_nodes", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_physical_nodes)
        .def_readwrite("node_count", &DREAMPLACE_NAMESPACE::PyPlaceDB::node_count)
        .def_readwrite("pin_offset_x", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin_offset_x)
        .def_readwrite("pin_offset_y", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin_offset_y)
        .def_readwrite("pin2nodeType_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin2nodeType_map)
        .def_readwrite("pin_names", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin_names)
        .def_readwrite("pin_types", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin_types)
        .def_readwrite("pin_typeIds", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin_typeIds)
        .def_readwrite("pin2net_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin2net_map)
        .def_readwrite("pin2node_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::pin2node_map)
        .def_readwrite("net_names", &DREAMPLACE_NAMESPACE::PyPlaceDB::net_names)
        .def_readwrite("net2pin_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::net2pin_map)
        .def_readwrite("flat_net2pin_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_net2pin_map)
        .def_readwrite("flat_net2pin_start_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_net2pin_start_map)
        .def_readwrite("net_name2id_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::net_name2id_map)
        .def_readwrite("num_sites_x", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_sites_x)
        .def_readwrite("num_sites_y", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_sites_y)
        .def_readwrite("site_type_map", &DREAMPLACE_NAMESPACE::PyPlaceDB::site_type_map)
        .def_readwrite("lg_siteXYs", &DREAMPLACE_NAMESPACE::PyPlaceDB::lg_siteXYs)
        .def_readwrite("dspSiteXYs", &DREAMPLACE_NAMESPACE::PyPlaceDB::dspSiteXYs)
        .def_readwrite("ramSiteXYs", &DREAMPLACE_NAMESPACE::PyPlaceDB::ramSiteXYs)
        .def_readwrite("flat_region_boxes", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_region_boxes)
        .def_readwrite("flat_region_boxes_start", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_region_boxes_start)
        .def_readwrite("spiral_accessor", &DREAMPLACE_NAMESPACE::PyPlaceDB::spiral_accessor)
        .def_readwrite("spiral_maxVal", &DREAMPLACE_NAMESPACE::PyPlaceDB::spiral_maxVal)
        .def_readwrite("ctrlSets", &DREAMPLACE_NAMESPACE::PyPlaceDB::ctrlSets)
        .def_readwrite("flat_ctrlSets", &DREAMPLACE_NAMESPACE::PyPlaceDB::flat_ctrlSets)
        .def_readwrite("num_routing_grids_x", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_routing_grids_x)
        .def_readwrite("num_routing_grids_y", &DREAMPLACE_NAMESPACE::PyPlaceDB::num_routing_grids_y)
        .def_readwrite("routing_grid_xl", &DREAMPLACE_NAMESPACE::PyPlaceDB::routing_grid_xl)
        .def_readwrite("routing_grid_yl", &DREAMPLACE_NAMESPACE::PyPlaceDB::routing_grid_yl)
        .def_readwrite("routing_grid_xh", &DREAMPLACE_NAMESPACE::PyPlaceDB::routing_grid_xh)
        .def_readwrite("routing_grid_yh", &DREAMPLACE_NAMESPACE::PyPlaceDB::routing_grid_yh)
        .def_readwrite("xl", &DREAMPLACE_NAMESPACE::PyPlaceDB::xl)
        .def_readwrite("yl", &DREAMPLACE_NAMESPACE::PyPlaceDB::yl)
        .def_readwrite("xh", &DREAMPLACE_NAMESPACE::PyPlaceDB::xh)
        .def_readwrite("yh", &DREAMPLACE_NAMESPACE::PyPlaceDB::yh)
        .def_readwrite("row_height", &DREAMPLACE_NAMESPACE::PyPlaceDB::row_height)
        .def_readwrite("site_width", &DREAMPLACE_NAMESPACE::PyPlaceDB::site_width)
        ;

}

