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

void update(int v, int tl, int tr, int pos)
{
    if(tl == tr) { t[v] = sqrt(t[v]); return;}
    int tm = (tl+tr)/2;
    if(pos < tm) update(v*2, tl, tm, pos);
    else update(v*2+1, tm+1, tr, pos);
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
    int n, c, l, r, q; cin >> n; FOR(i, 0, n) cin >> a[i];
    build(1, 0, n-1);

    //FOR(i, 0, 10) cout << t[i] << ' ';
    //cout << '\n';

    cin >> q;
    FOR(i, 0, q)
    {
        cin >> c >> l >> r; l--, r--;
        if(l>r) swap(l, r);
        if(c) cout << query(1, 0, n-1, l, r) << '\n';
        else FOR(j, l-1, r) update(1, 0, n-1, j);
    }
}