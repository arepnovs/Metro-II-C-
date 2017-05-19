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
    string name;
    vector <string> connections;

} t_stations;

void find_way(vector<t_stations> stations);

#endif //METRO_C_METRO_H
