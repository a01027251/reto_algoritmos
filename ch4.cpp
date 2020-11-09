

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cantidad de lineas.h"
#include "clase .h"
#include "DataBase.h"
#include <map>

using namespace std;
int seleccion = 10;
int counts = 0;

int main()
{

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
            getline(archivo, web, '\n');
            Linea o1(date, hour, ip, server, ip2, web, ids, ids2);
            archivo2.push_back(o1);
            cout << web << endl;
        }
    }

//     map<string, int> conteoFecha;
//     DataBase<Linea> registros("nuevo4.csv", ',');
//     string fecha;
//     int contador = 0;
//     int conexionesPorDia(string fecha)
//     {
//         if (conteoFecha.find(fecha) == conteoFecha.end())
//         {
//             conteoFecha conteo(web, contador, registros.All_Registrations);
//             conexionesPorDia.insert(pair<string, int>(web, contador));
//         }
//     }
// }
}