#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 200010
using namespace std;

int n;
string a,b;

vector<int> rk()
{
    int p=31,m=1e9+9;
    int s=b.length(),t=a.length();

    vector<ll> p_pow(max(s,t));
    p_pow[0]=1;
    for(int i=1;i<(int)p_pow.size();i++) p_pow[i]=(p_pow[i-1]*p)%m;

    vector<ll> h(t+1,0);
    for(int i=0;i<t;i++) h[i+1]=(h[i]+(a[i]-'a'+1)*p_pow[i])%m;

    ll h_s=0;
    for(int i=0;i<s;i++) h_s=(h_s+(b[i]-'a'+1)*p_pow[i])%m;

    vector<int> occ;
    for(int i=0;i+s-1<t;i++)
    {
        ll cur_h=(h[i+s]-h[i]+m)%m;
        if(cur_h==h_s*p_pow[i]%m) occ.push_back(i);
    }
    return occ;
}

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        vector<int> ans=rk();
        if(ans.size())
        {
            cout<<ans.size()<<'\n';
            for(int i:ans) cout<<i+1<<' ';
            cout<<'\n';
        }
        else cout<<"Not Found"<<'\n';
    }

    return 0;
}