//
// Created by Wladyslaw Nowak on 11/04/2021.
//

#include "FileReader.h"

int FileReader::readNextVal() {
    int nextVal;
    if (input.is_open()) {
        input >> nextVal;
        if (input.fail()) {
            throw runtime_error("File error - stopping program");
        }
        if (input.eof()) {
            input.close();
        }
        return nextVal;
    }
    throw runtime_error("File not opened - maybe it was already closed?");
    return 0;
}

FileReader::FileReader(const std::string &fileName) : fileName(fileName), input(fileName) {
    input >> edgeSize;
    input >> vertSize;
    input >> startVert;
    input >> endVert;
    if (!input.is_open()) {
        throw runtime_error("Could not read the file");
    }
    cout << "Edges: " << edgeSize << ", Vertices: "<<vertSize<<", Starting vertex: "<<startVert<<", Ending vertex: "<<endVert<<endl;
}

int FileReader::getStructureSize() const {
    return edgeSize;
}

void FileReader::readToAdjList(ListRepresentation *graph) {
    graph->setEdgeSize(edgeSize);
    graph->setVertSize(vertSize);
    graph->setStartingVertex(startVert);
    graph->setEndingVertex(endVert);
    int from, to, weight;
    for (int i = 0; i < edgeSize; i++){
        from = readNextVal();
        to = readNextVal();
        weight = readNextVal();
        graph->addConnection(from, to, weight);
    }
}

void FileReader::readToAdjMatrix(MatrixRepresentation *graph) {
    graph->setEdgeSize(edgeSize);
    graph->setVertSize(vertSize);
    graph->setStartingVertex(startVert);
    graph->setEndingVertex(endVert);
    int from, to, weight;
    for (int i = 0; i < edgeSize; i++){
        from = readNextVal();
        to = readNextVal();
        weight = readNextVal();
        graph->addConnection(from, to, weight);
    }
}
