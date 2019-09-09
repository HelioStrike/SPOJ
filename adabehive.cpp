#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 2010
using namespace std;

ll n,m,q,w,x,y,z,t[N][N];

void put(ll i,ll j,ll val)
{
    ll k;
    while(i<=n)
    {
        k=j;
        while(k<=m)
        {
            t[i][k]+=val;
            k+=k&(-k);
        }
        i+=i&(-i);
    }
}

ll get(ll i,ll j)
{
    ll sum=0,k;
    while(i>0)
    {
        k=j;
        while(k>0)
        {
            sum+=t[i][k];
            k-=k&(-k);
        }
        i-=i&(-i);
    }
    return sum;
}

int main()
{
    cin>>n>>m>>q;
    FOR(i,1,n+1)
    {
        FOR(j,1,m+1)
        {
            cin>>x;
            put(i,j,x);
        }
    }
    FOR(i,0,q)
    {
        cin>>w;
        if(w==1)
        {
            cin>>x>>y>>z;
            put(x,y,z);
        }
        else
        {
            cin>>w>>x>>y>>z;
            cout<<get(y,z)-get(y,x-1)-get(w-1,z)+get(w-1,x-1)<<'\n';
        }
    }

    return 0;
}