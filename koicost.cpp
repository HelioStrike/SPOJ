/*Segment Tree implementation */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define MOD 1000000000
#define N 100010
using namespace std;

int V,E,u,v,w,su,sv;
vector<tuple<int,int,int> > g;
ll ans,cu,cv,p[N],sz[N],sum[N];

int f(int x) { return (x==p[x]?x:p[x]=f(p[x])); }

int main()
{
    cin>>V>>E;
    FOR(i,0,E) cin>>u>>v>>w,g.push_back(make_tuple(w,u,v));
    sort(g.begin(),g.end());
    FOR(i,0,E)
    {
        tie(w,u,v)=g[i];
        sum[i]=w+(i>0?sum[i-1]:0);
    }
    FOR(i,1,V+1) p[i]=i,sz[i]=1;
    for(int i=E-1;i>=0;i--)
    {
        tie(w,u,v)=g[i];
        su=f(u),sv=f(v);
        if(su!=sv)
        {
            cu=sz[su],cv=sz[sv];
            ans+=cu*cv*sum[i];
            if(ans>MOD) ans%=MOD;
            p[u]=p[v];
            sz[f(u)]=cu+cv;
            sz[f(v)]=cu+cv;
        }
    }
    cout<<ans<<'\n';

    return 0;
}