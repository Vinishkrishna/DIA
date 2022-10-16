#include<iostream>
using namespace std;
int count=0;

int array(int arr[],int n,int key){
    for (int i = 0; i < n; i++)
    {
        ++count;
        if (arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n,key;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element at "<<i<<":";
        cin>>arr[i];
    }
    cout<<"Enter element to search:";
    cin>>key;
    int result=array(arr,n,key);
    (result==-1) ?cout<<"Element not found ":cout<<"Element found at index "<<result;
    cout<<endl;
    if (count==1)
    {
        cout<<"Best case";
    }
    else if (count==n)
    {
        cout<<"Worst case";
    }
    else
    {
        cout<<"Average case";
    }
    return 0;
}
