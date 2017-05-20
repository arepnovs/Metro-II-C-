#include "metro.h"

void	get_stack_elements(t_dfs *path)
{
    int i;

    i = 0;
    path->all[path->path_num] = (size_t *)malloc(sizeof(size_t) * path->size);
    memset(path->all[path->path_num], 0, path->size);
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
        do
        {
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
    else
    {
        cout << "Enter your destination" << endl;
        do
        {
            getline(cin, input);
            while (i < stations.size()) {
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
    }
    return(stations);
}

void choose_best_path(size_t **all, int path_num, vector<t_stations> stations)
{
    int i = 0;
    int len = 1000000;
    int low_len = 1;
    int best;

    while (i < path_num)
    {
        while (all[i][low_len] != 0)
            low_len++;
        if (low_len < len)
        {
            len = low_len - 1;
            best = i;
        }
        i++;
        low_len =1;
    }
    i = 0;
    while (i < len + 1)
    {
        cout << stations[all[best][i]].name << "  ";
        i++;
    }
    cout << endl;
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
    memset(path.visited, 0, path.size);
    memset(path.path, 0, path.size);
    remember_path(0, dest, &path, matrix);
    choose_best_path(path.all, path.path_num, stations);
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
    all_paths_search(stations, matrix);
}

