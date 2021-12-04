#include<bits/stdc++.h>
using namespace std;
void quick(int arr[] , int i , int j)
{
    if(i>=j) return;
    int pivot = arr[j];
    int st=i;
    int run=i;
    while(run<=j)
    {
        if(arr[run]<pivot)
        {
           swap(arr[run],arr[st]);
           st++;
        }
        run++;
    }
    swap(arr[st],arr[j]);
    quick(arr,i,st-1);
    quick(arr,st+1,j);

}
void quicksort(int arr[]  ,  int n)
{
    quick(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
main()
{
   int arr[]={-5,10,-3,2,-6,7};
   quicksort(arr,sizeof(arr)/sizeof(arr[0]));
}

