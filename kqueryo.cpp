#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 30010
using namespace std;

int n,q,a[N],ql,qr,qk,ans;
vector<int> t[N*4];

void build(int v,int l,int r)
{
    if(l==r) { t[v].push_back(a[l]); return; }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    merge(t[2*v].begin(),t[2*v].end(),t[2*v+1].begin(),t[2*v+1].end(),
        back_inserter(t[v]));
}

int query(int v,int k,int x,int y,int l,int r)
{
    if(x>r || l>y) return 0;
    if(x<=l && y>=r) return t[v].size()
        -(upper_bound(t[v].begin(),t[v].end(),k)-t[v].begin());
    int m=(l+r)/2;
    return query(2*v,k,x,y,l,m)+query(2*v+1,k,x,y,m+1,r);
}

int main()
{
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    build(1,0,n-1);
    scanf("%d",&q);
    FOR(i,0,q)
    {
        scanf("%d%d%d",&ql,&qr,&qk);
        ql^=ans,qr^=ans,qk^=ans;
        ql=max(0,ql-1);
        qr=min(qr-1,n-1);
        if(ql>qr) ans=0;
        else ans=query(1,qk,ql,qr,0,n-1);
        printf("%d\n",ans);
    }
}