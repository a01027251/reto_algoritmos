#include "DataBase.h"
#include "conexion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include "bst.h"
using namespace std;

int main()
{
    vector<string> dominios;
    set<string> not_reto;
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

        size_t host_last = host2.find_first_of(".\\"); //devuelve el indice del ultimo punto de un ip
        string dominio = host2.substr(host_last + 1, host2.length() - 1);
        if (dominio != "reto.com")
        {
            not_reto.insert(host2);
        }

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

        if (diccionario.find(host) == diccionario.end() && ip != "-")
        {
            ConexionesComputadora conexion(ip, host, registros.All_Registrations);
            diccionario.insert(pair<string, ConexionesComputadora>(host, conexion));
            // cout << ip << endl;
        }
        if (diccionario.find(host2) == diccionario.end() && ip2 != "-")
        {
            ConexionesComputadora conexion(ip2, host2, registros.All_Registrations);
            diccionario.insert(pair<string, ConexionesComputadora>(host2, conexion));
            // cout << ip << endl;
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
        stack<Linea> *stack_1(it->second.get_conexiones_entrantes());
        size_t host_last = it->first.find_first_of(".\\");
        string dominio = it->first.substr(host_last + 1, it->first.length() - 1);
        // cout << dominio << " " << it->second.get_conexiones_entrantes().size() << endl;
        if (dominio == "reto.com" && stack_1->size() > 0)
        {
            contador++;
        }
    }

    cout << "De las computadoras pertenecientes al dominio reto.com determina la cantidad de ips que tienen al menos una conexión entrante. " << endl;
    cout << "Cantidad de computadoras: " << contador << endl;
    cout << endl;

    cout << "PREGUNTA 4" << endl
         << "Toma algunas computadoras que no sean server.reto.com o el servidor dhcp. Pueden ser entre 5 y 150. Obtén las ip únicas de las conexiones entrantes." << endl;
    set<string> ip_unique;
    for (map<string, ConexionesComputadora>::iterator it = diccionario.begin(); it != diccionario.end(); ++it)
    {
        stack<Linea> *stack_2(it->second.get_conexiones_entrantes());
        // cout << it->first << endl;
        //cout<<it->second.get_ip()<<endl;
        while (!stack_2->empty())
        {
            Linea gol = stack_2->top();
            if (gol.server != "server.reto.com" && gol.ids != "68")
            {
                ip_unique.insert(gol.ip);
            }

            stack_2->pop();
        }
    }
    cout << "ips unicas: " << endl;
    for (auto ford_fiesta : ip_unique)
    {
        cout << ford_fiesta << endl;
    }
    cout << "Total = " << ip_unique.size() << endl;
    cout << endl;

    cout << "PREGUNTA 5" << endl;
    cout << "Despues de realizar las preguntas 3 y 4 podemos determinar que" << endl
         << "todas las computadoras pertenecientes al dominio reto.com con conexion entrante no son server.reto.com ya que el total de estas 2 es el mismo" << endl;

    cout << endl;
    cout << "PREGUNTA 6" << endl;
    cout << "Para las ips encontradas en el paso anterior, determina si se han comunicado con los datos encontrados en la pregunta 1." << endl;

    for (size_t i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        bool encontrar = false;
        string ip2 = registros.All_Registrations[i].ip2;

        while (ip2 != ip_dominios[0] || ip2 != ip_dominios[1])
        {
            cout << "Si se han comunicado con los servidores anomalos" << endl;
            encontrar = true;
            break;
        }
        if (encontrar == true)
        {
            break;
        }
    }
     cout << endl;
    cout << "PREGUNTA 7" << endl;
    cout<<" En caso de que hayas encontrado que las computadoras del paso 1 y 4 se comunican, determina en qué fecha ocurre la primera comunicación entre estas 2 y qué protocolo se usó."<<endl;
    
    for (size_t i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        bool encontrar = false;
        string ip2 = registros.All_Registrations[i].ip2;

        while (ip2 != ip_dominios[0] || ip2 != ip_dominios[1])
        {
            cout<< "la fecha es : "<<registros.All_Registrations[i].date<<endl;
            encontrar = true;
            break;
        }
        if (encontrar == true)
        {
            break;
        }
    }

}
