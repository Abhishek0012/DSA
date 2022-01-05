#include<bits/stdc++.h>
using namespace std;
class segment
{
    public:
    vector<int> seg;
    vector<int> arr;
    segment(int n)
    {
        seg.resize(4*n,0);
        arr.resize(n+1,0);
    }
    void build(int src , int l , int r)
    {
        if(l > r ) return ;
        if(l==r ) 
        {
            seg[src]=arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(src*2,l,mid);
        build(src*2+1 , mid+1 , r);
        seg[src]=seg[src*2]+seg[src*2+1];
    }
    int query(int src , int x , int y , int l , int r)
    {
        if(y < l || x  > r || l > r) return 0;
        if(x<=l && y>=r) return seg[src];
        int mid = l + (r-l)/2;
        int a = query(src*2 , x , y , l , mid);
        int b = query(src*2+1 , x, y , mid + 1 , r);
        seg[src]=a+b;
    }
    void update(int src  , int x , int l , int r)
    {
        if(l > r) return ;
        if(l==r && l==x)
        {
            seg[src]=x;
            arr[x]=x;
            return;
        }
        int mid = l + (r-l)/2;
        if(x <=mid) update(src*2 , x , l , mid);
        else update(src*2+1 , x , mid + 1 , r);
        seg[src]=seg[src*2]+seg[src*2+1];
    }

};
int main()
{
    int n ;
    cin>>n;
    segment obj(n);
    for(int i=1;i<=n;i++)
    {
        cin>>obj.arr[i];
    }
    obj.build(1,1,n);
    int x = obj.query(1,2,4,1,n);
    cout<<x<<endl;
}