#include "metro.h"

vector<string>      str_split_in_vect(string str, string delim, vector<string> splits)
{
    size_t pos;
    string stop;

    while ((pos = str.find(delim)) != string::npos)
    {
        stop = str.substr(0, pos);
        splits.push_back(stop);
        str.erase(0, pos + delim.length());
    }
    return(splits);
}

vector<t_stations>    stations_info(string line, int l, vector <t_stations> stations)
{
    size_t i;
    int j = 0;
    size_t size;
    vector<string> all;

    i = stations.size();
    all = str_split_in_vect(line, "-", all);
    size = all.size() + i;
    while (i < size)
    {
        stations.push_back(s_stations());
        stations[i].name = all[j];
        stations[i].line = l;
        if ((i > size - all.size()))
            stations[i].connections.push_back(all[j - 1]);
        if (i < size - 1)
            stations[i].connections.push_back(all[j + 1]);
        i++;
        j++;
    }
    return(stations);
}

vector<t_stations>    add_connections(vector<t_stations> stations, string str)
{
    int i = 0;
    size_t pos;
    string stop;
    string delim = "-";
    string conn[2];

    while ((pos = str.find(delim)) != string::npos)
    {
        stop = str.substr(0, pos);
        conn[i] = stop;
        str.erase(0, pos + delim.length());
        i++;
    }
    i = 0;
    while (i < stations.size())
    {
        if (stations[i].name.compare(conn[0]) == 0)
            stations[i].connections.push_back(conn[1]);
        else if (stations[i].name.compare(conn[1]) == 0)
            stations[i].connections.push_back(conn[0]);
        i++;
    }
    return(stations);
}

string  what_map(char **av)
{
    if (strcmp(av[1], "kyiv") == 0)
        return("../kyiv.txt");
    else
        return(0);
}

int main(int ac, char **av) {

    string str;
    string res;
    string map;
    if (ac == 2)
        map = what_map(av);
    else
        cout << "Choose city" << endl;
    int line = 1;
    vector <t_stations> stations;
    //ifstream file("../kyiv.txt");
    ifstream file(map);
    if (file.is_open())
    {
        while (getline(file, str))
        {
            if (str.find("#line") != -1)
            {
                getline(file, str);
                stations = stations_info(str, line, stations);
            }
            else if (str.find("#connect") != -1)
            {
                while (getline(file, str))
                    stations = add_connections(stations, str);
            }
            else
                cout << "Some error in map" << endl;
            line++;
        }
        file.close();
    }
    else
        cout << "Error" << endl;
    find_way(stations);
    return 0;
}
