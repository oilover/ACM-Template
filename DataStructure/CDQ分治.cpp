#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define prt(k) cerr<<#k<<" = "<<k<<endl
const int MAXN = 400005;
struct Node
{
    int x1, x2, y, f, idx;  // idx = 0 表示修改，否则表示第几个询问
    Node() {}
    Node(int x1,int x2,int y,int f,int idx):
        x1(x1),x2(x2),y(y),f(f),idx(idx){}
    bool operator < (Node a) const
    {
        if (y - a.y) return y < a.y;
        return idx < a.idx;
    }
};
Node q[MAXN], s1[MAXN], s2[MAXN];
int n, m, a[MAXN ], cnt, T[MAXN], ans[MAXN], Query;
map<int, int> ID;
void LiSan()
{
    sort(a+1, a+cnt+1); int n = cnt;
    int cnt = 1;
    for (int i=2;i<=n;i++) if (a[i]!=a[cnt]) a[++cnt] = a[i];
}
int Hash(int x) { return lower_bound(a+1, a+cnt+1, x) - a; }
int low(int x) { return x & -x; }
void add(int x, int v)
{   for (int i=x;i<cnt;i+=low(i)) T[i]+=v;   }
int sum(int x)
{  int r = 0; for (int i=x;i>0;i-=low(i)) r += T[i]; return r; }
void CDQ(int l, int r)
{
    if (l >= r) return ;
    int m = (l +  r) / 2, top1 = 0, top2 = 0, j = 0;
    CDQ(l ,m); CDQ(m+1, r);
    for (int i=m+1;i<=r;i++) if (q[i].idx != 0)  //询问操作
        s1[top1++] = q[i];
    for (int i=l;i<=m;i++) if (q[i].idx == 0) //修改操作
        s2[top2++] = q[i];
    sort(s1, s1 + top1);
    sort(s2, s2 + top2);
    for (int i=0;i<top1;i++) {
        while (j<top2 && s2[j].y <= s1[i].y) {
            add(s2[j].x1, s2[j].f);
            ++ j;
        }
        ans[s1[i].idx] += s1[i].f * sum(s1[i].x2);
        ans[s1[i].idx] -= s1[i].f * sum(s1[i].x1 - 1);
    }
    for (int i=0;i<j;i++)
        add(s2[i].x1, -s2[i].f);
}
void solve(int cas = 1)
{
    memset(T,0,sizeof T);
    memset(ans, 0 , sizeof ans);
    int op, x1,y1,x2,y2, x, y, w;
    m = cnt = Query = 0;
    while (true) {
        scanf("%d", &op);
        if (op == 3) break;
        if (op == 1) {  //单点增加w
            scanf("%d%d%d", &x, &y, &w);
            q[++m] = Node(x , x, y, w, 0);
            a[++cnt] = x;
        }
        else {   //查询矩形的和
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            q[++m] = Node(x1, x2,     y2,  1, ++Query);
            q[++m] = Node(x1, x2, y1 - 1, -1, Query);
            a[++cnt] = x2;
            a[++cnt] = x1 - 1;
 
        }
    }
    LiSan();
    for (int i=1;i<=m;i++) {
        if (q[i].idx == 0) q[i].x1 = Hash(q[i].x1);
        else {
            q[i].x1 = Hash(q[i].x1 - 1) + 1;
            q[i].x2 = Hash(q[i].x2);
        }
    }
    CDQ(1, m);
    for (int i=1;i<=Query;i++) printf("%d\n", ans[i]);
}
int main()
{
    freopen("mokia.in","r",stdin); freopen("mokia.out","w",stdout);
    int cas = 0;
    while (~scanf("%*d%d", &n)) solve(++cas);
}
