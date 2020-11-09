

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
    set<string> fechas;

    for (int i = 0; i < registros.All_Registrations.size() - 1; i++)
    {
        string fecha = registros.All_Registrations[i].date;
        fechas.insert(fecha);
    }

    for (auto dates : fechas)
    {
        registros.top(5, dates);
    }

    cout << "¿Existe algún sitio que se mantenga en el top 5 en todos los días?" << endl;
    cout << "si freemailserver.com" << endl
         << endl;

    cout << " ¿Existe algún sitio que entre al top 5 a partir de un día y de ahí aparezca en todos los días subsecuentes?" << endl;
    cout << "si 3cgmaxmmtuo1ib6fr3fx.xxx en el dia 14-8-2020 " << endl
         << endl;

    cout << " ¿Existe algún sitio que aparezca en el top 5 con una cantidad más alta de tráfico que lo normal?" << endl;
    cout << "si freemailserver.com con siempre mas de 1200 de conexiones al dia tambien 3cgmaxmmtuo1ib6fr3fx.xxx con mas de 200 conexines al dia cuando las demas tienen menos de 25 (que seria lo normal)  " << endl
         << endl;
}