#include "metro.h"


void find_way(vector<t_stations> stations)
{
    int matrix[stations.size()][stations.size()];
    int i = 0;
    int j;

    while (i < stations.size())
    {
        j = 0;
        while (j < stations.size())
        {
            matrix[i][j] = (find(stations[i].connections.begin(), stations[i].connections.end(), stations[j].name)
                            != stations[i].connections.end()) ? 1 : 0;
            j++;
        }
        i++;
    }
    /*i = 0;
    while (i < stations.size())
    {
        j = 0;
        while (j < stations.size())
        {
            cout << matrix[i][j];
            j++;
        }
        cout << endl;
        i++;
    }*/
}