cmake_minimum_required(VERSION 2.8.12)
project(python_cpp_example)

set(Boost_INCLUDE_DIR /usr/local/boost/include)
set(Boost_LIBRARY_DIR /usr/local/boost/lib)

find_package(Boost REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  message(STATIC "\nfound boost library\n")
endif()

# Set source directory
set(SOURCE_DIR "src/python_cpp_example")
# Tell CMake that headers are also in SOURCE_DIR
include_directories(${SOURCE_DIR})
set(SOURCES "${SOURCE_DIR}/math.cpp")
# Generate Python module
add_subdirectory(lib/pybind11)
pybind11_add_module(python_cpp_example ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
