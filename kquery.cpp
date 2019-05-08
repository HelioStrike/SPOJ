#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
#define piipii pair<pii,pii>
#define fi first
#define se second
#define N 30010
#define Q 200010
using namespace std;

int n,q,po,ans[Q],t[N*4];
pii a[N];
piipii qs[Q];

void update(int v,int p,int l,int r)
{
    if(l==r) { t[v]=1; return; }
    int m=(l+r)/2;
    if(p<=m) update(2*v,p,l,m);
    else update(2*v+1,p,m+1,r);
    t[v]=t[2*v]+t[2*v+1];
}

int sum(int v,int x,int y,int l,int r)
{
    if(l>y || x>r) return 0;
    if(l>=x && y>=r) return t[v];
    int m=(l+r)/2;
    return sum(2*v,x,y,l,m)+sum(2*v+1,x,y,m+1,r);
}

int main()
{
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i].fi),a[i].se=i;
    sort(a,a+n);
    scanf("%d",&q);
    FOR(i,0,q) scanf("%d%d%d",&qs[i].se.fi,&qs[i].se.se,&qs[i].fi.fi),qs[i].fi.se=i;
    sort(qs,qs+q);

    FOR(i,0,q)
    {
        while(po<n && a[po].fi<=qs[i].fi.fi) update(1,a[po++].se,0,n-1);
        ans[qs[i].fi.se]=qs[i].se.se-qs[i].se.fi+1-sum(1,qs[i].se.fi-1,qs[i].se.se-1,0,n-1);
    }

    FOR(i,0,q) printf("%d\n",ans[i]);
}