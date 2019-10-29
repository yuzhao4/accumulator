#include <pybind11/pybind11.h>
#include "math.hpp"
#include <pybind11/stl.h>
#include "pet.hpp"
#include "accumulator.hpp"

namespace py = pybind11;

PYBIND11_PLUGIN(python_cpp_example)
{
    py::module m("python_cpp_example");
    m.def("add", &add);
    m.def("subtract", &subtract);
    m.def("average", &average);

    // bindings to Pet class
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        .def("go_for_a_walk", &Pet::go_for_a_walk)
        .def("get_hunger", &Pet::get_hunger)
        .def("get_name", &Pet::get_name);

    // bindings to Accumulator class
    py::class_<Accumulator>(m, "Accumulator")
        .def(py::init<int, int, int, int>())
        .def("test", &Accumulator::test)
        .def("append", &Accumulator::append)
        .def("get_variance", &Accumulator::get_variance)
        .def("get_mean", &Accumulator::get_mean)
        .def("reset", &Accumulator::reset);
    
    // bindings to CovarianceAccumulator class
    py::class_<CovarianceAccumulator>(m, "CovarianceAccumulator")
        .def(py::init<int, int, int, int>())
        .def("append", &CovarianceAccumulator::append)
        .def("get_covariance", &CovarianceAccumulator::get_covariance)
        .def("get_mean", &CovarianceAccumulator::get_mean)
        .def("reset", &CovarianceAccumulator::reset);

    return m.ptr();

}

// PYBIND11_MODULE(pet_class, m) {
//     // optional module docstring
//     m.doc() = "pybind11 example plugin";

//     // define add function
//     m.def("add", &add, "A function which adds two numbers");


// }