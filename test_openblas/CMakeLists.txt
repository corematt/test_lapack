cmake_minimum_required(VERSION 3.5)

project(test_openblas LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_LIST
    main.cpp
)

set(BLA_VENDOR OpenBLAS)
find_package(BLAS REQUIRED)
if(BLAS_FOUND)
    message("OpenBlasFound")
    message(${BLAS_LIBRARIES})
endif(BLAS_FOUND)

include_directories("C:\\Program Files\\OpenBLAS-0.3.21-x64\\include")

add_executable(test_openblas main.cpp)

target_link_libraries(test_openblas ${BLAS_LIBRARIES})
