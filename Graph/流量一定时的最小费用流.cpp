const int MAXN = 20010;///点数的最大值
const int MAXM = 400010;///边数的最大值
const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;
///流量一定时的最小费用流，见挑战程序设计竞赛226页。
int N, M;
struct Edge
{
    int to, cap, cost, rev;
    Edge() {}
    Edge(int to, int cap, int cost, int rev):to(to),cap(cap),cost(cost),rev(rev){}
};
vector<Edge> G[MAXN];
int h[MAXN], dist[MAXN], Prev[MAXN], pree[MAXN];
void init()
{
    for (int i=0;i<=N+N;i++) G[i].clear();
}
void adde(int from, int to, int cap, int cost)
{
    G[from].push_back(Edge(to,cap,cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}
///求解从s到t流量为f的最小费用流
///如果没有，返回-1
int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    memset(h, 0, sizeof h);
    while (f > 0) {
        priority_queue<P, vector<P>, greater<P> > Q;
        memset(dist,63,sizeof dist);
        dist[s] = 0;
        Q.push(P(0,s));
        while (!Q.empty()) {
            P p = Q.top(); Q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i=0;i<G[v].size();i++) {
                Edge e = G[v][i]; int u = e.to;
                if (e.cap>0 && dist[u] > dist[v] + e.cost + h[v] - h[u]) {
                    dist[u] = dist[v] + e.cost + h[v] - h[u];
                    Prev[u] = v;
                    pree[u] = i;
                    Q.push(P(dist[u], u));
                }
            }
        }
        if (dist[t] == INF) return -1;
        for (int v=0;v<=N;v++) h[v] += dist[v];
        int d = f;
        for (int v=t;v!=s;v=Prev[v]) d = min(d, G[Prev[v]][pree[v]].cap);
        f -= d;
        res += d * h[t];
        for (int v=t;v!=s;v=Prev[v]) {
            Edge &e = G[Prev[v]][pree[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}
