
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cantidad de lineas.h"
#include "clase .h"
#include "DataBase.h"
#include "graph copy.h"
#include <map>

using namespace std;
int main()
{

    DataBase<Linea> registros("nuevo4.csv", ',');
    Graph<T> graphA;
    set<string> ipEntrante;

    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        ipEntrante.insert(ip);
    }
    ipEntrante.erase("-");

    for (int i = 0; i < ipEntrante.size(); i++)
    {
        graphA.add_node(ipEntrante);
    }
}
