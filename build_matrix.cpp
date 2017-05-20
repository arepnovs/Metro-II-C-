#include "metro.h"

void	get_stack_elements(t_dfs *path)
{
    int i;

    i = 0;
    path->all[path->path_num] = (size_t *)malloc(sizeof(size_t) * path->size);
    while (i < path->indx && path->path_num <= 100)
    {
        path->all[path->path_num][i] = path->path[i];
        i++;
    }
    path->path_num++;
}

void	remember_path(size_t start, long dest, t_dfs *path, int **matrix)
{
    size_t	i;

    path->visited[start] = 1;
    path->path[path->indx] = start;
    path->indx++;
    if (start == dest)
        get_stack_elements(path);
    else
    {
        i = 0;
        while (i < path->size)
        {
            if (path->visited[i] == 0 && matrix[start][i])
                remember_path(i, dest, path, matrix);
            i++;
        }
    }
    path->visited[start] = 0;
    path->indx--;
}

vector<t_stations>     get_start_and_dest(vector<t_stations> stations, int *station, int flag)
{
    *station = -1;
    string input;
    int i = 0;
    if (flag == 1)
    {
        cout << "Enter start station" << endl;
        do {
            getline(cin, input);
            while (i < stations.size())
            {
                if (stations[i].name.compare(input) == 0)
                {
                    *station = i;
                    break;
                }
                i++;
            }
            if (*station == -1)
            {
                cout << "Wrong input! Wrong station name" << endl;
                i = 0;
            }
        }
        while (*station == -1);
        if (station != 0)
            swap(stations[*station], stations[0]);
    }
    else {
        cout << "Enter your destination" << endl;
        do {
            getline(cin, input);
            while (i < stations.size()) {
                if (stations[i].name.compare(input) == 0)
                    *station = i;
                i++;
            }
            if (*station == -1)
            {
                cout << "Wrong input! Wrong station name" << endl;
                i = 0;
            }
        } while (*station == -1);
    }
    return(stations);
}

void	all_paths_search(vector<t_stations> stations, int **matrix)
{
    t_dfs path;
    int dest;
    path.path_num = 0;
    path.size = stations.size();
    path.visited = (size_t *)malloc(sizeof(size_t) * path.size);
    path.path = (size_t *)malloc(sizeof(size_t) * path.size);
    path.all = (size_t **)malloc(sizeof(size_t) * 100);
    path.indx = 0;

    stations = get_start_and_dest(stations, &dest, 0);
    remember_path(0, dest, &path, matrix);
    int i = 0;
    int j;
    /*while (i < path.path_num)
    {
        j = 0;
        while (j < path.size)
        {
            cout << stations[path.all[i][j]].name << " ";
            j++;
        }
        cout << endl;
        i++;
    }*/
}

void find_way(vector<t_stations> stations)
{
    int **matrix;
    int i = 0;
    int j;
    int start;

    matrix = (int **)malloc(sizeof(int) * stations.size());
    stations = get_start_and_dest(stations, &start, 1);
    while (i < stations.size())
    {
        j = 0;
        matrix[i] = (int *)malloc(sizeof(int) * stations.size());
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
    all_paths_search(stations, matrix);
}

