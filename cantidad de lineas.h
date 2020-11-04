//
//  cantidad de lineas.h
//  reto 1 - Final
//
//  Created by Jorge Becker on 9/23/20.
//

#ifndef cantidad_de_lineas_h
#define cantidad_de_lineas_h
using namespace std;

int numero_de_entradas = 0;
void conteo_entradas(){

    string linea;
    ifstream archivo("equipo4.csv");
    

    
    if(archivo.is_open()){
        while(!archivo.eof()){
            getline(archivo,linea);
            //cout<< linea << endl;
            numero_de_entradas++;
            
            
        }
        
        numero_de_entradas-=1;
        cout<<"Cantidad de entradas en archivo csv: " << numero_de_entradas << endl;
        archivo.close();
}
}

#endif /* cantidad_de_lineas_h */

