//
// Created by Anton Repnovskyi on 5/18/17.
//

#ifndef METRO_C_METRO_H
#define METRO_C_METRO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef struct s_stations
{
    int line;
    int pos;
    string name;
    vector <string> connections;

} t_stations;

/*typedef struct s_path
{
    int line;
    int pos;
    string name;
    vector <string> connections;

} t_path;*/

#endif //METRO_C_METRO_H
