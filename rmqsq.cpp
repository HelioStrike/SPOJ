#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 100010
using namespace std;

int n,q,x,y,k,a[N],st[N][20];

int main()
{
    cin>>n; FOR(i,0,n) cin>>a[i],st[i][0]=a[i];
    FOR(j,1,21) for(int i=0;i+(1<<j)<=n;i++) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    cin>>q;
    FOR(i,0,q)
    {
        cin>>x>>y; k=log2(y-x+1);
        cout<<min(st[x][k],st[y-(1<<k)+1][k])<<'\n';
    }

    return 0;
}