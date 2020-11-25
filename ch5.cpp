
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
    Graph<string> graphFechas;
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

    for (auto it : setFecha)
    {
        graphFechas.add_node(it);
        cout << it << "-----" << cont << endl;
        cont++;
    }

    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        ipEntrante.insert(ip);
    }
    ipEntrante.erase("-");

    for (auto it : ipEntrante)
    {
        graphFechas.add_node(it);
        cout << it << "-----" << cont << endl;
        cont++;
    }

    int k = 0;
    while (registros.All_Registrations[k].ip == "-") //recorre el archivo hasta llegar a un ip existente
    {
        k++;
    }

    string ipc = registros.All_Registrations[k].ip;
    int ultimo_punto = ipc.find_last_of(".\\");
    string ipj = ipc.substr(0,ultimo_punto + 1);

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
        string ipt = ipc.substr( 0 ,ultimo + 1);
        
        //cout << i << endl;

        if (a != b)
        {
            for (auto partes : setFechaIntermitente)
            {

                vectror_grafos[c].add_node(partes);
                cout << partes << "--" << c << endl;
            }

            set<string> setFechaIntermitente;
            cout << a << "--" << b << "--" << c << endl;
            c++;
        }
        setFechaIntermitente.insert(ip);
      

        if (ipj == ipt)
        {
            
            setFechaIntermitente.insert(ip2);
             cout<< ipj<< "--"<<ipt<<endl;

        }
        
        
    }

}
