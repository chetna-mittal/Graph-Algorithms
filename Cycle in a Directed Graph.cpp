#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define pii pair<int,int>
#define ps(x,y) fixed<<setprecision(y)<<x
typedef long long ll;

using namespace std;
const int mx = 1e5+5;

bool solve(vector<int>adj[],vector<bool>vis,int curr)
{
    if(vis[curr]==true)
    {
        return true;
    }
    bool flag=false;
    for(int i=0;i<adj[curr].size();i++)
    {
        flag=solve(adj,vis,adj[curr][i]);
        if(flag==true)
        {
            return true;
        }
    }
    return false;
}

bool iscyclic(int n,vector<int>adj[])
{
    vector<bool>vis(n,false);
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        vis[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            flag=solve(adj,vis,adj[i][j]);
            if(flag==true)
            {
                return true;
            }
        }
        vis[i]=false;
    }
    return false;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        if(iscyclic(n,adj))
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