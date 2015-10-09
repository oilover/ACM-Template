///#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
//typedef long long LL;
/// 树分治， POJ 1741 求距离不超过 K 的顶点对数
/// 见《挑战程序设计竞赛》363页
const int INF = 0x3f3f3f3f;
const int MAXN = 10005;
typedef pair<int, int> P;
struct edge { int to; int length; };
int n; int  K;
vector<edge> G[MAXN];
bool centroid[MAXN];
int subtree_size[MAXN];
int ans;
int compute_subtree_size(int u, int p)
{
    int c = 1;
    for (int i=0;i<G[u].size();i++) {
        int v = G[u][i].to;
        if (v == p || centroid[v]) continue;
        c += compute_subtree_size(v, u);
    }
    return subtree_size[u] = c;
}
P search_centroid(int v, int p, int t)
{
    P res = P(INF, -1);
    int s = 1, m = 0;
    for (int i=0;i<G[v].size();i++) {
        int w = G[v][i].to;
        if (w==p || centroid[w]) continue;
        res = min(res, search_centroid(w, v, t));
        m = max(m, subtree_size[w]);
        s += subtree_size[w];
    }
    m = max(m, t - s);
    res = min(res, P(m, v));
    return res;
}
void enumerate_paths(int v, int p, int d, vector<int> &ds)
{
    ds.push_back(d);
    for (int i=0;i<G[v].size();i++) {
        int w = G[v][i].to;
        if (w==p || centroid[w]) continue;
        enumerate_paths(w, v, d + G[v][i].length, ds);
    }
}
int count_pairs(vector<int> &ds)
{
    int res = 0;
    sort(ds.begin(), ds.end());
    int j = ds.size();
    for (int i=0;i<ds.size();i++) {
        while (j > 0 && ds[i] + ds[j-1] > K) j--;
        res += j - (j > i ? 1 : 0);
    }
    return res / 2;
}
void solve_subproblem(int v)
{
    compute_subtree_size(v, -1);
    int s = search_centroid(v, -1, subtree_size[v]).second;
    centroid[s] = true;
    for (int i=0;i<G[s].size();i++) {
        int w = G[s][i].to;
        if (centroid[w]) continue;
        solve_subproblem(w);
    }
    vector<int> ds;
    ds.push_back(0);
    for (int i=0;i<G[s].size();i++) {
        int w = G[s][i].to;
        if (centroid[w]) continue;
        vector<int> tds;
        enumerate_paths(w, s, G[s][i].length, tds);
        ans -= count_pairs(tds);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }
    ans += count_pairs(ds);
    centroid[s] = false;
}
void solve()
{
    ans = 0;
    for (int i=1;i<=n;i++) centroid[i] = false;
    solve_subproblem(1);
    printf("%d\n", ans);
}
int main()
{
    while (scanf("%d%d", &n, &K) == 2 && n) {
        for (int i=1;i<=n;i++) G[i].clear();
        for (int i=1;i<n;i++) {
            int u,v ; int w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back((edge){v, w});
            G[v].push_back((edge){u, w});
        }
        solve();
    }
    return 0;
}
