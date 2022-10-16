#include<iostream>
#include<math.h>
using namespace std;
int count=0;
int array(int arr[],int key,int low,int high){
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        count++;
        if (arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    int n,result,key;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element at "<<i<<":\n";
        cin>>arr[i];
    }
    cout<<"Enter element to find:";
    cin>>key;
    result=array(arr,key,0,n-1);
    (result==-1)?cout<<"Element not found" : cout<<"Element found at index :"<<result;
    cout<<endl;
    if (count==1)
    {
        cout<<"Best case";
    }
    int res=log2(n);
    int j=ceil(res);
    if(count==j)
    {
        cout<<"Worst case";
        goto label;
    }  
    cout<<"Other case";
    label:
    return 0;
}
