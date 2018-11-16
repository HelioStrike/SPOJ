/*Segment Tree implementation */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define MAXN 100010
using namespace std;

ll a[MAXN];
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
    list<int> nexti;
    list<int>::iterator it;
    
    while(scanf("%d", &n) != EOF)
    {
        nexti.clear();
        printf("Case #%d:\n", ++cc);
        memset(t, 0, 4*n*sizeof(int));
        FOR(i, 0, n) { scanf("%lli", &a[i]); if(a[i] > 1) nexti.push_back(i);}
        build(1, 0, n-1);

        scanf("%d", &q);
        FOR(i, 0, q)
        {
            scanf("%d%d%d", &c, &l, &r); l--,r--;
            if(l>r) swap(l, r);
            if(c) printf("%lli\n", query(1, 0, n-1, l, r));
            else
            {
                for(it = lower_bound(nexti.begin(), nexti.end(), l); it != nexti.end() && (*it) <= r;)
                {
                    update(1, 0, n-1, *it, a[*it]=sqrt(a[*it]));
                    if(a[*it] == 1) it = nexti.erase(it);
                    else it++;
                }
            }
 
        }
        printf("\n");
    }
}