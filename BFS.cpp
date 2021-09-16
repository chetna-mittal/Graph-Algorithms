#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define pii pair<int,int>
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define loopi(mp) for(auto i=mp.begin();i!=mp.end();i++)
#define ff first
#define ss second
#define rep(i,k,n) for(int i=k;i<n;i++)
#define repl(i,k,n) for(ll i=k;i<n;i++)
typedef long long ll;

using namespace std;
const ll mx=(1e5)+1;
const ll mod=1000000007;

vector<int>adj[mx];

void bfs(int curr,bool vis[],vector<int>& ans)
{
    queue<int>q;
    vis[curr]=1;
    q.push(curr);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for(auto it:adj[curr])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        bool vis[n+1]={0};
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans;
        bfs(1,vis,ans);
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}