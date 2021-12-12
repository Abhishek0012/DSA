#include<bits/stdc++.h>
using namespace std;
class G_colour
{
    public:
    void colour(vector<pair<int,int>> a_list[], int n)
    {
        int col[n+1];
        memset(col,-1,sizeof(col));
        queue<pair<int,int>> q;
        q.push({1,1});
        while(q.size()!=0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto it : a_list[x])
            {
               if(col[it.first]==-1)
               {
                 if(y==1)
                 {
                     col[it.first]=0;
                     q.push({it.first,0});

                 }
                 if(y==0)
                 {
                     col[it.first]=1;
                     q.push({it.first,1});

                 }
               }
               if((col[it.first]==1 && y==0) || (col[it.first]==0 && y==1))
               {
                   continue;
               }
               else
               {
                   return ;
               }
            }
        }
        for(int i=1;i<=n;i++)
        {
             cout<<i<<" "<<col[i]<<endl;
        }
    }
};
// hello
class ufind
{
    public:
    bool find(int a ,int parent[])
    {
        while(parent[a]!=a) a=parent[a];
        return a;
    }
    bool uni(int a , int b , int parent[])
    {
        int px = find(a,parent);
        int py = find(b,parent);
        if(px==py)
        {
            return false;
        }
        parent[px]=parent[py];
        return true;
    }
};
class mst
{
    public:
    void krushkal(vector<pair<int,pair<int,int>>> list , int n)
    {
       int parent[n+1];
       for(int i=0;i<=n;i++)
       {
           parent[i]=i;
       }
       ufind obj;
       sort(list.begin(),list.end());
       int count=0 , ans=0;
       for(int i=0;i<list.size() && count< n-1 ;i++)
       {
           int x = list[i].second.first;
           int y = list[i].second.second;
           int w = list[i].first;
           if(obj.find(x,parent)!=obj.find(y,parent)) continue;
           else
           {
               cout<<x<<"-"<<y<<" "<<w<<"\n";
               ans+=w;
               count++;
               obj.uni(x,y,parent);
           }
       }
       cout<<ans<<endl;
    }
    void prims1(vector<pair<int,int>> arr[],int n)
    {
       int src=1;
       int dist[n+1];
       for(int i=1;i<=n;i++) dist[i]=INT_MAX;
       int vis[n+1];
       int par[n+1];
       for(int i=0;i<=n;i++) par[i]=i;
       memset(vis,false,sizeof(vis));
       vis[1]=1;
       int ans=0;
       int count=n-1;
       while(count--)
       {
           int pos=src;
           int mn=INT_MAX;
           for(auto it : arr[src])
           {
               dist[it.first]=min(dist[it.first],it.second);
               if(dist[it.first] > it.second)
               {
                   par[it.first]=src;
                   dist[it.first]=it.second;
               }
           }
           for(int i=1;i<=n;i++)
           {
               if(!vis[i])
               {
                   if(mn > dist[i])
                   {
                       mn=dist[i];
                       pos=i;
                   }
               }
           }
           ans=ans+mn;
           cout<<pos<<"--"<<par[pos]<<endl;
           src=pos;
           vis[src]=true;
       }
       cout<<ans<<endl;
    }
};
class spsp
{
    public:
    void dijsktra(vector<pair<int,int>> arr[],int n , int src) // only valid for non negtive edges type of graph!
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // store {weight,index}
        int dist[n+1];
        for(int i=0;i<=n;i++) dist[i]=INT_MAX;
        dist[src]=0;
        pq.push({0,src});
        while(pq.size()!=0)
        {
            int x = pq.top().second;
            int y = pq.top().first;
            pq.pop();
            for(auto it : arr[x])
            {
                if(it.second + dist[x] < dist[it.first])
                {
                    dist[it.first]=it.second + dist[x];
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=src)
            {
                cout<<"shortest path b/w "<<src<<" &"<<i<<" is "<<dist[i]<<endl;
            }
        }
    }
    void bellman(vector<pair<int,pair<int,int>>> list,int n , int src)
    {
    int dist[n+1];
    for(int i=0;i<=n;i++) dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=0;i<n;i++)
    {
        for(auto it : list)
        {
            int x = it.second.first;
            int y = it.second.second;
            int w = it.first;
            dist[y]=min(dist[y],dist[x]+w);
        }
    }
        for(int i=1;i<=n;i++)
        {
            if(i!=src)
            {
                cout<<"shortest path b/w "<<src<<" &"<<i<<" is "<<dist[i]<<endl;
            }
        }
    }
};
class traverse
{
    public:
    void bfs(vector<pair<int,int>> a_list[], int src , int n , int vis[])
    {
       queue<int> q;
       q.push(src);
       vis[src]=true;
       while(!q.empty())
       {
           int x = q.front();
           q.pop();
           cout<<x<<" ";
           for(auto it : a_list[x])
           {
               if(!vis[it.first])
               {
                   q.push(it.first);
                   vis[it.first]=true;
               }
           }
       }
    }
    void dfs(vector<pair<int,int>> a_list[], int src , int n , int vis[])
    {
        vis[src]=true;
        cout<<src<<" ";
        for(auto x : a_list[src])
        {
            if(!vis[x.first])
            {
                dfs(a_list,x.first,n,vis);
            }
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    int a_matrix[n+1][n+1];
    memset(a_matrix,0,sizeof(a_matrix));
    vector<pair<int,int>> a_list[n+1];
    vector<pair<int,pair<int,int>>> list;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        list.push_back({z,{x,y}});
        a_matrix[x][y]=z;
        a_matrix[y][x]=z;
        a_list[x].push_back({y,z});
        a_list[y].push_back({x,z});
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<a_matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<"->";
    //     for(int j=0;j<a_list[i].size();j++)
    //     {
    //         cout<<a_list[i][j].first<<"-"<<a_list[i][j].second<<"->";
    //     }
    //     cout<<endl;
    // }
    // int vis[n+1];
    // memset(vis,false,sizeof(vis));
    // traverse obj;
    // obj.bfs(a_list,2,n,vis);
    // for(int i=1;i<=n;i++)
    // {
    //     if(!vis[i])
    //     {
    //        obj.bfs(a_list,i,n,vis);
    //     }
    // }
    // memset(vis,false,sizeof(vis));
    // cout<<endl;
    // obj.dfs(a_list,2,n,vis);
    mst obj;
    // obj.krushkal(list,n);
    // obj.prims1(a_list,n);
    spsp obj1;
    obj1.dijsktra(a_list,n,1);
    cout<<endl;
    obj1.bellman(list,n,1);

}
