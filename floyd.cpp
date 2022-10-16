#include <iostream>
#include <cmath>
using namespace std;

int temp[50][50], arr[50][50];

int n,m,count=0;
void floyd_warshall(int m,int n, int arr[][50]);

int main()
{
    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "Enter the basic distance matrix: " << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    floyd_warshall(0,n,arr);
    if (count <= pow(n,3))
        cout << "Complexity : O(n^3)";
    return 0;
}

void floyd_warshall(int m,int n, int arr[][50])
{
    if (m < n)
    {
        cout << "Distance matrix " << m+1 << endl;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                count++;
                temp[i][j] = min(arr[i][j], arr[i][m]+arr[m][j]);
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }
        floyd_warshall(m+1,n,temp);
    }
}
