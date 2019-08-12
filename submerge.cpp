/*Segment Tree implementation */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 10010
using namespace std;

int n,m,u,v,timer,tin[N],low[N],vis[N];
vector<int> g[N];
set<int> pts;

void dfs(int u,int p)
{
    vis[u]=1;
    tin[u]=low[u]=timer++;
    int children=0;
    for(int v: g[u])
    {
        if(v==p) continue;
        if(vis[v]) low[u]=min(low[u],tin[v]);
        else
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(tin[u]<=low[v] && p!=-1) pts.insert(u);
            children++;
        }
    }
    if(p==-1 && children>1) pts.insert(u);
}

int main()
{
    while(cin>>n>>m)
    {
        if(!n && !m) break;
        memset(vis,0,sizeof(vis)); pts.clear(); timer=0;
        FOR(i,1,n+1) g[i].clear();
        FOR(i,1,m+1) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
        dfs(1,-1);
        cout<<pts.size()<<'\n';
    }

    return 0;
}