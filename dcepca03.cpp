#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 10010
using namespace std;

ll t,n,p[N];

int main()
{
    FOR(i,1,N) p[i]=i;
    FOR(i,2,N)
    {
        if(p[i]==i)
        {
            for(ll j=i;j<N;j+=i) p[j]-=p[j]/i;
        }
    }
    FOR(i,2,N) p[i]+=p[i-1];

    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<p[n]*p[n]<<'\n';
    }

    return 0;
}