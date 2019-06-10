#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int nx[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

bool inLimit(int nc,int mc,int n,int m) { return (nc>=0 && mc>=0 && nc<n && mc<m); }

int main()
{
    int t,n,m,nc,mc,nl,ml,d; cin>>t;
    while(t--)
    {
        cin>>n>>m; nl=n,ml=m;
        int mapp[n][m],dist[n][m];
        queue<tuple<int,int,int>> q;

        FOR(i,0,n) FOR(j,0,m) {
            cin>>mapp[i][j],dist[i][j]=0;
            if(mapp[i][j]) q.push({i,j,0});
        }

        while(!q.empty())
        {
            tie(n,m,d)=q.front(); q.pop();
            FOR(i,0,4) 
            {
                nc=n+nx[i]; mc=m+mx[i];
                if(inLimit(nc,mc,nl,ml) && !mapp[nc][mc] && !dist[nc][mc]) dist[nc][mc]=d+1,q.push({nc,mc,d+1});
            }
        }

        FOR(i,0,nl) { FOR(j,0,ml) cout<<dist[i][j]<<' '; cout<<'\n'; }
    }

    return 0;
}