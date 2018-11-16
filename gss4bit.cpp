/* Binary Indexex Tree implementation */
/* gives TLE */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define MAXN 100010
using namespace std;

ll t[MAXN];
int a[MAXN];

void update(int idx, int delta, int n)
{
    for(; idx < n; idx = idx|(idx+1)) t[idx] += delta;
}

ll sum(int r)
{
    ll tot = 0;
    for(; r >= 0; r = (r&(r+1))-1) tot += t[r];
    return tot;
}

ll query(int l, int r) { return sum(r) - sum(l-1);}

int main()
{
    int n, c, cc=0, l, r, q;
    
    while(scanf("%d", &n) != EOF)
    {
        printf("Case #%d:\n", ++cc);
        memset(t, 0, n*sizeof(ll));
        FOR(i, 0, n) scanf("%d", &a[i]), update(i, a[i], n);

        scanf("%d", &q);
        FOR(i, 0, q)
        {
            scanf("%d%d%d", &c, &l, &r); l--,r--;
            if(l>r) swap(l, r);
            if(c) printf("%lli\n", query(l, r));
            else FOR(j, l, r+1) if(a[j]>1) c = sqrt(a[j]), update(j, c-a[j], n), a[j] = c;
        }
        printf("\n");
    }
}