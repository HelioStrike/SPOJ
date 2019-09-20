#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 100010
#define M 10010
using namespace std;

ll n,x,fin,maxm,a[N],nc4[M],siev[M],primes[M];

ll solve(ll div,ll idx)
{
    ll res=0,cur=0;
    for(ll i=div;i<=maxm;i+=div) cur+=a[i];
    if(cur>=4)
    {
        res=nc4[cur];
        FOR(i,idx,fin)
        {
            if(div*primes[i]>maxm) break;
            res-=solve(div*primes[i],idx+1);
        }
    }
    return res;
}

int main()
{
    FOR(i,2,M)
    {
        if(siev[i]) continue;
        primes[fin++]=i;
        for(ll j=i*2;j<M;j++) siev[j]=1;
    }
    nc4[4]=1;
    FOR(i,5,M) nc4[i]=nc4[i-1]*i/(i-4);
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        FOR(i,0,n) cin>>x,a[x]++,maxm=max(maxm,x);
        cout<<solve(1,0)<<'\n';
    }

    return 0;
}