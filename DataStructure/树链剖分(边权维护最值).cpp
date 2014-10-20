/**
树链剖分(边权维护最值)
树链剖分+线段树
维护两点建路径上的边权最大值。。。
SPOJ QTREE
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 100100;
#define prt(k) cout<<#k" = "<<k<<endl;
struct Edge
{
    int to, next;
}e[N<<2];
int head[N], Size;
void init_edge()
{
    memset(head, -1, sizeof head);
    Size = 0;
}
void addedge(int u, int v)
{
    e[Size] = (Edge) {v, head[u]};
    head[u] = Size++;
}
int siz[N], dep[N], fa[N], top[N], son[N], p[N];
/// fa 父节点 dep 深度 num 孩子数 son 重儿子
/// top[u] 它所在重链顶点 p[u]他与父亲连边在数据结构中位置 rp p的反
int n;

void dfs1(int u, int pre, int d)
{
    siz[u] = 1;
    fa[u] = pre;
    dep[u] = d;
    for(int i=head[u];~i;i=e[i].next)
    {
        int v = e[i].to;
        if(v == pre) continue;
        dfs1(v, u, d + 1);
        siz[u] += siz[v];
        if(son[u]==-1 || siz[son[u]] < siz[v])
            son[u] = v;
    }
}
int pos;
void getPOS(int u, int to)
{
    top[u] = to;
    p[u] = pos++;
    if(~son[u]) getPOS(son[u], to);
    for(int i=head[u];~i;i=e[i].next)
    {
        int v = e[i].to;
        if(v-fa[u] && v-son[u])
            getPOS(v, v);
    }
}
void init()
{
    memset(son, -1, sizeof son);
    init_edge();
    pos = 0;
}
/***********Tree*************/
int tree[N<<2];
#define ls o*2
#define rs o*2+1
#define lson l,m,ls
#define rson m+1,r,rs
void build(int l,int r,int o)
{
    tree[o] = 0;
    if(l==r) return ;
    int m = (l+r) /2;
    build(lson);
    build(rson);
}
void pushup(int o)
{
    tree[o] = max(tree[ls], tree[rs]);
}
void update(int pos, int val, int l=1, int r=n, int o=1)
{
    if(l==r)
    {
        if(l==pos) tree[o] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos<=m) update(pos, val, lson);
    else update(pos, val, rson);
    pushup(o);
}
int query(int L, int R, int l,int r, int o)
{
    if(L<=l && r<=R) return tree[o];
    int m = (l+r)/ 2;
    int res=0;
    if(L<=m) res=max(res, query(L,R,lson));
    if(m<R) res=max(res,query(L,R,rson));
    return res;
}
inline int query(int L, int R)
{
   // if(L>R) swap(L, R); if(L<1) L = 1;
    return query(L,R, 1,n,1);
}
/*********End Tree*************/
inline int find(int u, int v)
{
    int f1 = top[u], f2 = top[v], tmp = 0;
    while(f1 - f2)
    {
        if(dep[f1] < dep[f2])
            swap(f1, f2), swap(u,v);
        tmp = max(tmp, query(p[f1], p[u]));
        u = fa[f1]; f1 = top[u];
      //  cout<<u<<endl;
    }
    if(u==v) return tmp;
    if(dep[u] > dep[v]) swap(u, v);
    return max(tmp, query(p[son[u]], p[v]));
}
int edge[N][3];
inline void read(int &a)
{
    char c = 0;
    while(!isdigit(c)) c=getchar();
    a = 0;
    while(isdigit(c)) a = a * 10 + c - '0', c = getchar();
}
void show(int l ,int r, int o)
{
    printf("[%d, %d] : tree[%d] = %d\n", l, r, o, tree[o]);
    if(l==r) return;
    int  m = (l+r) / 2;
    show(lson);
    show(rson);
    if(o==1) putchar(10);
}
int main()
{
   // int a,b; read(a); read(b); cout<<a<<' '<<b<<endl;
   // freopen("qtree.in", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n); n--;
        init();
        for(int i=1;i<=n;i++) {
            int a,b,c;
            read(a); read(b); read(c);
          //  scanf("%d%d%d", &a, &b, &c);
            edge[i][0]=a, edge[i][1]=b, edge[i][2]=c;
            addedge(a,b);
            addedge(b,a);
        }
        dfs1(1, 1, 0);
        getPOS(1, 1);
        build(1, n, 1);
        for(int i=1;i<=n;i++)
        {
            if(dep[edge[i][0]] > dep[edge[i][1]])
                swap(edge[i][0], edge[i][1]);
           // cout<<p[edge[i][1]]<< ' '<< edge[i][1]<<endl;
            update(p[edge[i][1]], edge[i][2]);
           // prt(p[edge[i][1]]); prt(edge[i][2]);
        }
        char op[11];
        while(scanf("%s", op)==1)
        {
            if(op[0]=='Q')
            {
                int a, b;
                //scanf("%d%d", &a, &b);
                read(a); read(b);
               // show(1, n, 1);
                printf("%d\n", find(a,b));
            }
            else if(op[0]=='C')
            {
                int a,b;
                //scanf("%d%d", &a, &b);
                read(a); read(b);
                update(p[edge[a][1]], b, 1, n, 1);
               // show(1, n, 1);
            }
            else if(op[0]=='D')
            {
                putchar(10);
                break;
            }
        }
    }
    return 0;
}
