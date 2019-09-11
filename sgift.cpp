#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define MAX 1000000010
using namespace std;

ll n,q,x;
map<ll,ll> m;

void put(ll idx,ll val)
{
    while(idx<=MAX)
    {
        m[idx]+=val;
        idx+=idx&(-idx);
    }
}

ll get(ll idx)
{
    ll sum=0;
    while(idx>=1)
    {
        sum+=m[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

int main()
{
    cin>>n; FOR(i,0,n) cin>>x,put(x,x);
    cin>>q;
    FOR(i,0,q)
    {
        cin>>n>>x;
        cout<<get(x)-get(n-1)<<'\n';
    }

    return 0;
}