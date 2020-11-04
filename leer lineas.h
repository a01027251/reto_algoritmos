//
//  leer lineas.h
//  reto 1 - Final
//
//  Created by Jorge Becker on 9/23/20.
//

#ifndef leer_lineas_h
#define leer_lineas_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void leer_lineas(){
    
    
    
    ifstream archivo("nuevo4.csv");
    

    
    string date, hour, ip, server,ip2,web,id, id2;
    int dats;
    
    string myString;
    string line;
    
    while (getline(archivo,line)) {
        stringstream ss(line);
        getline(ss, date, ',');
        date=date.substr(0,2)+date.substr(3,1)+date.substr(5,4);
        dats=stoi(date);
        getline(ss, hour, ',');
        getline(ss, ip, ',');
        getline(ss, id, ',');
        getline(ss, server, ',');
        getline(ss, ip2, ',');
        getline(ss, id2, ',');
        getline(ss, web, ',');
        cout<<dats<<endl;
        
        }
        

    archivo.close();
}


#endif /* leer_lineas_h */
