//
//  main.cpp
//  reto 1 - Final
//
//  Created by Jorge Becker on 9/23/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cantidad de lineas.h"
#include "clase .h"

using namespace std;
int seleccion = 10;
int counts=0;

int main() {
    string date, hour, ip, server,ip2,web,ids, ids2;
    string line;
    int numero_de_entradas = 0;
    ifstream archivo("nuevo4.csv");
    vector<Linea> archivo2;
    if(archivo.is_open()){
        while(!archivo.eof()){
                   getline(archivo, date, ',');
                   getline(archivo, hour, ',');
                   getline(archivo, ip, ',');
                   getline(archivo, ids, ',');
                   getline(archivo, server, ',');
                   getline(archivo, ip2, ',');
                   getline(archivo, ids2, ',');
                   getline(archivo, web, '\n');
            Linea o1(date,hour,ip,server,ip2,web,ids,ids2);
            archivo2.push_back(o1);

        }
    }
    
    while (seleccion!=0) {
        cout<<"¿Que deseas hacer?"<<endl;
        cout<<"1) Obtener la cantidad de filas"<<endl;
        cout<<"2) Obtener la cantidad de registros del segundo día resistrado"<<endl;
        cout<<"3) ¿Qué computadora le pertenece a las personas específicas?"<<endl;
        cout<<"4) Direccion red interna de la compañia"<<endl;
        cout<<"5) ¿Alguna computadora se llama server.reto.com?"<<endl;
        cout<<"6) Que servicio de mail utilizan"<<endl;
        cout<<"0) SALIR"<<endl;
        cin>>seleccion;
        
        if (seleccion==1) {
            cout<<"Seleccion 1"<<endl;
            cout<<"La cantidad de entradas en el archivo son: "<<archivo2.size()-1<<endl;;
        }
        
        if (seleccion==2){
            cout<<"Seleccion 2"<<endl;
            int dats;
            string date2;
            int conte_de_fecha=0;
            date=archivo2[0].date;
            date2=date.substr(0,2);

            dats=stoi(date);
            dats++;
            date=to_string(dats)+date.substr(2);

            for (int i=0; i<archivo2.size()-1; i++) {
                if (archivo2[i].date==date) {
                    conte_de_fecha++;
                }

            }
            cout<<"La cantidad de entradas en el segundo día son: "<<conte_de_fecha<<endl;

        }
        
        if(seleccion==3){
            cout<<"Seleccion 3"<<endl;
            int conteo_nombres = 0;
            string servers;
            servers=archivo2[5].server;

            for (int i=0; i<archivo2.size()-1; i++) {
                if (archivo2[i].server==("jeffrey.reto.com")){
                    conteo_nombres++;
                }
                else if (archivo2[i].server==("betty.reto.com")){
                    conteo_nombres++;
                }
                
                else if (archivo2[i].server==("katherine.reto.com")){
                    conteo_nombres++;
                }
                else if (archivo2[i].server==("scott.reto.com")){
                    conteo_nombres++;
                }
                else if (archivo2[i].server==("samuel.reto.com")){
                    conteo_nombres++;
                }
                else if (archivo2[i].server==("raymond.reto.com")){
                    conteo_nombres++;
                }
                
            }
            if (conteo_nombres>0) {
                cout<<"Si hay computadoras que le pertenecen a alguna de las siguientes peprsonas, la cantidad es: "<<conteo_nombres<<endl;
            }
            else
                    cout<<"No se encontraron entradas con esos nombres "<<endl;
                    
            }

        if (seleccion==4) {
            cout<<"Seleccion 4"<<endl;

            string ips2;
            ip=archivo2[2].ip;

            ips2=ip.substr(0,3);
            cout<<"El numero de la compañia es: "<<ips2<<endl;


        }
        
        if (seleccion==5) {
            cout<<"Seleccion 5"<<endl;
            string servers;
            int contador_server = 0;
            servers=archivo2[5].server;

            for (int i=0; i<archivo2.size()-1; i++) {
                if (archivo2[i].server==("server.reto.com")){
                    contador_server++;
                }
            }
            if (contador_server > 0)
            {
                cout<<"Si hay una entrada que se llama server.reto.com"<<endl;
            }
            else
                cout<<"No se encontro una entrada que se llama server.reto.com"<<endl;
        }
        
        if (seleccion==6){
            cout<<"Selecion 6"<<endl;
            int conteo_gmail=0, conteo_hotmail=0, conteo_outlook=0, protonmail=0;
            string webs;
            webs=archivo2[5].web;
            for (int i=0; i<archivo2.size()-1; i++) {
                if (archivo2[i].web==("google.com")){
                    conteo_gmail++;
                }
                else if (archivo2[i].web==("freemailserver.com")){
                    conteo_hotmail++;
                }
                
                else if (archivo2[i].web==("bestbuy.com")){
                    conteo_outlook++;
                }
                else if (archivo2[i].web==("youtube.com")){
                    protonmail++;
                }
            
        }
            cout<<conteo_gmail<<" Usan Gmail"<<endl;
            cout<<conteo_hotmail<<" Usan Free mail server"<<endl;
            cout<<conteo_outlook<<" Usan bestbuy.com"<<endl;
            cout<<conteo_hotmail<<" Usan youtube.com"<<endl;

    }
        

}

}

