cmake_minimum_required(VERSION 3.19)
project(SDiZO2)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_EXE_LINKER_FLAGS "-static")
link_directories()
add_executable(SDiZO2 main.cpp src/GraphStructures/MatrixRepresentation.cpp src/GraphStructures/MatrixRepresentation.h src/GraphStructures/ListRepresentation.cpp src/GraphStructures/ListRepresentation.h src/GraphStructures/util/AdjList.cpp src/GraphStructures/util/AdjList.h src/GraphStructures/Algorithms/KruskalMatrix.cpp src/GraphStructures/Algorithms/KruskalMatrix.h src/GraphStructures/Algorithms/KruskalList.cpp src/GraphStructures/Algorithms/KruskalList.h)
