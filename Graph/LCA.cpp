#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define prt(k) cout<<#k" = "<<k<<endl;
typedef long long ll;
const int N = 100005;
int n, m, head[N], mm;
struct Edge {
    int to, next;
}e[N << 1];
void add(int u, int v)
{
    e[mm].to = v;
    e[mm].next = head[u];
    head[u] = mm++;
}
int sz[N], dep[N];
int f[N][22];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    sz[u] = 1;
    for (int i=head[u];~i;i=e[i].next)
    {
        int v = e[i].to;
        if (v != fa)
        {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int maxh;
void gao()
{
    int j;
    for (j=1;(1<<j)<n;j++)
        for (int i=1;i<=n;i++)
        f[i][j] = f[f[i][j-1]][j-1];
    maxh = j - 1;
}
int swim(int x, int k)
{
    for (int i=0;i<=maxh;i++)
        if (k >> i & 1)
        x = f[x][i];
    return x;
}
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y); ///dep[x] <= dep[y];
    y = swim(y, dep[y] - dep[x]);
    if (x == y) return y;
    for (int i=maxh; i>=0; i--) {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
