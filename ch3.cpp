#include "DataBase.h"
#include "conexion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<string> dominios;
    vector<string> ip_dominios;
    vector<string> anomalos;
    DataBase<Linea> registros("nuevo4.csv", ',');
    map<string, ConexionesComputadora> diccionario;
    int counter = 0;
    int counter2 = 0;
    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        string ip2 = registros.All_Registrations[i].ip2;
        string host = registros.All_Registrations[i].server;
        string host2 = registros.All_Registrations[i].web;

        if (counter != 1)
        {
            if (host2 == "3cgmaxmmtuo1ib6fr3fx.xxx")
            {
                dominios.push_back(host2);
                ip_dominios.push_back(ip2);
                counter++;
            }
        }

        if (counter2 != 1)
        {
            if (host2 == "m86b47mnakl1ggo1y17a.xxx")
            {
                dominios.push_back(host2);
                ip_dominios.push_back(ip2);
                counter2++;
            }
        }

        if (diccionario.find(host) == diccionario.end())
        {
            ConexionesComputadora conexion(ip, host, registros.All_Registrations);
            diccionario.insert(pair<string, ConexionesComputadora>(host, conexion));
            cout << ip << endl;
        }
        if (diccionario.find(host2) == diccionario.end())
        {
            ConexionesComputadora conexion(ip2, host2, registros.All_Registrations);
            diccionario.insert(pair<string, ConexionesComputadora>(host2, conexion));
            cout << ip << endl;
        }
    }

    cout << endl;
    anomalos.push_back("3cgmaxmmtuo1ib6fr3fx.xxx");
    anomalos.push_back("m86b47mnakl1ggo1y17a.xxx");

    cout << "PREGUNTA 1" << endl;
    cout << "¿Hay algún nombre de dominio que sea anómalo?" << endl;
    cout << "Estos son los anomalos" << endl;
    for (size_t i = 0; i < anomalos.size(); i++)
    {
        cout << anomalos[i] << endl;
    }

    cout << endl
         << "PREGUNTA 2" << endl;

    // cout << "Tamaño del diccionario: " << diccionario.size() << endl;
    cout << "De los nombres de dominio encontrados en el paso anterior, ¿cuál es su ip? ¿Cómo determinarías esta información de la manera más eficiente en complejidad temporal?" << endl;
    cout << "Los ip de los servers anomalos son: " << endl;

    for (size_t i = 0; i < ip_dominios.size(); i++)
    {
        cout << dominios[i] << " : " << ip_dominios[i] << endl;
    }
    cout << endl;
    cout << "Nosotros pensamos que esta es la forma mas eficiente ya que es de complejidad O(n), podemos observar que solamente utilizamos un for loop" << endl;
    cout << endl;

    cout << "PREGUNTA 3" << endl;
    int contador = 0;
    for (map<string, ConexionesComputadora>::iterator it = diccionario.begin(); it != diccionario.end(); ++it)
    {
        size_t host_last = it->first.find_first_of(".\\"); //devuelve el indice del ultimo punto de un ip
        string dominio = it->first.substr(host_last + 1, it->first.length() - 1);
        cout << dominio << " " << it->second.get_conexiones_entrantes().size() << endl;
        if (dominio == "reto.com" && it->second.get_conexiones_entrantes().size() < 100)
        {

            contador++;
        }
    }

    cout << "De las computadoras pertenecientes al dominio reto.com determina la cantidad de ips que tienen al menos una conexión entrante. " << endl;
    cout << "Cantidad de computadoras: " << contador << endl;
    cout << endl;
    cout << endl;
}
