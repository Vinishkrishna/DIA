#include <iostream>
#include <cmath>
using namespace std;
int max_cap,cap=0,count=0;
float profit=0;
float greedy (int n, float arr[][3]);
void quick_sort(float array[][3], int low, int high);
int partition (float array[][3], int low, int high);

int main()
{
    int n;
    cout << "Enter the number of items : ";
    cin >> n;
    float arr[n][3];
    cout << "Enter each item profit and it's weight: " << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=1; j++)
        {
            cin >> arr[i][j];
        }
        arr[i][2] = arr[i][0] / arr[i][1];
    }
    cout << "Enter the maximum capacity: ";
    cin >> max_cap;
    quick_sort(arr,0,n-1);
    cout << "Sorted array : " << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    float profit = greedy(n-1,arr);
    cout << endl << "Capacity : " << cap << endl;
    cout << "Profit : " << profit << endl;
    cout << "Count = " << count << endl;
    if (count <= n*log2(n) + n)
        cout << "Complexity : O(n log2 n)" << endl;


}

float greedy (int n, float arr[][3])
{
    int i=n;
    while (cap < max_cap)
    {
        if (cap+arr[i][1] <= max_cap)
        {
            cap = cap + arr[i][1];
            //profit = profit + arr[i][0];
            arr[i][2] = 0;
            cout << profit << endl;
            greedy(i-1,arr);
        }
        else if (cap+1 <= max_cap)
        {
            cap++;
            arr[i][1]--;
            //profit = profit + arr[i][2];
            cout << profit << endl;
            greedy(i,arr);
        }
    }
    return profit+arr[i][0];
}

void quick_sort(float array[][3], int low, int high)
{
    int pivot;
    if (low < high)
    {
        count++;
        pivot = partition (array, low, high);
        quick_sort (array, low, pivot-1);
        quick_sort (array, pivot+1, high);
    }
}

int partition (float array[][3], int low, int high)
{
    int left, right;
    float pivot, temp;
    left = low;
    right = high;
    pivot = array[low][2];
    while (left < right)
    {
        
        while (left <= high && array[left][2] <= pivot)
        {
            left++;
            count++;
        }
        while (array[right][2] >  pivot )
        {
            right--;
            count++;
        }
        if (left < right)
        {
            for (int i=0; i<3; i++)
            {
                float temp = array[left][i];
                array[left][i] = array[right][i];
                array[right][i] = temp;
            }
        }
    }
    for (int i=0; i<3; i++)
    {
        float temp1 = array[low][i];
        array[low][i] = array[right][i];
        array[right][i] =  temp1;
    }
    return right; 
}