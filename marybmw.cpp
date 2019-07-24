/*Segment Tree implementation */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 100010
using namespace std;

int t,V,E,u,v,w,pu,pv,ans,p[N];
vector<tuple<int,int,int> > g;
ll spd[N];

int f(int x) { return x==p[x]?x:p[x]=f(p[x]); }

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>V>>E; g.clear();
        FOR(i,0,E) cin>>u>>v>>w,g.push_back(make_tuple(w,u,v));
        FOR(i,1,V+1) p[i]=i;
        sort(g.begin(),g.end());
        for(int i=E-1;i>=0;i--)
        {
            tie(w,u,v)=g[i];
            pu=f(u),pv=f(v);
            if(pu!=pv)
            {
                p[pu]=pv;
                if(!spd[pv]) spd[pv]=w;
                else spd[pv]=min(spd[pv],spd[pu]);
                if(f(1)==f(V))
                {
                    ans=spd[pv];
                    break;   
                }
            }
        }
        cout<<ans<<'\n';
    }
}