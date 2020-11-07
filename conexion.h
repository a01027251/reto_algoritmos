#include <stack>
#include <queue>
#include <iostream>
#include "clase .h"

using namespace std;

class ConexionesComputadora
{
private:
    string ip;
    string nombre;
    stack<Linea> conexiones_entrantes;
    queue<Linea> conexiones_salientes;

public:
    /*aqui usamos gets para poder acceder a los atributos privados*/
    stack<Linea>* get_conexiones_entrantes() { return &conexiones_entrantes; }
    queue<Linea>* get_conexiones_salientes() { return &conexiones_salientes; }
    string get_ip() {return ip;}

    ConexionesComputadora(string ip2, string nombre2, vector<Linea> archivo)
    {
        ip = ip2;
        nombre = nombre2;

        for (int i = 0; i < archivo.size() - 1; i++)
        {
            //stack
            if (archivo[i].ip2 == ip)
            {
                conexiones_salientes.push(archivo[i]);
            }

            //queue
            if (archivo[i].ip == ip)
            {
                conexiones_entrantes.push(archivo[i]);
            }
        }
    };

    ~ConexionesComputadora(){};
};
