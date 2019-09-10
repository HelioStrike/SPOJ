#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 100010
#define SZ 31
using namespace std;

ll n,q,x,a,b,c,os,zs,ans,d[N],t[SZ][N];
string s;

void put(ll i,ll idx,ll val)
{
    while(idx<=n)
    {
        t[i][idx]+=val;
        idx+=idx&(-idx);
    }
}

ll get(ll i,ll idx)
{
    ll sum=0;
    while(idx>=1)
    {
        sum+=t[i][idx];
        idx-=idx&(-idx);
    }
    return sum;
}

int main()
{
    cin>>n>>q;
    FOR(i,1,n+1)
    {
        cin>>d[i]; x=d[i]; c=0;
        while(x) 
        {
            if(x&1) put(c,i,x&1);
            x>>=1; c++;
        }
    }
    FOR(i,0,q)
    {
        cin>>c;
        if(c==1)
        {
            cin>>a>>b;
            x=d[b]; c=0;
            while(x) 
            {
                if(x&1) put(c,b,-1);
                x>>=1; c++;
            }
            d[b]=a;
            x=d[b]; c=0;
            while(x) 
            {
                if(x&1) put(c,b,x&1);
                x>>=1; c++;
            }
        }
        else
        {
            cin>>s>>a>>b; ans=0;
            FOR(i,0,SZ)
            {
                os=get(i,b)-get(i,a-1);
                zs=b-a+1-os;
                if(s=="OR")
                {
                    ans+=(1<<i)*(os*zs+os*(os-1)/2);
                }
                else if(s=="XOR")
                {
                    ans+=(1<<i)*(os*zs);
                }
                else
                {
                    ans+=(1<<i)*(os*(os-1)/2);
                }
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}