

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
    DataBase<Linea> registros("nuevo4.csv", ',');
    map<string,int> hola = registros.conexionesPorDia("10-8-2020");
    for (auto dichi : hola)
    {
        cout << dichi.first<<" : "<<dichi.second<<endl;
    }
    
}