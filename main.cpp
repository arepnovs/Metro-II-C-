#include "metro.h"

vector<t_stations>    stations_info(string line, int l)
{
    int i = 0;
    vector<string> all;
    vector <t_stations> stations;
    size_t pos;
    string stop;
    string delim = "-";

    while ((pos = line.find(delim)) != string::npos) {
        stop = line.substr(0, pos);
        all.push_back(stop);
        line.erase(0, pos + delim.length());
        i++;
    }
    i = 0;
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

vector<string>    get_stations(string line, vector<string> all)
{
    int i = 0;
    size_t pos;
    string stop;
    string delim = "-";

    while ((pos = line.find(delim)) != string::npos) {
        stop = line.substr(0, pos);
        all.push_back(stop);
        line.erase(0, pos + delim.length());
        i++;
    }
    return(all);
}

int main() {

    string str;
    string res;
    int line = 1;
    vector <t_stations> stations;
    vector <t_stations> temp;
    vector <string> all_stations;
    ifstream file("../kyiv.txt");
    if (file.is_open())
    {
        while (getline(file, str))
        {
            if (str.find("#line") != -1)
            {
                getline(file, str);
                temp = stations_info(str, line);
                stations.insert(stations.end(), temp.begin(), temp.end());
                all_stations = get_stations(str, all_stations);
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