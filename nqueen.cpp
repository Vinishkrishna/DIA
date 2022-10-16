#include <iostream>
using namespace std;

int arr[50][50],n,count=0,num=0;
void fill_queens (int n,int row);
int check (int n, int column, int m);
void printsol ();

int main ()
{
    int i,j;
    cout << "Enter number of rows and columns: ";
    cin >> n;
    fill_queens (n,0);
    cout << "Count: " << count;
    return 0;
}

void fill_queens (int n,int row)
{
    if (row == n)
    {
        printsol();
        return;
    }
    for (int i=0; i<n; i++)
    {
        if (check(n, row, i))
        {
            arr[row][i] = 1;
            fill_queens (n,row+1);
            count++;
        }
        arr[row][i] = 0;
    }
    return;
}

int check (int n, int row, int column)
{
    for (int i=0; i<row; i++)
        if (arr[i][column] == 1)
            return 0;
    
    for (int i=row-1, j=column-1; i>=0 && j>=0 ; i-- , j--)
        if (arr[i][j] == 1)
            return 0;

    for (int i=row-1, j=column+1; i>=0 && j<n ; i--, j++)
        if (arr[i][j] == 1)
            return 0;
    
    return 1;
}

void printsol ()
{
    num++;
    cout << "Solution " << num << endl;
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
