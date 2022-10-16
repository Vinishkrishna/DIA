#include <iostream>
#include <cmath>
using namespace std;

int n,max_cap=0,count=0;
int tab[50][50],arr[10][10];
int knap_sack (int i, int j);
int main()
{
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter maximum acceptable Capacity: ";
    cin >> max_cap;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<2; j++)
        {
            cin >> arr[i][j];
        }
    }   
    int max_profit = knap_sack (n,max_cap);
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=max_cap; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Maximum Profit : " << max_profit << endl;
    int i=n;
    int j=max_cap;
    while( j!=0 && i!=0) 
    {
		if(tab[i][j] != tab[i-1][j]) 
        {
			arr[i-1][2]=1;
			j=j-arr[i-1][1];
			i--;
		} else
		   i--;
	}
    cout << "Weight     Profit" << endl;
    for (i=0; i<n; i++)
    {
        if (arr[i][2] == 1 )
        cout << arr[i][1] << "           " << arr[i][0] << endl;
    }
    cout << "Count = " << count << endl;
    if (count <= 2*pow(2,n))
        cout << "Complexity: O(2^n)";
    return 0;
}

int knap_sack (int i, int j)
{
    count++;
    if (i==0 || j==0)
        return 0;
    else if (j < arr[i-1][1])
        tab[i][j] = knap_sack(i-1,j);
    else
        tab[i][j] = max(knap_sack(i-1,j), arr[i-1][0] + knap_sack(i-1,j-arr[i-1][1]));
    return  (tab[i][j]);       
}
