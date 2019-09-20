#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 16
using namespace std;

ll n,k,a[N];

ll rec(ll idx,ll div)
{
    if(idx==k) return n/div;
    return rec(idx+1,div)-rec(idx+1,div*a[idx]/__gcd(div,a[idx]));
}

int main()
{
    cin>>n>>k; FOR(i,0,k) cin>>a[i];
    cout<<rec(0,1)<<'\n';

    return 0;
}