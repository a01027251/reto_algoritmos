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
    DataBase<Linea> registros("nuevo4.csv", ',');
    map<string, ConexionesComputadora> diccionario;
    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string ip = registros.All_Registrations[i].ip;
        string host = registros.All_Registrations[i].server;
        size_t host_last = host.find_first_of(".\\"); //devuelve el indice del ultimo punto de un ip
        string dominio = host.substr(host_last + 1, host.length() - 1);
        if (dominio != "reto.com")
        {
            dominios.push_back(host);
            cout << host << endl;
            ip_dominios.push_back(ip);
            cout << ip << endl;
        }

        if (diccionario.find(ip) == diccionario.end())
        {
            ConexionesComputadora conexion(ip, host, registros.All_Registrations);
            diccionario.insert(pair<string, ConexionesComputadora>(ip, conexion));
            // cout << ip << endl;
        }
    }
    cout << endl;
    cout << "PREGUNTA 1" << endl;
    cout << "¿Hay algún nombre de dominio que sea anómalo?" << endl;
    cout << "la cantidad de anomalos es: " << dominios.size() << endl
         << endl;

    cout << "PREGUNTA 2" << endl;
    // cout << "Tamaño del diccionario: " << diccionario.size() << endl;
    cout << "De los nombres de dominio encontrados en el paso anterior, ¿cuál es su ip? ¿Cómo determinarías esta información de la manera más eficiente en complejidad temporal?" << endl;
    cout << "Los ip de los servers anomalos son: " << endl;

    for (int i = 0; i < ip_dominios.size(); i++)
    {
        cout << ip_dominios[i] << endl;
    }
    cout << "Nosotros pensamos que esta es la forma mas eficiente ya que es de complejidad O(n), podemos observar que solamente utilizamos un for loop" << endl;
    cout << endl;

    cout << "PREGUNTA 3" << endl;
    int contador = 0;
    for (map<string, ConexionesComputadora>::iterator it = diccionario.begin(); it != diccionario.end(); ++it)
    {
        if (it->second.get_conexiones_entrantes().size() > 0)
        {
            contador++;
        }
    }
    cout << "De las computadoras pertenecientes al dominio reto.com determina la cantidad de ips que tienen al menos una conexión entrante. " << endl;
    cout << "Cantidad de computadoras: " << contador << endl;
    cout << endl;
}
