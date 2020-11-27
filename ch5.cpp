
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
            if (setFechaIntermitente.find(ip2) == setFechaIntermitente.end())
            {
                vectror_grafos[c].add_node(ip2);
                setFechaIntermitente.insert(ip2);
            }
            vectror_grafos[c].add_edge_generic(ip, ip2);
        }
    }
    int dia = 1;
    string ip_seleccion;
    cout << "Selecciona la ip a buscar" << endl;
     cin >> ip_seleccion;

    for (size_t i = 0; i < vectror_grafos.size(); i++)
    {

        cout << "dia # " << dia << endl;
        //cout << "lenght: " << vectror_grafos[i].get_nodes().size() << endl;

        //vectror_grafos[i].print_edge();
        vectror_grafos[i].print_conteo(ip_seleccion);

        dia++;

        vectror_grafos[i].conteo_inversa(ip_seleccion);
        cout << endl;
    }

    //                   PREGUNTAS 3 Y 4
    cout << endl;
    cout << endl;
    cout << "PREGUNTAS 3 Y 4" << endl;
    cout << endl;
    vector<Graph<string>> vectror_grafos2(10);
    set<string> setFechaIntermitente2;
    c = 0;
    for (int i = 1; i < registros.All_Registrations.size() - 1; i++)
    {
        string port = registros.All_Registrations[i].ids2;
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

        if (port == "443")
        {
            if (setFechaIntermitente.find(ip2) == setFechaIntermitente.end())
            {
                vectror_grafos[c].add_node(ip2);
                setFechaIntermitente.insert(ip2);
            }
            vectror_grafos[c].add_edge_generic(ip, ip2);
        }
    }

    int dia2 = 1;
    string ip_anomalo = "190.135.246.47";
    string ip_conexion_anomala = "13.27.150.7";

    for (size_t i = 0; i < vectror_grafos.size(); i++)
    {

        cout << "dia # " << dia2 << endl;
        //cout << "lenght: " << vectror_grafos[i].get_nodes().size() << endl;

        //vectror_grafos[i].print_edge();
        //vectror_grafos[i].print_conteo(ip_anomalo);

        dia2++;

        vectror_grafos[i].conteo_inversa(ip_anomalo);
        vectror_grafos[i].conteo_inversa(ip_conexion_anomala);

        
        cout << endl;
    }
}
