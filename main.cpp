#include "metro.h"

vector<string>      str_split_in_vect(string str, string delim, vector<string> splits)
{
    size_t pos;
    string stop;

    while ((pos = str.find(delim)) != string::npos) {
        stop = str.substr(0, pos);
        splits.push_back(stop);
        str.erase(0, pos + delim.length());
    }
    return(splits);
}

vector<t_stations>    stations_info(string line, int l, vector <t_stations> stations)
{
    int i = 0;
    vector<string> all;

    all = str_split_in_vect(line, "-", all);
    while (i < all.size())
    {
        stations.push_back(s_stations());
        stations[i].name = all[i];
        stations[i].line = l;
        if (i > 0)
            stations[i].connections.push_back(all[i - 1]);
        if (i < all.size() - 1)
            stations[i].connections.push_back(all[i + 1]);
        i++;
    }
    return(stations);
}

int main() {

    string str;
    string res;
    int line = 1;
    vector <t_stations> stations;
    vector <string> all_stations;
    ifstream file("../kyiv.txt");
    if (file.is_open())
    {
        while (getline(file, str))
        {
            if (str.find("#line") != -1)
            {
                getline(file, str);
                stations = stations_info(str, line, stations);
                all_stations = str_split_in_vect(str, "-", all_stations);
                line++;
            }
            else if (str.find("#connect") != -1)
            {
                while (getline(file, str))
                {
                    res = res + '|' + str;
                }
                cout << "#connect " << res << endl;
            }
            else
                cout << "Some input error" << endl;
            line++;

        }
        file.close();
    }
    else
        cout << "Shiiiit" << endl;
    return 0;
}