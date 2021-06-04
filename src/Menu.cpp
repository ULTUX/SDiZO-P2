//
// Created by Wladyslaw Nowak on 17.04.2021.
//

#include "./Menu.h"
#include "IO/FileReader.h"
#include <windows.h>
Menu::Menu() {
    printMainMenu();
}

void Menu::printMainMenu() {
    while (matrixRep == nullptr && listRep == nullptr) {
        printReadFromFileMenu();
    }
    while (true) {
        cout << "Wybierz polecenie: " << endl;
        cout << "\t1. Wczytaj graf z pliku" << endl;
        cout << "\t2. Wyswietl graf" << endl;
        cout << "\t3. Algorytm Kruskala" << endl;
        cout << "\t4. Algorytm Prima" << endl;
        cout << "\t5. Algorytm Dijsktry" << endl;
        cout << "\t6. Algorytm Bellmana-Forda" << endl;
        cout << "\t7. Algorytm Forda-Fulkersona" << endl;
        cout << "\t0. Wylacz program" << endl;
        int input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                printReadFromFileMenu();
                break;
            }
            case 2: {
                printGraph();
                break;
            }
            case 3: {
                kruskal();
                break;
            }
            case 4: {
                prima();
                break;
            }
            case 5: {
                dijsktra();
                break;
            }
            case 6: {
                bellmanFord();
                break;
            }
            case 7: {
                fordFulkderson();
                break;
            }
            case 0: {
                cout << "Wylaczanie programu..." << endl;
                exit(0);
            }
            default: {
                cout << "Nieznana komenda" << endl;
                break;

            }
        }
    }
}

int Menu::getIntegerInput(string message, bool mustPositive) {
    bool isNum = false;
    bool isPositive = false;
    int val;
    while (!isNum) {
        cout << message;
        string input;
        cin.clear();
        cin.sync();
        getline(cin, input);
        try {
            val = stoi(input);
            if (val > 0) isPositive = true;
            if (!mustPositive) isNum = true;
            else if (isPositive) isNum = true;
            else isNum = false;
        } catch (invalid_argument &e) {
            cout << "Wprowadzone dane nie sa liczba!" << endl;
            continue;
        }
        catch (out_of_range &e) {
            cout << "Wprowadzona liczba jest za duza!" << endl;
            continue;
        }
    }
    return val;
}

float Menu::getFloatInput(string message, bool mustPositive) {
    bool isNum = false;
    bool isPositive = false;
    float val;
    while (!isNum) {
        cout << message;
        string input;
        cin.clear();
        cin.sync();
        getline(cin, input);
        try {
            val = stof(input);
            if (val > 0) isPositive = true;
            if (!mustPositive) isNum = true;
            else if (isPositive) isNum = true;
            else isNum = false;
        } catch (invalid_argument &e) {
            cout << "Wprowadzone dane nie sa liczba!" << endl;
            continue;
        }
        catch (out_of_range &e) {
            cout << "Wprowadzona liczba jest za duza!" << endl;
            continue;
        }
    }
    return val;
}

void Menu::printException(exception &e) {
    cout << "-------------------------------\n";
    cout << endl << endl << "UWAGA: Wystapil blad: ";
    cerr << e.what() << "\n\n\n";
    cout << "-------------------------------\n";
}

void Menu::printReadFromFileMenu() {
    string fileName;
    cout<<"Prosze podac nazwe pliku: ";
    cin>>fileName;
    cout<<"Wczytywanie danych z pliku..."<<endl;
    try {
        FileReader reader(fileName);
        listRep = new ListRepresentation(0, 0, 0, 0, true);
        reader.readToAdjList(listRep);

        FileReader reader2(fileName);
        matrixRep = new MatrixRepresentation(0, 0, 0, 0, true);
        reader2.readToAdjMatrix(matrixRep);
    } catch (runtime_error& e){
        printException(e);
        Sleep(200);
        return;
    }

    cout<<"Dane wczytane pomyslnie."<<endl;
    printGraph();
}

void Menu::printGraph() {
    cout<<"Representacja macierzowa: "<<endl;
    matrixRep->print();
    cout<<"Reprezentacja listowa: "<<endl;
    listRep->print();
}

void Menu::kruskal() {
    cout<<endl<<endl;
    cout<<"Reprezentacja listowa: "<<endl;
    KruskalList klist(0, 0);
    klist.clone(listRep);
    klist.start();

    cout<<endl<<endl<<"Reprezentacja macierzowa: "<<endl;
    KruskalMatrix kmatrix(0, 0);
    kmatrix.clone(matrixRep);
    kmatrix.start();
    cout<<endl<<endl;
}

void Menu::dijsktra() {
    cout<<endl<<endl;
    cout<<"Reprezentacja listowa: "<<endl;
    DijsktraList dlist(0,0, 0);
    dlist.clone(listRep);
    if (dlist.hasNegativeWeights()) cout<<"UWAGA: Ten graf posiada ujemne krawedzie, algorytm djikstry może nie dzialac poprawnie"<<endl;
    dlist.start();

    cout<<endl<<endl<<"Reprezentacja macierzowa: "<<endl;
    DijsktraMatrix dmatrix(0, 0, 0);
    dmatrix.clone(matrixRep);
    if (dmatrix.hasNegativeWeights()) cout<<"UWAGA: Ten graf posiada ujemne krawedzie, algorytm djikstry może nie dzialac poprawnie"<<endl;
    dmatrix.start();
    cout<<endl<<endl;

}

void Menu::bellmanFord() {
    cout<<endl<<endl;
    cout<<"Reprezentacja listowa: "<<endl;
    BellmanFordList bflist(0,0, 0);
    bflist.clone(listRep);
    bflist.start();

    cout<<endl<<endl<<"Reprezentacja macierzowa: "<<endl;
    BellmanFordMatrix bfmatrix(0, 0, 0);
    bfmatrix.clone(matrixRep);
    bfmatrix.start();
    cout<<endl<<endl;
}

void Menu::fordFulkderson() {
    cout<<endl<<endl;
    cout<<"Reprezentacja listowa: "<<endl;
    FordFulkersonList fflist(0, 0, 0, 0);
    fflist.clone(listRep);
    fflist.start();

    cout<<endl<<endl<<"Reprezentacja macierzowa: "<<endl;
    FordFulkersonMatrix ffmatrix(0, 0, 0, 0);
    ffmatrix.clone(matrixRep);
    ffmatrix.start();
    cout<<endl<<endl;
}

void Menu::prima() {
    cout<<endl<<endl;
    cout<<"Reprezentacja listowa: "<<endl;
    PrimsList plist(0, 0);
    plist.clone(listRep);
    plist.start();

    cout<<endl<<endl<<"Reprezentacja macierzowa: "<<endl;
    PrimsMatrix pmatrix(0, 0);
    pmatrix.clone(matrixRep);
    pmatrix.start();
    cout<<endl<<endl;
}
