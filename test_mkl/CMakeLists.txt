cmake_minimum_required(VERSION 3.5)

project(test_mkl LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_LIST
    main.cpp
)

set(MKL_INTERFACE "lp64")
find_package(MKL CONFIG REQUIRED)
include_directories(${MKL_INCLUDE})

message(STATUS "${MKL_IMPORTED_TARGETS}") #Provides available list of targets based on input

add_executable(test_mkl main.cpp)

target_link_libraries(test_mkl MKL::MKL)
