
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cantidad de lineas.h"
#include "clase .h"
#include "DataBase.h"
#include <map>
#include "graph_searcher.h"
#include <algorithm>

using namespace std;

int main()
{

    DataBase<Linea> registros("nuevo4.csv", ',');
    set<string> ipEntrante;
    set<string> setFecha;
    set<string> setFechaIntermitente;
    vector<Graph<string>> vectror_grafos(10);

    int cont = 0;

    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string fecha = registros.All_Registrations[i].date;
        setFecha.insert(fecha);
    }

    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        ipEntrante.insert(ip);
    }
    ipEntrante.erase("-");

    int k = 0;
    while (registros.All_Registrations[k].ip == "-") //recorre el archivo hasta llegar a un ip existente
    {
        k++;
    }

    string ipc = registros.All_Registrations[k].ip;
    int ultimo_punto = ipc.find_last_of(".\\");
    string ipj = ipc.substr(0, ultimo_punto + 1);

    int c = 0;
    for (int i = 1; i < registros.All_Registrations.size() - 1; i++)
    {

        string fecha = registros.All_Registrations[i].date;
        string a = fecha;
        string b = registros.All_Registrations[i - 1].date;
        string ip = registros.All_Registrations[i].ip;
        string ip2 = registros.All_Registrations[i].ip2;

        string ipk = registros.All_Registrations[i].ip2;
        int ultimo = ipk.find_last_of(".\\");
        string ipt = ipk.substr(0, ultimo + 1);
        //cout << i << endl;

        if (a != b)
        {
            setFechaIntermitente.clear();
            c++;
        }
        if (setFechaIntermitente.find(ip) == setFechaIntermitente.end())
        {
            vectror_grafos[c].add_node(ip);
            setFechaIntermitente.insert(ip);
        }

        if (ipj == ipt)
        {
            if (setFechaIntermitente.find(ip) == setFechaIntermitente.end())
            {
                vectror_grafos[c].add_node(ip2);
                setFechaIntermitente.insert(ip2);
            }
            vectror_grafos[c].add_edge_generic(ip, ip2);
        }
    }
    for (size_t i = 0; i < vectror_grafos.size(); i++)
    {
        cout << "lenght: " << vectror_grafos[i].get_nodes().size() << endl;
        cout << endl;

        vectror_grafos[i].print_edge();
    }

    cout<<"¿Es A el vértice que más conexiones salientes hacia la red interna tiene?";




























}



