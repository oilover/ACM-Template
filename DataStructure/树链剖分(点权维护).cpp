/**
树链剖分(点权维护)
树链剖分+树状数组 维护路径上的点/边
HDOJ3966
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 50010<<2;
struct Edge
{
    int to, next;
}edge[N<<2];
int head[N], tot;
void addedge(int u, int v)
{
    edge[tot] = (Edge) {v, head[u]};
    head[u] = tot++;
}
void init_edge()
{
    memset(head, -1, sizeof head);
    tot = 0;
}
/// fa 父节点 dep 深度 num 孩子数 son 重儿子
/// top[u] 它所在重链顶端节点 p[u]在数据结构中位置 rp p的反
int fa[N], dep[N], top[N], num[N];
int son[N], p[N];
int pos;
void init()
{
    init_edge();
    pos = 1;
    memset(son, -1, sizeof son);
}
void dfs(int u, int pre=-1, int d=0)
{
    dep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==pre) continue;
        dfs(v, u, d+1);
        num[u] += num[v];
        if(son[u]==-1||num[son[u]] < num[v])
            son[u] = v;
    }
}

void getpos(int u, int to=1)
{
    top[u] = to;
    p[u] = pos++;
    if(~son[u]) getpos(son[u], to);
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v-son[u] && v-fa[u])
            getpos(v, v);
    }
}

inline int read(int &a)
{
    char ch = 0;
    while(!isdigit(ch)&&~ch) ch = getchar();
    a = 0;
    while(isdigit(ch)&&~ch) a = a * 10 + ch - '0', ch = getchar();
    return ~ch ? 0: -1;
}
int n, m, Q;
/******Bit Index Tree************/
int tree[N<<2];
int a[N];
int b[N];
inline int low(int x) { return x & -x; }
void add(int i, int x)
{
    for(;i<=n;i+=low(i)) tree[i]+=x;
}
int sum(int p)
{
    int res = 0;
    for(int i=p;i>0;i-=low(i)) res+=tree[i];
    return res;
}
/**********End Tree**********/
inline int Change(int u, int v, int val)
{
    int f1 = top[u], f2 = top[v];
    int tmp = 0;
    while(f1 - f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(f1 ,f2);
            swap(u, v);
        }
        add(p[f1], val);
        add(p[u]+1, -val);
        u = fa[f1];
        f1 = top[u];
    }
    if(dep[u] > dep[v]) swap(u, v);
    add(p[u], val);
    add(p[v]+1, -val);
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &Q)==3)
    {
        init();
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=0;i<m;i++)
        {
            int u,v;
            read(u); read(v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1);
        getpos(1, 1);
        memset(tree, 0, sizeof tree);
        for(int i=1;i<=n;i++)
        {
            add(p[i], a[i]);
            add(p[i]+1, -a[i]);
        }
        while(Q--)
        {
            char op[22]; scanf("%s", op);
            int u, v, val;
            if(op[0]=='I'||op[0]=='D')
            {
                read(u); read(v); read(val);
                if(op[0]=='D') val = -val;
                Change(u, v, val);
            }
            else if(op[0]=='Q')
            {
                read(u);
                printf("%d\n", sum(p[u]));
            }
        }
    }
    return 0;
}
