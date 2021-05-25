//
// Created by Wladyslaw Nowak on 11/04/2021.
//

#ifndef SDIZO2_FILEREADER_H
#define SDIZO2_FILEREADER_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "../Algorithms/Prims/PrimsList.h"
#include "../Algorithms/Prims/PrimsMatrix.h"
#include "../Algorithms/Kruskal/KruskalList.h"
#include "../Algorithms/Kruskal/KruskalMatrix.h"
#include "../Algorithms/FordFulkerson/FordFulkersonList.h"
#include "../Algorithms/FordFulkerson/FordFulkersonMatrix.h"
#include "../Algorithms/Dijsktra/DijsktraList.h"
#include "../Algorithms/Dijsktra/DijsktraMatrix.h"
#include "../Algorithms/BellmanFord/BellmanFordList.h"
#include "../Algorithms/BellmanFord/BellmanFordMatrix.h"

using namespace std;

/**
 * This class helps reading int data from files and creating graphs from them. <br/>
 * Data should be delimited with spaces or other white characters. <br/>
 * In first line: amount of edges in this graph, amount of vertices, starting vertex, ending vertex <br/>
 * Rest of file should be the data.
 */
class FileReader {
private:
    /**
     * Name of input file.
     */
    std::string fileName;

    /**
     * File input stream.
     */
    ifstream input;

    /**
     * Amount of edges this graph has.
     */
    int edgeSize = 0;

    /**
     * Amount of vertices this graph has.
     */
    int vertSize = 0;

    /**
     * Starting vertex.
     */
    int startVert = 0;

    /**
     * Ending vertex.
     */
    int endVert = 0;

    /**
     * Get next value from file and return it.
     * @return Value read from the file.
     */
    int readNextVal();

public:
    /**
     * Create new instance of this class with name of file to read from.
     * This class also performs first read from file - it reads and stores first value representing amount of data in this file.
     * @param fileName Name of file to read from.
     */
    explicit FileReader(const std::string& fileName);

    /**
     * Read data to graph structure.
     * @return Ptr to graph structure.
     */
    void readToAdjList(ListRepresentation* graph);

    /**
    * Read data to graph structure.
    * @return Ptr to graph structure.
    */
    void readToAdjMatrix(MatrixRepresentation* graph);

    /**
     * Get amount of items stored in input file.
     * @return Value equal to amount of int values stored in input file.
     */
    int getStructureSize() const;


};


#endif //SDIZO2_FILEREADER_H
