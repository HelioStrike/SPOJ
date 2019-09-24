#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define mii map<int,int>
#define N 100010
using namespace std;

int n,q,g,h,a[N];
mii t[4*N];

mii combine(mii a,mii b)
{
    mii m=a;
    for(auto p: b) { m[p.first]+=p.second; }
    return m;
}

void build(int v,int l,int r)
{
    if(l==r) { t[v][a[l]]++; return; }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}

mii query(int v,int x,int y,int l,int r)
{
    if(l>y || r<x) { mii m; return m; }
    if(x<=l && y>=r) return t[v];
    int m=(l+r)/2;
    mii c=query(2*v,x,y,l,m);
    mii d=query(2*v+1,x,y,m+1,r);
    return combine(c,d);
}

int main()
{
    cin>>n>>q; FOR(i,0,n) cin>>a[i];
    build(1,0,n-1);
    FOR(i,0,q)
    {
        cin>>g>>h; g--,h--;
        mii m=query(1,g,h,0,n-1);
        //for(auto p: m) cout<<p.first<<' '<<p.second<<'\n';
        int maxm=0,maxi=0;
        for(auto p: m) if(p.second>maxm) maxm=p.second,maxi=p.first;
        cout<<maxm<<'\n';
    }
    cin>>n;

    return 0;
}