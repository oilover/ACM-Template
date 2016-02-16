const int MAXN = 233;
vector<int> g[MAXN];
int n, ans, m, tot, from[MAXN];
bool use[MAXN];
bool match(int x) {
    for (int v: g[x]) 
        if (!use[v]) {
            use[v] = true;
            if (from[v] == -1 || match(from[v])) {
                from[v] = x;
                return true;
            }
        }
    return false;
}
int solve()
{
    int tot = 0;
    memset(from, -1, sizeof from);
    for (int i=1;i<=n;i++) {
        memset(use, false, sizeof use);
        if (match(i)) ++ tot;
    }
    return tot;
}
