#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 10000010
using namespace std;

int lazy[4*N];
set<int> s;

void shift(int v)
{
    if(lazy[v]) lazy[2*v]=lazy[2*v+1]=lazy[v],lazy[v]=0;
}

void update(int v,int color,int x,int y,int l,int r)
{
    if(l>y || x>r) return;
    if(x<=l && y>=r) { lazy[v]=color; return; }
    shift(v);
    int m=(l+r)/2;
    update(2*v,color,x,y,l,m);
    update(2*v+1,color,x,y,m+1,r);
}

void calc(int v,int l,int r)
{
    if(lazy[v])
    {
        s.insert(lazy[v]);
        return;
    }
    if(l==r) return;
    int m=(l+r)/2;
    calc(2*v,l,m);
    calc(2*v+1,m+1,r);
}

int main()
{
    int t,n,l,r; cin>>t;
    while(t--)
    {
        memset(lazy,0,sizeof(lazy));
        cin>>n;
        FOR(i,1,n+1)
        {
            cin>>l>>r;
            update(1,i,l,r,0,N-1);
        }
        s.clear();
        calc(1,0,N-1);
        cout<<s.size()<<'\n';
    }

    return 0;
}