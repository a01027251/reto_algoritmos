#include <vector>
#include <map>
#include <fstream>
#include "clase .h"

using namespace std;

template <class T>
#pragma once
class DataBase
{
public:
    vector<T> All_Registrations;

    DataBase(string file_name, char punctation_mark)
    {
        ifstream MyFile;
        MyFile.open(file_name);

        string date, time, ip, port, hostname, ip2, port2, hostname2;

        // Counter for printing the Registrations if enabeled
        // int i = 0;
        while (!MyFile.eof())
        {
            getline(MyFile, date, punctation_mark);
            getline(MyFile, time, punctation_mark);
            getline(MyFile, ip, punctation_mark);
            getline(MyFile, port, punctation_mark);
            getline(MyFile, hostname, punctation_mark);
            getline(MyFile, ip2, punctation_mark);
            getline(MyFile, port2, punctation_mark);
            getline(MyFile, hostname2, '\n');

            All_Registrations.push_back(Linea(date, time, ip, hostname, ip2, hostname2, port, port2));

            // The code below prints all the registrations

            // cout << "Resgistration number " << i << " == ";
            // All_Registrations.at(i).print();
            // i++;
        }
        MyFile.close();
    }

    map<string, int> conexionesPorDia(string fecha)
    {
        map<string, int> conteoFecha;
        for (size_t i = 0; i < All_Registrations.size(); i++)

        {
            if (All_Registrations[i].date > fecha)
            {
                break;
            }

            else if (All_Registrations[i].date == fecha)
            {
                string host = All_Registrations[i].web;
                size_t host_last = host.find_first_of(".\\");
                string dominio = host.substr(host_last + 1, host.length() - 1);
                if (conteoFecha.find(host) == conteoFecha.end() && dominio != "reto.com" && host != "-")
                {

                    conteoFecha.insert(pair<string, int>(host, 1));
                }
                else if (conteoFecha.find(host) != conteoFecha.end())
                {

                    conteoFecha[host]++;
                }
            }
        }

        return conteoFecha;
    }
    ~DataBase(){};
};