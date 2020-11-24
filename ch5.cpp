
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cantidad de lineas.h"
#include "clase .h"
#include "DataBase.h"
#include "graph.h"
#include <map>
#include "graph_searcher.h"
#include <algorithm>


using namespace std;


int main()
{
    
    DataBase<Linea> registros("nuevo4.csv", ',');
    Graph<string> graphA;
    set<string> ipEntrante;

    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        ipEntrante.insert(ip);
    }
    ipEntrante.erase("-");

    int c = 0;
    for (auto it : ipEntrante)
    {
        graphA.add_node(it);
        cout<<it<<"-----"<<c<<endl;
        c++;
        

    }

    
    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        string ip2 = registros.All_Registrations[i].ip2;

       graphA.add_edge(find(graphA.get_nodes().begin(), graphA.get_nodes().end(), ip), find(graphA.get_nodes().begin(), graphA.get_nodes().end(), ip2))
    }

   



}
