#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mi map<int,int>
#define ml map<ll,ll>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vector<int>,greater<int>>
#define loopi(mp) for(auto i=mp.begin();i!=mp.end();i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define pi 3.141592653589793238462
#define rep(i,k,n) for(int i=k;i<n;i++)
#define repl(i,k,n) for(ll i=k;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((int)(x).size())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll mx=(1e5)+1;
const ll mod=1000000007;

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        //n is the number of nodes and m is the number of edges

        //For a directed unweighted graph
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        //For an undirected unweighted graph
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //For a directed weighted graph
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,weight});
        }

        //For an undirected weighted graph
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
    }
    return 0;
}