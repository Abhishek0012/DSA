#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<int> seg;
vector<int> lazy;
class segment_tree
{
    public:
    segment_tree(int n)
    {
        seg.resize(4*(n+1),0);
        lazy.resize(4*(n+1),0);
    }
    void update(ll src , ll x , ll y , ll l , ll r , ll val)
    {
    //    cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
       if(l>r) return;
       if(lazy[src]!=0)
       {
           seg[src]=seg[src]+ (r-l+1)*lazy[src];
           if(l!=r)
           {
               lazy[2*src]+=lazy[src];
               lazy[2*src+1]+=lazy[src];
           }
           lazy[src]=0; 

       }
       if(x>r || y<l)
       {
            return;
       }
       if(l>=x && r<=y)
       {
           seg[src]=seg[src]+(r-l+1)*val;
           if(l!=r)
           {
               lazy[2*src]+=val;
               lazy[2*src+1]+=val;
           }
           return;
       }
       ll mid = l + (r-l)/2;
       update(2*src,x,y,l,mid,val);
       update(2*src+1,x,y,mid+1,r,val);
       seg[src]=seg[src*2]+seg[src*2+1];
    }
    ll query(ll src , ll x , ll y , ll l , ll r)
    {
       if(l>r) return 0;
       if(lazy[src]!=0)
       {
           seg[src]=seg[src]+(r-l+1)*lazy[src];
           if(l!=r)
           {
               lazy[2*src]+=lazy[src];
               lazy[2*src+1]+=lazy[src];
           }
           lazy[src]=0;
       }
       if(x>r || y<l) return 0;
       if(l>=x && r<=y)
       {
           return seg[src];
       }
       ll mid = l + (r-l)/2;
       if(x<=mid)
       {
           return query(2*src,x,y,l,mid);
       }
       else
       {
           return query(2*src+1,x,y,mid+1,r);
       }
       return 1; 
    }
};
void solve()
{
   ll n,q;
   cin>>n>>q;
   ll arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   segment_tree obj(n);
   for(int i=0;i<q;i++)
   {
      ll x,y;
      cin>>x>>y;
      obj.update(1,x,y,1,n,1);
   }
//    cout<<"HELLO"<<endl;
   vector<ll> brr(n);
   for(int i=0;i<n;i++)
   {
       brr[i]= obj.query(1,i+1,i+1,1,n);
   }
   sort(arr,arr+n);
   sort(brr.begin(),brr.end());
   ll sum=0;
//    for(int i=0;i<n;i++)
//    {
//        cout<<brr[i]<<" ";
//    }
   cout<<endl;
   for(int i=0;i<n;i++)
   {
       sum= sum + arr[i]*brr[i];
   }
   cout<<sum<<endl;
}
int main()
{
    int test=1;
    while(test--)
    {
        solve();
    }
}