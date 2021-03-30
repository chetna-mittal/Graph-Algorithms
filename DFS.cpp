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

bool dfs(int curr,int n,bool vis[])
{
    if(curr==n)
    {
        return true;
    }
    vis[curr]=1;
    for(int i=0;i<adj[curr].size();i++)
    {
        if(!vis[adj[curr][i]])
        {
            dfs(adj[curr][i]);
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
        if(dfs(1,n,vis))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}