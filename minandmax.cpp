#include <iostream>
using namespace std;
int cnt1=0,cnt2=0;
int maxy(int *arr, int l, int r)
{
    cout << endl;
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << endl;
    if (l == r)
    {
        return arr[l];
    }
    if (l == r - 1)
    {
        if (arr[l] < arr[r])
        {
                cnt1++;
            cout << arr[l] << endl
                 << endl;
            cout << arr[r] << endl
                 << endl;
            return arr[r];
        }
        else
        {
            cnt1++;
            return arr[l];
        }
    }
    int m = l + (r - l) / 2;
    int max1 = maxy(arr, l, m);
    cout << endl;
    int max2 = maxy(arr, m + 1, r);
    if (max1 > max2)
    {
        cout<<"Max:"<<max1<<endl;
        return max1;
    }
    else
    {
        cout<<"Max:"<<max2<<endl;
        return max2;
    }
}
int miny(int *arr, int l, int r)
{
    if (l == r)
    {
        return arr[l];
    }
    
    if (l == r - 1)
    {
        if (arr[l] < arr[r])
        {
            cnt2++;
            return arr[l];
            cout << arr[l] << endl<< endl;
            cout << arr[r] << endl<< endl;
        }
        else
        {
            cnt2++;
            return arr[r];
        }
    }
    int m = l + (r - l) / 2;
    int max1 = miny(arr, l, m);
    int max2 = miny(arr, m + 1, r);
    if (max1 > max2)
    {
        cout<<"Min:"<<max2<<endl;
        return max2;
    }
    else
    {
        cout<<"Min:"<<max1<<endl;
        return max1;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << ":";
        cin >> arr[i];
    }
    cout << "For maximum:" << endl;
    int maximum = maxy(arr, 0, n - 1);
    cout << "For minimum:" << endl;
    int minimum = miny(arr, 0, n - 1);
    cout << "The max element in the array:" << maximum << endl;
    cout << "The min element in the array:" << minimum<<endl;
    
    if (cnt1<=n-1)
    {
        cout<<"Time complexity is O(n)";
    }
    cout<<endl;
    if (cnt2<=n-1)
    {
        cout<<"Time complexity is O(n)";
    }
    return 0;
}
