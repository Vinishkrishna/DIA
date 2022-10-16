#include <iostream>
using namespace std;
int n, m, count, arr[50][50], sol, col[50];
void print(int col[]);
bool check(int arr[][50], int col[], int c, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[v][i] == 1 && c == col[i])
            return false;
    }
    return true;
}
bool graph(int arr[][50], int col[], int v, int m)
{
    if (v == n)
    {
        print(col);
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (check(arr, col, i, v))
        {
            col[v] = i;
            graph(arr, col, v + 1, m);
            count++;
        }
        col[v] = 0; // backtracking condition
    }
    return true;
}
void print(int col[])
{
    cout << "Solution:" << ++sol << endl;
    for (int i = 0; i < n; i++)
        cout << col[i] << " ";
    cout << endl;
}
int main()
{
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    cout << "Enter adjacency Matrix: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    graph(arr, col, 0, m);
    return 0;
}
