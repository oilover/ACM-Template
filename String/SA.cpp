#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define prt(k) cout<<#k"="<<k<<" ";
#define inf 0x3f3f3f3f
const int N=1000022;
#define rank Rank
int sa[N],rank[N],rank2[N],h[N],*y,*x,c[N];
char str[N];
bool cmp(int* r,int a,int b,int l,int n)
{
    return (r[a]==r[b]&&a+l<n&&b+l<n&&r[a+l]==r[b+l]);
}
void radix_sort(int n,int sz)
{
    for(int i=0;i<sz;i++) c[i]=0;
    for(int i=0;i<n;i++) c[x[y[i]]]++;
    for(int i=1;i<sz;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
}
void get_sa(char s[],int n,int sz=128)
{
    x=rank,y=rank2;
    for(int i=0;i<n;i++) x[i]=s[i],y[i]=i;
    radix_sort(n,sz);
    for(int len=1;len<n;len<<=1)
    {
        int yid=0;
        for(int i=n-len;i<n;i++) y[yid++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=len) y[yid++]=sa[i]-len;

        radix_sort(n,sz);

        swap(x,y);
        x[sa[0]]=yid=0;

        for(int i=1;i<n;i++)
        {
            x[sa[i]]=cmp(y,sa[i],sa[i-1],len,n)?yid:++yid;
        }

        sz=yid+1;
        if(sz>=n) break;
    }
    for(int i=0;i<n;i++) rank[i]=x[i];
}
void get_h(char* s,int n)
{
    int k=0;  h[0]=inf;
    for(int i=0;i<n;i++)
    {
        if(rank[i]==0) continue;
        k=max(0,k-1);
        int j=sa[rank[i]-1];
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
        h[rank[i]]=k;
    }
}
int n,m;
int len;
bool judge(int L)
{
    int len=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(h[i]>=L) cnt++;
        else  len=max(len,cnt),cnt=1;
    }
    return(len>=m)  ;
}
int gao(int L)
{
    int ret=-1,cnt=1,tt=sa[0];
    for(int i=1;i<=n;i++)
    {
        if(h[i]>=L)
        {
            cnt++;
            tt=max(sa[i],tt);
        }
        else
        {
            if(cnt>=m)   ret=max(ret,tt);
            cnt=1;tt=sa[i];
        }
    }
    return ret;
}
void init()
{
    memset(sa,0,sizeof(sa));
    memset(rank,0,sizeof(rank));
    memset(rank2,0,sizeof(rank2));
    memset(h,0,sizeof(h));
    memset(c,0,sizeof(c));
}
int main()
{
    int re; //scanf("%d",&re);
    while(scanf("%d",&m)==1,m)
    {
        init();
        scanf("%s",str);
        n=strlen(str);
        get_sa(str,n);
        get_h(str,n);
       // for(int i=1;i<=n;i++) printf("%4d",h[i]); putchar(10);
        int l=1,r=n;  int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(judge(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        if(ans==-1) { puts("none"); continue; }
        printf("%d %d\n",ans,m==1?0:gao(ans));
    }
}
