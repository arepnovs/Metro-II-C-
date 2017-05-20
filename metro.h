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

typedef struct s_dfs
{
    size_t *path;
    size_t *visited;
    size_t **all;
    int path_num;
    size_t size;
    int indx;
} t_dfs;

/*typedef struct		s_dfs
{
    int				indx;
    int				ant;
    int				dest;
    int				*path;
    int				**all_paths;
    int				**best_paths;
    int				amount;
    int				*visited;
    int				*stop;
    int				f;
    int				i;
    int				l;
    int				vert;
    int				all_len;
}					t_dfs;*/
/*void	get_stack_elements(int indx, int *way, t_dfs *path)
{
    int	i;

    i = 0;
    path->all_paths[path->i] = (int*)malloc(sizeof(int) * path->vert);
    while (i < indx)
    {
        path->all_paths[path->i][i] = way[i];
        i++;
    }
    path->i++;
}

void	remember_path(int start, int dest, t_dfs *path, int **matrix)
{
    int	i;

    path->visited[start] = 1;
    path->path[path->indx] = start;
    path->indx++;
    if (start == dest)
        get_stack_elements(path->indx, path->path, path);
    else
    {
        i = 0;
        while (i < path->vert)
        {
            if (path->visited[i] == 0 && matrix[start][i])
                remember_path(i, dest, path, matrix);
            i++;
        }
    }
    path->visited[start] = 0;
    path->indx--;
}

void	all_paths_search(int **matrix, t_lst *start)
{
    t_dfs	path;

    path.dest = loc_dest(start);
    path.vert = start->vert;
    path.path = (int*)malloc(sizeof(int) * start->vert);
    path.visited = (int*)malloc(sizeof(int) * start->vert);
    path.all_paths = (int**)malloc(sizeof(int*) * 10000);
    path.indx = 0;
    path.i = 0;
    ft_memset(path.visited, 0, sizeof(path.visited));
    remember_path(0, path.dest, &path, matrix);*/

void find_way(vector<t_stations> stations);

#endif //METRO_C_METRO_H
