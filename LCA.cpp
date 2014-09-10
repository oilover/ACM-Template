#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
#define ll long long
#define ERR puts("=======here========");
#define prt(k) cout<<#k"="<<k<<" "
#include<algorithm>
const int N=200555;
int head[N],next[N],to[N],cost[N];
int tot;
void addedge(int u,int v,int w)
{
    to[++tot]=v;
    cost[tot]=w;
    next[tot]=head[u];
    head[u]=tot;
}
int n;
bool vis[N];
int dist[N],dp[N][20],h[N],dd[N],r[N];
int id;
void dfs(int u,int len,int dep)
{
    vis[u]=1;
    h[u]=id; dd[id]=dep; r[id++]=u;
    dist[u]=len;
    for(int i=head[u];i!=-1;i=next[i])
    {
        int v=to[i];
        if(!vis[v]) {
            dfs(v,len+cost[i],dep+1);
            r[id]=u;   dd[id++]=dep;
        }
    }
}
void RMQ(int n)
{
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++) {
        for(int i=1;i+(1<<j)-1<=n;i++) {
            if(dd[dp[i][j-1]]<dd[dp[i+(1<<(j-1))][j-1]])
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=dp[i+(1<<(j-1))][j-1];
        }
    }
}
#include<cmath>
int get_rmq(int a,int b)
{
    a=h[a];  b=h[b];
    if(a>b) swap(a,b);
    int k=log(b-a+1)/log(2);
    if(dd[dp[a][k]]<dd[dp[b-(1<<k)+1][k]])
        return dp[a][k];
    return dp[b-(1<<k)+1][k];
}
int main()
{
    bool line=0;
    while(cin>>n)
    {
        if(line) putchar(10);       line=1;
        tot=0;
        memset(head,-1,sizeof head);
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w); addedge(v,u,w);
        }
        id=1;
        memset(dist,0,sizeof dist);
        memset(vis,0,sizeof vis);
        dfs(0,0,0);
        RMQ(id);
        int q; cin>>q;
        while(q--)
        {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            int x=r[get_rmq(a,b)],y=r[get_rmq(b,c)],z=r[get_rmq(a,c)];
            int ans=dist[a]+dist[b]+dist[c]-dist[x]-dist[y]-dist[z];
            printf("%d\n",ans);
        }

    }
}
