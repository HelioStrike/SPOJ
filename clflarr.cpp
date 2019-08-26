#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 200010
using namespace std;

int n,q,l,r,c,a[N],p[N],qs[N][3];

int f(int x) { return x==p[x]?x:p[x]=f(p[x]); }

int main()
{
    cin>>n>>q;
    FOR(i,1,n+2) p[i]=i; 
    FOR(i,0,q) cin>>qs[i][0]>>qs[i][1]>>qs[i][2];
    for(int i=q-1;i>=0;i--)
    {
        l=qs[i][0];
        r=qs[i][1];
        c=qs[i][2];
        for(int j=f(l);j<=r;j=f(j)) { a[j]=c,p[j]=j+1; }
    }
    FOR(i,1,n+1) cout<<a[i]<<'\n';

    return 0;
}