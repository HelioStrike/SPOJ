#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 1000010
using namespace std;

ll n,phi[N],res[N];

int main()
{
    FOR(i,1,N) phi[i]=i;
    FOR(i,2,N)
    {
        if(phi[i]==i)
        {
            for(ll j=i;j<N;j+=i) phi[j]=phi[j]*(i-1)/i;
        }
    }
    FOR(i,1,N)
    {
        for(ll j=2*i;j<N;j+=i) res[j]+=i*phi[j/i];
    }
    FOR(i,2,N) res[i]+=res[i-1];
    while(cin>>n)
    {
        if(n==0) break;
        cout<<res[n]<<'\n';
    }
}