#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 30010
using namespace std;

int t,n,p,ans,bit[N];
string s;
map<string,int> m;

void put(int idx)
{
    while(idx<=n)
    {
        bit[idx]++;
        idx+=idx&(-idx);
    }
}

int get(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=bit[idx];
        idx-=idx&(-idx);
    }
    return ret;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n; memset(bit,0,sizeof(bit));
        m.clear(); ans=n*(n-1)/2;
        FOR(i,1,n+1) cin>>s,m[s]=i;
        FOR(i,1,n+1)
        {
            cin>>s; p=m[s];
            ans-=get(p);
            put(p);
        }
        cout<<ans<<'\n';
    }

    return 0;
}