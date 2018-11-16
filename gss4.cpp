/*Segment Tree implementation *.
/* gives TLE */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define MAXN 100010
using namespace std;

int a[MAXN];
ll t[4*MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr) { t[v] = a[tl]; return;}
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr) { t[v] = val; return;}
    int tm = (tl+tr)/2;
    if(pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2+1, tm+1, tr, pos, val);
    t[v] = t[v*2]+t[v*2+1];
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl == l && tr == r) return t[v];
    int tm = (tl+tr)/2;
    return (query(v*2, tl, tm, l, min(tm, r))+query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main()
{
    int n, c, cc=0, l, r, q;
    
    while(scanf("%d", &n) != EOF)
    {
        printf("Case #%d:\n", ++cc);
        memset(t, 0, 4*n*sizeof(int));
        FOR(i, 0, n) scanf("%d", &a[i]);
        build(1, 0, n-1);

        scanf("%d", &q);
        FOR(i, 0, q)
        {
            //cout << query(1,0,n-1,0,n-1) << '\n';
            //FOR(j, 0, n) cout << a[j] << ' ';
            //cout << '\n';

            scanf("%d%d%d", &c, &l, &r); l--,r--;
            if(l>r) swap(l, r);
            if(c) printf("%lli\n", query(1, 0, n-1, l, r));
            else FOR(j, l, r+1) if(a[j]>1) update(1, 0, n-1, j, a[j]=sqrt(a[j]));
        }
        printf("\n");
    }
}