//
//  clase .h
//  reto 1 - Final
//
//  Created by Jorge Becker y Gabriel Dichi on 9/23/20.
//

#ifndef clase__h
#define clase__h
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Linea
{
public:
    string date, hour, ip, server,ip2,web,ids, ids2;
    Linea(string date1,string hour1,string ip1,string server1,string ip3,string web1,string ids1,string ids3){
        date=date1;
        hour=hour1;
        ip=ip1;
        server=server1;
        ip2=ip3;
        web=web1;
        ids=ids1;
        ids2=ids3;
    };
    ~Linea(){};
           
    
    
    
};
#endif /* clase__h */
