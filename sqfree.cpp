#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define M 10000010
using namespace std;

ll t,n,x,k,fin,maxm,siev[M],primes[M];

ll solve(ll div,ll idx)
{
    if(idx==k) return n/(div*div);
    return solve(div,idx+1)-solve(div*primes[idx],idx+1);
}

int main()
{
    FOR(i,2,M)
    {
        if(siev[i]) continue;
        primes[fin++]=i;
        for(ll j=i*2;j<M;j+=i) siev[j]=1;
    }
    
    cin>>t;
    while(t--)
    {
        cin>>n; k=upper_bound(primes,primes+fin,ceil(sqrt(n)))-primes;
        cout<<solve(1,0)<<'\n';
    }

    return 0;
}