#include<bits/stdc++.h>
using namespace std;
class segment_tree
{
    public:
    vector<int> arr;
    vector<int> seg;
    segment_tree(int n)
    {
        arr.resize(n+1);
        seg.resize(4*n);
    }
    void build(int src , int l , int r)
    {
        if(l==r)
        {
            seg[src]=arr[l];
            cout<<seg[src]<<" "<<l<<" "<<r<<endl;
            return;
        }
        int mid = l + (r-l)/2;
        build(2*src , l , mid);
        build(2*src+1 , mid+1 ,r);
        seg[src]=seg[src*2]+seg[src*2+1];
        cout<<seg[src]<<" "<<l<<" "<<r<<endl;
    }
    void update(int src , int l , int r , int val , int ind)
    {
        if(ind==l && l==r)
        {
            arr[ind]=val;
            seg[src]=val;
            return;
        }
        int mid = l+(r-l)/2;
        if(ind <=mid) update(src*2,l,mid,val,ind);
        else update(src*2+1,mid+1,r,val,ind);
        seg[src]=seg[src*2]+seg[src*2+1];
    }
    int query(int src , int l ,int r  , int x , int y)
    {
        if(x>r || y<l || l>r) return 0;
        if(x<=l && y>=r) return seg[src];
        int mid = l + (r-l)/2;
        return query(src*2,l,mid,x,y) + query(src*2+1,mid+1,r,x,y);
    }
};
void solve()
{
    int n;
    cin>>n;
    segment_tree obj(n);
    for(int i=1;i<=n;i++)
    {
        cin>>obj.arr[i];
    }
    obj.build(1,1,n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<obj.query(1,1,n,x,y)<<endl;
    }
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}
