#include <iostream>
using namespace std;
int num;
int graph[50][50], select[50], total = 0;
void minimum(int k, int nodes);

void prims(int graph[][50], int nodes)
{
    int i;
    for (i = 0; i < nodes; i++)
        select[i] = 0;
    cout << "The Minimal Spanning Tree is" << endl;
    select[1] = 1;
    minimum(1, nodes);
}

void minimum(int k, int nodes)
{
    if (k < nodes)
    {
        int min_dist, v1, v2, i, j;
        min_dist = 999;
        for (i = 0; i < nodes; i++)
        {
            for (j = 0; j < nodes; j++)
            {
                if (graph[i][j] && (select[i] && !select[j]))
                {
                    if (graph[i][j] < min_dist)
                    {
                        min_dist = graph[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }
        cout << v1 + 1 << "->" << v2 + 1 << " - " << min_dist << endl;
        select[v1] = select[v2] = 1;
        total = total + min_dist;
        minimum(k + 1, nodes);
    }
}

int main()
{
    int v1, v2, length, i, j, n, nodes;
    cout << "Enter no of nodes: ";
    cin >> nodes;
    n = nodes;
    for (i = 0; i < nodes; i++)
        for (j = 0; j < nodes; j++)
            cin >> graph[i][j];
    prims(graph, nodes);
    cout << "Total weight is " << total;
    cout << "\nTime complexity is n^3" << endl;
    return 0;
}
