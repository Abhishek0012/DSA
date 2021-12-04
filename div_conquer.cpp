#include <bits/stdc++.h>
using namespace std;
class srt
{
public:
    void quicksort(int arr[], int n)
    {
        quick(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void quick(int arr[], int i, int j)
    {
        if (i >= j)
            return;
        int pivot = arr[j];
        int st = i;
        int run = i;
        while (run <= j)
        {
            if (arr[run] < pivot)
            {
                swap(arr[run], arr[st]);
                st++;
            }
            run++;
        }
        swap(arr[st], arr[j]);
        quick(arr, i, st - 1);
        quick(arr, st + 1, j);
    }
    vector<int> mergesort(vector<int> arr , int i , int j)
    {
        if(i>j) return {};
        int mid= i + (j-i)/2;
        vector<int> res;
        vector<int> left = mergesort(arr,i,mid);
        vector<int> right =mergesort(arr,mid+1,j);
        while(left.size()>0 && right.size()>0)
        {
            if(left[left.size()-1]>=right[right.size()-1]) 
            {
                res.push_back(left[left.size()-1]);
                left.pop_back();
            }
            else
            {
                res.push_back(right[right.size()-1]);
                right.pop_back();
            }
        }
        while(left.size()>0)
        {
            res.push_back(left[left.size()-1]);
            left.pop_back();
        }
        while(right.size()>0)
        {
            res.push_back(right[right.size()-1]);
            right.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    void msort(vector<int> arr, int n)
    {
        int i=0 , j= n -1;
        vector<int> res = mergesort(arr,i,j);
        for(int x : res) cout<<x<<" ";
        cout<<endl;
    }

};
int main()
{
    vector<int> arr = {-5, 10, -3, 2, -6, 7};
    srt obj;
    obj.msort(arr,6);
}
