cmake_minimum_required(VERSION 3.19)
project(SDiZO2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
link_directories()

add_executable(SDiZO2 main.cpp
        src/GraphRepresentations/MatrixRepresentation.cpp
        src/GraphRepresentations/MatrixRepresentation.h
        src/GraphRepresentations/ListRepresentation.cpp
        src/GraphRepresentations/ListRepresentation.h
        src/util/AdjList.cpp src/util/AdjList.h
        src/Algorithms/Kruskal/KruskalMatrix.cpp
        src/Algorithms/Kruskal/KruskalMatrix.h
        src/Algorithms/Kruskal/KruskalList.cpp
        src/Algorithms/Kruskal/KruskalList.h
        src/Algorithms/Prims/PrimsMatrix.cpp
        src/Algorithms/Prims/PrimsMatrix.h
        src/Algorithms/Prims/PrimsList.cpp
        src/Algorithms/Prims/PrimsList.h
        src/Algorithms/Dijsktra/DijsktraMatrix.cpp
        src/Algorithms/Dijsktra/DijsktraMatrix.h
        src/Algorithms/Dijsktra/DijsktraList.cpp
        src/Algorithms/Dijsktra/DijsktraList.h
        src/Algorithms/BellmanFord/BellmanFordList.cpp
        src/Algorithms/BellmanFord/BellmanFordList.h
        src/Algorithms/BellmanFord/BellmanFordMatrix.cpp
        src/Algorithms/BellmanFord/BellmanFordMatrix.h
        src/Algorithms/FordFulkerson/FordFulkersonMatrix.cpp
        src/Algorithms/FordFulkerson/FordFulkersonMatrix.h
        src/util/Queue.cpp src/util/Queue.h
        src/Algorithms/FordFulkerson/FordFulkersonList.cpp
        src/Algorithms/FordFulkerson/FordFulkersonList.h
        src/IO/CSVWriter.h
        src/IO/CSVWriter.cpp
        src/IO/FileReader.h
        src/IO/FileReader.cpp
        src/Menu.cpp
        src/Menu.h
        src/AlgType.h
        src/Benchmark.cpp
        src/Benchmark.h
        )
