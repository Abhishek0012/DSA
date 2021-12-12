// competitive programming !
#include<bits/stdc++.h>
using namespace std;
int mx=INT_MIN , pn = 1;
void dfs(int src ,vector<int> adj[] ,int vis[] , int ds)
{
  if(ds>mx)
  {
      mx=ds;
      pn=src;
  }
  vis[src]=true;
  for(int x: adj[src])
  {
      if(!vis[x])
      {
          dfs(x,adj,vis,ds+1);
      }
  }
}
void solve()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int vis[n+1];
    memset(vis,false,sizeof(vis));
    dfs(1,adj,vis,0);
    memset(vis,false,sizeof(vis));
    dfs(pn,adj,vis,0);
    cout<<mx<<endl;
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