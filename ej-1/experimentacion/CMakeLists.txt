cmake_minimum_required(VERSION 3.16)
project(experimentacion)

set(CMAKE_CXX_STANDARD 14)

add_executable(exp-djikstra-fast
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-djikstra-fast.cpp
        experimento.cpp)
target_compile_definitions(exp-djikstra-fast PUBLIC SRC=1)

add_executable(exp-djikstra-slow
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-djikstra-slow.cpp
        experimento.cpp)
target_compile_definitions(exp-djikstra-slow PUBLIC SRC=2)

add_executable(exp-bellford
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-bellford.cpp
        experimento.cpp)
target_compile_definitions(exp-bellford PUBLIC SRC=3)
