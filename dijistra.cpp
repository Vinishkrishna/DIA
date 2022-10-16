#include <iostream>
using namespace std;

int n,short_path[50],reached[50],cost[50][50],backtrack[50][50];
int minidis (int short_path[], int reached[])
{
    int min_index,minidis = 9999;
    for (int i=0; i<n; i++)
    {
        if (reached[i]==0 && short_path[i] <= minidis) 
        {
            min_index = i;
            minidis = short_path[i];
        }
    }
    return min_index;
}
void dijistra (int m,int short_path[], int reached[])
{
    if (m > 0)
    {
        int minidismum = minidis(short_path,reached);
        reached[minidismum] = 1;
        for (int j=0; j<n; j++)
        {
            if (short_path[minidismum] + cost[minidismum][j] < short_path[j]) 
            {
                short_path[j] = short_path[minidismum] + cost[minidismum][j];
            }
            cout << short_path[j] << " ";
            backtrack[minidismum][j] = short_path[j];
        }
        cout << endl;
        dijistra (m-1,short_path,reached);
    }

}

int main()
{
    int i,j,k;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the array of graph: ";
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (i=0; i<n ;i++)
    {
        short_path[i] = 9999;
        reached[i] = 0;
    }
    cout << "Enter the source vertex: ";
    cin >> k;
    short_path[k-1] = 0;
    dijistra(n,short_path,reached);
    for (j=0; j<n; j++)
    {
        cout << short_path[j] << " ";
    }

    cout << endl;
    cout<<"Visited Array: "<<endl;
    cout << endl;
    for (i=0; i<n; i++)
        cout << reached[i] << " ";

    cout << endl;
    cout<<"Shortest Distance: "<<short_path[5];

    cout << endl;
    return 0;
}
