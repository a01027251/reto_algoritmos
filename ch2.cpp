/*
Jorge Becker    A01027251
Gabriel Dichi   A01027301
El reto de evidencias de aprendizaje #2 se relaciona con los temas vistos en clase de listas enlazadas, pilas y colas.
Trabajamos con el fichero presentado en clase y creamos un vector con las IP para encontrar las conexiones entrantes y salientes de un serviodor
Relizamos investigación para aprender el funcionamiento de nuevas funciones y poder hacer que este programa sea generico
*/
#include "conexion.h.icloud"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cantidad de lineas.h"
#include "clase .h"

using namespace std;

int main()
{
    //Acceder a cada columna del archivo
    string date, hour, ip, server, ip2, web, ids, ids2;
    string line;
    int numero_de_entradas = 0;
    ifstream archivo("nuevo4.csv");
    vector<Linea> archivo2;
    if (archivo.is_open())
    {
        while (!archivo.eof())
        {
            getline(archivo, date, ',');
            getline(archivo, hour, ',');
            getline(archivo, ip, ',');
            getline(archivo, ids, ',');
            getline(archivo, server, ',');
            getline(archivo, ip2, ',');
            getline(archivo, ids2, ',');
            getline(archivo, web, '
');
            Linea o1(date, hour, ip, server, ip2, web, ids, ids2);
            archivo2.push_back(o1);
        }
    }

    string ipt; // ip final
    string ipc; // ip completo (ya con el input)
    int num;
    cout << "que numero final de ip deseas de 0-150? " << endl;
    cin >> num;

    while (num <= 0 || num >= 150)
    {
        cout << "no pusiste un numero entre 0-150 intentelo de nuevo " << endl;
        cin >> num;
    }

    int i = 0;
    while (archivo2[i].ip == "-") //recorre el archivo hasta llegar a un ip existente
    {

        i++;
    }

    ipc = archivo2[i].ip;
    int ultimo_punto = ipc.find_last_of(".\\"); //devuelve el indice del ultimo punto de un ip

    ipt = ipc.substr(0, ultimo_punto + 1) + to_string(num);

    ConexionesComputadora o2(ipt, archivo2[i].server, archivo2);

    cout << "¿Qué dirección ip estas usando? " << endl
         << "el ip creado es: " << ipt << endl
         << endl;

    cout << "¿Cuál fue la ip de la última conexión que recibió esta computadora? ¿Es interna o externa? " << endl;
    cout << o2.get_conexiones_entrantes().top().ip; //top() agarra el primer valor en un stack
    if (ipc.substr(0, ultimo_punto + 1) == o2.get_conexiones_entrantes().top().ip.substr(0, ultimo_punto + 1))
    {
        cout << " es interna" << endl
             << endl;
    }
    else
    {
        cout << "es externa" << endl
             << endl;
    }

    cout << "¿Cuántas conexiones entrantes tiene esta computadora? " << endl
         << o2.get_conexiones_entrantes().size() << endl
         << endl;

    cout << "¿Cuántas conexiones salientes tiene esta computadora? " << endl
         << o2.get_conexiones_salientes().size() << endl
         << endl;

    string server_check;
    string server_check2;
    string server_check3;
    while (!o2.get_conexiones_salientes().empty())
    {
        server_check = o2.get_conexiones_salientes().front().server;
        o2.get_conexiones_salientes().pop();
        server_check2 = o2.get_conexiones_salientes().front().server;

        if (server_check == server_check2)
        {
            o2.get_conexiones_salientes().pop();
            server_check3 = o2.get_conexiones_salientes().front().server;

            if (server_check2 == server_check3)
            {
                cout << "¿Tiene esta computadora 3 conexiones seguidas a un mismo sitio web? " << endl
                     << "Si " << server_check3 << endl;

                break;
            }
        }
    }

    if (o2.get_conexiones_salientes().empty())
    {
        cout << "¿Tiene esta computadora 3 conexiones seguidas a un mismo sitio web? " << endl
             << "No " << endl;
    }

    return 0;
}
