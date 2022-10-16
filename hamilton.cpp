#include <iostream>
using namespace  std;

int n, graph[50][50],arr[50],cycle=0; 
void hamiltonian (int k);
void next_vertex (int arr[],int k);

int main()
{
    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "Enter Adjacency Matrix: " << endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cin >> graph[i][j];
    }  
    arr[1] = 1; 
    for (int i=2; i<=n; i++)
        arr[i] = 0;
    hamiltonian (2);
    return 0;
} 

void hamiltonian (int k)
{
    do 
    {
        next_vertex(arr,k);
        if (arr[k] == 0)
            return;
        //if last reached then print and come back.
        if (k == n)
        {
            cycle++;
            cout << "Cycle " << cycle << " : ";
            for (int i=1; i<=n; i++)
                cout << arr[i] << " ";
            cout << 1 << endl;
        }
        else
            hamiltonian (k+1);
    } while (true);
}

void next_vertex (int arr[],int k)
{
    do 
    {
        arr[k] = (arr[k] + 1)%(n+1);
        //0 means stop
        if (arr[k] == 0)
            return;
        //Edge is there or not
        if (graph[arr[k-1]][arr[k]] != 0)
        {
            //Checking for duplicates
            for (int j=1; j<k; j++)
            {   
                if (arr[j] == arr[k])
                    break;
                if (j==k-1)
                    //Reached last position check that there is a connection to vertex 1
                    if (k<n || (k==n && graph[arr[n]][arr[1]] != 0))
                        return;
            }
        }
    } while (true);
}
