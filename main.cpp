#include "metro.h"

void    get_stations(string line, vector<t_stations> stations, vector<string> all)
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
    i = 0;
    while (i < 3)
    {
        stations.push_back(s_stations());
        stations[i].name = all[i];
        stations[i].pos = i;
        if (i > 0)
            stations[i].connections.push_back(all[i - 1]);
        if (i < 3)
            stations[i].connections.push_back(all[i + 1]);
        cout << all[i] << endl;
        i++;
    }
    cout << endl;
    i = 0;
    while (i < 3)
    {
        int j = 0;
        cout << stations[i].name <<endl;
        cout << stations[i].pos <<endl;
        while (j < 2)
        {
            cout << "++++" << endl << stations[i].connections[j] << endl;
            j++;
        }
        cout << "--------" << endl;
        i++;
    }
    cout << endl;
}

int main() {

    string str;
    string res;
    vector <t_stations> stations;
    vector <string> all_stations;
    ifstream file("../kyiv.txt");
    if (file.is_open()) {
        while (getline(file, str))
        {
            if (str.find("#line") != -1)
            {
                getline(file, str);
                get_stations(str, stations, all_stations);
                //cout << "#line " << str << endl;
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

        }
        file.close();
    }
    else
        cout << "Shiiiit" << endl;
    return 0;
}