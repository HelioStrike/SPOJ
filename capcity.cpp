/*Segment Tree implementation */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 100010
using namespace std;

int n,e,x,y,c,cc,in[N],ccs[N],vis[N];
vector<int> topo,g[N],gr[N];

void dfs1(int u)
{
    vis[u]=1;
    for(int v: g[u]) if(!vis[v]) dfs1(v);
    topo.push_back(u);
}

void dfs2(int u,int cc)
{
    vis[u]=0;
    for(int v: gr[u]) if(vis[v]) dfs2(v,cc);
    ccs[u]=cc;
}

int main()
{
    cin>>n>>e;
    FOR(i,0,e)
    {
        cin>>x>>y;
        g[y].push_back(x);
        gr[x].push_back(y);
    }
    FOR(i,1,n+1) if(!vis[i]) dfs1(i);
    for(int i=topo.size()-1;i>=0;i--) if(vis[topo[i]]) dfs2(topo[i],cc++);
    FOR(i,1,n+1) for(int u: g[i]) if(ccs[i]!=ccs[u]) in[ccs[u]]++;
    FOR(i,0,cc) if(in[i]==0) c++;
    if(c>1) cout<<0<<'\n';
    else
    {
        c=0;
        FOR(i,1,n+1) if(in[ccs[i]]==0) c++;
        cout<<c<<'\n';
        FOR(i,1,n+1) if(in[ccs[i]]==0) cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}