#include <bits/stdc++.h>
#define NEGINF -999999
using namespace std;

struct data { int sum, pref, suff, ans; };

data t[200001];
int a[50001];

data create(int val)
{
    data d;
    d.sum = val;
    d.pref = d.suff = d.ans = val;

    return d;
}

data combine(data l, data r)
{
    data comb;
    comb.sum = l.sum + r.sum;
    comb.pref = max(l.pref, l.sum + r.pref);
    comb.suff = max(r.suff, r.sum + l.suff);
    comb.ans = max(max(l.ans, r.ans), l.suff + r.pref);

    return comb;
}

void build(int v, int tl, int tr)
{
    if(tl == tr) { t[v] = create(a[tl]); return;}
    int tm = (tl + tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = combine(t[2*v], t[2*v+1]);
}

void modify(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr) { t[v] = create(val); return;}
    int tm = (tl + tr)/2;
    if(pos <= tm) modify(2*v, tl, tm, pos, val);
    else modify(2*v+1, tm+1, tr, pos, val);
    t[v] = combine(t[2*v], t[2*v+1]);
}

data query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return create(NEGINF);
    else if (tl == l && tr == r) return t[v];
    int tm = (tl + tr)/2;
    return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

int main()
{
    int n, q, c, l, r; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> c >> l >> r;
        if(c) cout << query(1, 0, n-1, l-1, r-1).ans << '\n';
        else modify(1, 0, n-1, l-1, r);
    }

    return 0;
}