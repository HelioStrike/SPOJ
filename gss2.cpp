/* WA at 9th test case */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAX3(a,b,c) ((a)>(b))? (((a)>(c))?(a):(c)): (((b)>(c))?(b):(c))
#define ll long long
#define NEGINF -100010
#define MAXN 100010
using namespace std;


int a[MAXN], pre[2*MAXN];
ll t[4*MAXN], best[4*MAXN], best_lazy[4*MAXN], lazy[4*MAXN];

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return NEGINF;
    if(tl == l && tr == r) return best[v];
    int tm = (tl+tr)/2;
    return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update_children(int v)
{
    FOR(child, v*2, v*2+2)
    {
        best_lazy[child] = max(best_lazy[child], lazy[child]+best_lazy[v]);
        lazy[child] += lazy[v];
        best[child] = max(best[child], t[child]+best_lazy[v]);
        t[child] += lazy[v];
    }
    lazy[v] = best_lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r) return;
    if(tl == l && tr == r) 
    {
        best_lazy[v] = max(best_lazy[v], lazy[v] += val);
        best[v] = max(best[v], t[v] += val);
    }
    else
    {
        update_children(v);
        int tm = (tl + tr)/2;
        update(v*2, tl, tm, l, min(tm, r), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = max(t[v*2], t[v*2+1]);
        best[v] = max(best[v], t[v]);
    }
}

bool sortf(const pair< pair<int, int>, int >& a, const pair< pair<int, int>, int >& b) { return (a.first.second < b.first.second);}

int main()
{
    fill(pre, pre+2*MAXN, -1);

    int n, q, l, r, curr; cin >> n; FOR(i,0,n) cin >> a[i];

    vector< pair< pair<int, int>, int > > qs;
    cin >> q; ll ans[q];
    FOR(i,0,q) { cin >> l >> r; qs.push_back(pair< pair<int, int>, int> (make_pair(l-1, r-1), i));}
    sort(qs.begin(), qs.end(), sortf);

    curr = 0;
    FOR(i, 0, n) 
    { 
        update(1, 0, n-1, pre[a[i]+MAXN]+1, i, a[i]);
        
        //cout << query(1, 0, n-1, i, i) << ' ';

        pre[a[i]+MAXN] = i;
        while(qs[curr].first.second == i)
        {
            ans[qs[curr].second] = query(1, 0, n-1, qs[curr].first.first, qs[curr].first.second);
            curr++;
        }
    }
    //cout << '\n';

    FOR(i, 0, q) cout << ans[i] << '\n';

    return 0;
}