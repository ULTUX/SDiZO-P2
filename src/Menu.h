//
// Created by Wladyslaw Nowak on 17.04.2021.
//

#ifndef SDIZO2_MENU_H
#define SDIZO2_MENU_H

#include <string>
#include "GraphRepresentations/ListRepresentation.h"
#include "GraphRepresentations/MatrixRepresentation.h"

using namespace std;

class Menu {
private:
    /**
     * Graph list representation read from file.
     */
    ListRepresentation* listRep = nullptr;

    /**
     * Graph matrix representation read from file.
     */
    MatrixRepresentation* matrixRep = nullptr;

    /**
     * Print main menu.
     */
    void printMainMenu();

    /**
     * Prompt user with message to input integer value and return it.
     * @param message Message to be displayed.
     * @param mustPositive If it is required for the value to be positive.
     * @return Value inputted by user.
     */
    static int getIntegerInput(string message, bool mustPositive = false);

    /**
     * Prompt user with message to input float value and return it.
     * @param message Message to be displayed.
     * @param mustPositive If it is required for the value to be positive.
     * @return Value inputted by user.
     */
    static float getFloatInput(string message, bool mustPositive = false);

    /**
     * Nicely print thrown exception on stdout.
     * @param e Exception to be printed.
     */
    static void printException(exception &e);

public:
    Menu();

    void printReadFromFileMenu();

    void printGraph();

    void kruskal();

    void dijsktra();

    void bellmanFord();

    void fordFulkderson();

    void prima();
};


#endif //SDIZO2_MENU_H