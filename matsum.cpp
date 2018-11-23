/* WA */
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define MAXN 1030
using namespace std;

int bit[MAXN][MAXN];
int mat[MAXN][MAXN];

int sum(int x, int y)
{
    int ret = 0;
    for(int i = x; i >= 0; i=(i&(i+1))-1)
    {
        for(int j = y; j >= 0; j=(j&(j+1))-1)
        {
            ret += bit[i][j];
        }
    }
    return ret;
}

void update(int x, int y, int n, int m, int delta)
{
    for(int i = x; i < n; i=i|(i+1))
    {
        for(int j = y; j < m; j=j|(j+1))
        {
            bit[i][j] += delta;
        }
    }
}

int query(int x1, int y1, int x2, int y2)
{
    return (sum(x2, y2) - sum(x1-1, y1-1));
}

int main()
{
    int c, n, x1, y1, x2, y2; scanf("%d", &c);
    char com[30];
    while(c--)
    {
        scanf("%d", &n);
        memset(bit, 0, sizeof(bit));
        memset(mat, 0, sizeof(mat));
        while(scanf("%s", com))
        {
            if(!strcmp(com, "END")) break;
            scanf("%d%d%d",&x1,&y1,&x2);
            if(!strcmp(com, "SET")) update(x1, y1, n, n, x2-mat[x1][y1]), mat[x1][y1]=x2;
            else if(!strcmp(com, "SUM")) scanf("%d", &y2), printf("%d\n", query(x1, y1, x2, y2));
            else break;
        }
        printf("\n");
    }
}