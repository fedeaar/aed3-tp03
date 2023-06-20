cmake_minimum_required(VERSION 3.16)
project(experimentacion)

set(CMAKE_CXX_STANDARD 14)

add_executable(exp-dijkstra-fast
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-fast.cpp
        experimento.cpp)
target_compile_definitions(exp-dijkstra-fast PUBLIC SRC=1)

add_executable(exp-dijkstra-slow
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-slow.cpp
        experimento.cpp)
target_compile_definitions(exp-dijkstra-slow PUBLIC SRC=2)

add_executable(exp-dijkstra-queue
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-queue.cpp
        experimento.cpp)
target_compile_definitions(exp-dijkstra-queue PUBLIC SRC=3)


add_executable(exp-dijkstra-fast-ralo
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-fast.cpp
        experimento_ralo.cpp)
target_compile_definitions(exp-dijkstra-fast-ralo PUBLIC SRC=1)

add_executable(exp-dijkstra-slow-ralo
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-slow.cpp
        experimento_ralo.cpp)
target_compile_definitions(exp-dijkstra-slow-ralo PUBLIC SRC=2)

add_executable(exp-dijkstra-queue-ralo
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-queue.cpp
        experimento_ralo.cpp)
target_compile_definitions(exp-dijkstra-queue-ralo PUBLIC SRC=3)


add_executable(exp-dijkstra-fast-ralo-small
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-fast.cpp
        experimento_ralo_small.cpp)
target_compile_definitions(exp-dijkstra-fast-ralo-small PUBLIC SRC=1)

add_executable(exp-dijkstra-slow-ralo-small
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-slow.cpp
        experimento_ralo_small.cpp)
target_compile_definitions(exp-dijkstra-slow-ralo-small PUBLIC SRC=2)

add_executable(exp-dijkstra-queue-ralo-small
        ./algoritmos/trafico.h
        ./algoritmos/impl/trafico-dijkstra-queue.cpp
        experimento_ralo_small.cpp)
target_compile_definitions(exp-dijkstra-queue-ralo-small PUBLIC SRC=3)
