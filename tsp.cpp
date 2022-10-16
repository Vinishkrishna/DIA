#include <iostream>
using namespace std;
int c = 0, cost = 999;
int n;
int arr[10][10], b[10];
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void copy_array(int *a, int m)
{
    int i, sum = 0;
    for (i = 0; i <= m; i++)
    {
        sum += arr[a[i % n]][a[(i + 1) % n]];
    }
    if (cost > sum)
    {
        for (int i = 0; i < n; i++)
            b[i] = a[i];

        cost = sum;
    }
}
void permute(int *a, int i, int n)
{
    int j, k;
    if (i == n)
    {
        copy_array(a, n);
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));

            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
}
int main()
{
    int i, j;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter adjacency matrix : \n";
    int a[n];
    for (i = 0; i < n; i++)
        a[i] = i;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    permute(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << b[i]
             << " => ";
    }
    cout << 0 << endl;
    cout << "minimum cost:" << cost << endl;
}
