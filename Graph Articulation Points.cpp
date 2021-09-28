#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void dfs(int node,int parent,vector<int>& tin,vector<int>& low,vector<int>& vis,vector<int> adj[],vector<int>& articulation,int& timer)
{
    vis[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto it:adj[node])
    {
        if(it==parent)
        {
            continue;
        }
        if(!vis[it])
        {
            dfs(it,node,tin,low,vis,adj,articulation,timer);
            low[node]=min(low[node],low[it]);
            if(low[it]>=tin[node] && parent!=-1)
            {
                articulation[node]=1;
            }
            child++;
        }
        else
        {
            low[node]=min(low[node],tin[it]);
        }
    }
    if(parent==-1 && child>1)
    {
        articulation[node]=1;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>vis(n,0);
    vector<int>articulation(n,0);
    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,tin,low,vis,adj,articulation,timer);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(articulation[i]==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
