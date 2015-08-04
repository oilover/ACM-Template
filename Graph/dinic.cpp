struct Node
{
    int u , v, w;
} e[M];
struct data
{
    int to, cap, rev;
} ;
vector<data> G[N];
int level[N];
int iter[N];
void addedge(int from,int to, int cap=1)
{
    G[from].push_back((data){to, cap, G[to].size()});
    G[to].push_back((data){from, 0, G[from].size()-1});
}
void BFS(int s)
{
    memset(level, -1, sizeof level);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int v = que.front(); que.pop();
        for (data e : G[v])
        {
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v, int t, int f)
{
    if (v==t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++)
    {
        data &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t)
{
    int flow = 0;
    for (;; ) {
        BFS(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, inf)) > 0) {
            flow += f;
        }
    }
}
