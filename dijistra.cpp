#include <iostream>
using namespace std;
int t = 0;
int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

void djistras(int n, int cost[][10], int distance[])
{
    static int i;
    if (i < n)
    {
        for (int j = 0; j < n; j++)
        {
            distance[j] = min(distance[j], distance[i] + cost[i][j]);
            t++;
        }
        i++;
        djistras(n, cost, distance);
    }
}

int main()
{
    int n, s = 0, cost[10][10], distance[10];
    cout << " enter the number of nodes " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // cout << " enter the weight of row :" << i + 1 << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    distance[0] = 0;
    for (int i = 1; i < n; i++)
    {
        distance[i] = 999;
    }
    djistras(n, cost, distance);
    cout << " by djkstras algorithm the distance from source are:" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << s + 1 << " : ->" << i + 1 << " = " << distance[i] << endl;
    }
    if (n < t * t)
    {
        cout << " the time complexity is O(n*n)" << endl;
    }
    return 0;
}

/*
0 4 0 0 0 0 0 8 0 
4 0 8 0 0 0 0 11 0 
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0 
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0
*/

/*
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0
*/
