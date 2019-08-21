#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 2010
using namespace std;

int v,e,t,x,y,ans;
vector<int> c(N),g[N];

bool isbi(int u)
{
    queue<int> q;
    q.push(u); c[u]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int y: g[x])
        {
            if(c[x]==c[y]) return false;
            if(c[y]) continue;
            if(c[y]==0) c[y]=3-c[x];
            q.push(y);
        }
    }
    return true;
}

int main()
{
    cin>>t;
    FOR(k,1,t+1)
    {
        cin>>v>>e; ans=1;
        fill(c.begin(),c.end(),0);
        FOR(i,1,v+1) g[i].clear();
        FOR(i,0,e) cin>>x>>y,g[x].push_back(y);
        FOR(i,1,v+1) if(!c[i]) ans&=isbi(i);
        cout<<"Scenario #"<<k<<":\n";
        cout<<(ans?"No suspicious bugs found!":"Suspicious bugs found!")<<'\n';
    }

    return 0;
}