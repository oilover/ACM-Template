
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
int dp[maxn][20],Log[maxn];  
  
void RMQ_init(int n)  
{  
    for(int i=0;i<n;i++) dp[i][0]=h[i];  
    for(int i=1;(1<<i)<=n;i++)  
    {  
        for(int j=0;j+(1<<i)-1<n;j++)  
        {  
            dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);  
        }  
    }  
}  
  
int LCP(int l,int r,int n)  
{  
    if(l==r) return n-sa[l];  
    l++;  
    if(l>r) swap(l,r);  
    int k = 0;  
    while(1<<(k+1) <= r-l+1) k++;  
    return min(dp[l][k],dp[r-(1<<k)+1][k]);  
}  
  
int main()  
{  
    int cas=1;  
    while(scanf("%s",str)!=EOF&&str[0]!='#')  
    {  
        int n=strlen(str);  
  
        get_sa(str,n);  
        get_h(str,n);  
        RMQ_init(n);  
    }
    return 0;
}
