#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

int main()
{
    int n, m;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin >> n >> m;
    
    std::vector<std::vector<int>> mat;
    mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        mat[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            fin >> mat[i][j];
        }
    }
    
    std::vector<std::vector<bool>> is_visited;
    std::vector<std::vector<int>> distance;
    is_visited.resize(n);
    distance.resize(n);
    for(int i = 0; i < n; ++i)
    {
        distance[i].resize(m, 0);
        is_visited[i].resize(m, false);
        for(int j = 0; j < m; ++j)
        {
            if(mat[i][j] == 1)
            {
                is_visited[i][j] = true;
                distance[i][j] = -1;
            }
        }
    }
    
    std::pair<int, int> start;
    std::pair<int, int> end;
    fin >> start.first >> start.second;
    fin >> end.first >> end.second;
    
    std::queue<std::pair<int, int>> q;
    q.push(start);
    while(!q.empty())
    {
        std::pair<int, int> current = q.front();
        q.pop();
        /*if(current == end)
        {
            break;
        }*/
        const int i = current.first;
        const int j = current.second;
        if(i - 1 >= 0 && !is_visited[i - 1][j])
        {
            q.push(std::make_pair(i - 1, j));
            distance[i - 1][j] = distance[i][j] + 1;
            is_visited[i][j] = true;
        }
        if(i + 1 < n && !is_visited[i + 1][j])
        {
            q.push(std::make_pair(i + 1, j));
            distance[i + 1][j] = distance[i][j] + 1;
            is_visited[i][j] = true;
        }
        if(j - 1 >= 0 && !is_visited[i][j - 1])
        {
            q.push(std::make_pair(i, j - 1));
            distance[i][j - 1] = distance[i][j] + 1;
            is_visited[i][j] = true;
        }
        if(j + 1 < m && !is_visited[i][j + 1])
        {
            q.push(std::make_pair(i, j + 1));
            distance[i][j + 1] = distance[i][j] + 1;
            is_visited[i][j] = true;
        }
    }
    fout << distance[end.first][end.second] << std::endl;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            fout << distance[i][j] << " ";
        }
        fout << std::endl;
    }
    
    return 0;
}
