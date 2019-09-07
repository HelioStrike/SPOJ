#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 200010
using namespace std;

ll t,n,p,ans,a[N],b[N],c[N];

void put(ll idx,ll val)
{
    while(idx<=n)
    {
        b[idx]+=val;
        idx+=idx&(-idx);
    }
}

ll get(ll idx)
{
    ll sum=0;
    while(idx>=1)
    {
        sum+=b[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n; memset(b,0,sizeof(b)); ans=0;
        FOR(i,1,n+1) cin>>a[i],c[i]=a[i];
        sort(c+1,c+n+1);
        FOR(i,1,n+1)
        {
            p=lower_bound(c+1,c+n+1,a[i])-c;
            ans+=get(n)-get(p);
            put(p,1);
        }
        cout<<ans<<'\n';
    }

    return 0;
}