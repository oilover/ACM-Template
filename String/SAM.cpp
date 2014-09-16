#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define prt(k) cout<<#k"="<<k<<" ";

/**Suffix Automaton*/
const int Char=26,N=600022;
struct SAM_Node
{
    SAM_Node *fa,*ch[Char];
    int len,id,pos;
    SAM_Node() {}
    SAM_Node(int _len)
    {
        fa=0; len=_len;
        memset(ch,0,sizeof ch);
    }
}pool[N],*root,*last,*tail;   ///tail
int SAM_size;
#define sam pool
#define node SAM_Node
SAM_Node *newnode(int len)
{
    pool[SAM_size]=node(len);
    pool[SAM_size].id=SAM_size;
    return &pool[SAM_size++];
}
node *newnode(node *p)
{
    pool[SAM_size]=*p;
    pool[SAM_size].id=SAM_size;
    return &pool[SAM_size++];
}
void SAM_init()
{
    SAM_size=0;
    root=last=newnode(0);
    pool[0].pos=0;
}
void add(int x,int len)
{
    node *p=last,*np=newnode(p->len+1);
    np->pos=len; last=np;
    for(;p&&!p->ch[x];p=p->fa) p->ch[x]=np;
    if(!p) { np->fa=root;return ; }
    node *q=p->ch[x];
    if(q->len==p->len+1) { np->fa=q;return; }
    node *nq=newnode(q);
    nq->len=p->len+1;
    q->fa=nq; np->fa=nq;
    for(;p&&p->ch[x]==q;p=p->fa) p->ch[x]=nq;
}
void SAM_build(char *s)
{
    SAM_init();
    int len=strlen(s);
    for(int i=0;i<len;i++) add(s[i]-'a',i+1);
}
void Max(int &a,int b) { a=max(a,b); }
void Min(int &a,int b) { a=min(a,b); }
int c[N]; int L[N],R[N],num[N];
node *top[N];
char s[N];
#define inf 0x3f3f3f3f
void gao(int len)
{
    memset(c,0,sizeof c);
    memset(top,0,sizeof top);
    for(int i=0;i<SAM_size;i++) c[sam[i].len]++;
    for(int i=1;i<=len;i++) c[i]+=c[i-1];
    for(int i=0;i<SAM_size;i++) top[--c[sam[i].len]]=&sam[i];
    memset(L,63,sizeof L);
    memset(R,0,sizeof R);
    memset(num,0,sizeof num);
    for( node *p=root;;p=p->ch[s[p->len]-'a'])
    {
        num[p->id]=1;
        L[p->id]=R[p->id]=p->pos;
        if(p->len==len) break;
    }
    for(int i=SAM_size-1;i>=0;i--)
    {
        node *p=top[i];
        if(L[p->id]==inf&&R[p->id]==0)
        {
            L[p->id]=R[p->id]=p->pos;
        }
        if(p->fa) {
            node *q=p->fa;
            Min(L[q->id],L[p->id]);
            Max(R[q->id],R[p->id]);
            num[q->id]+=num[p->id];
        }
    }
    ll ans=0;
    for(int i=1;i<SAM_size;i++)
    {
        if(num[sam[i].id]<=1) continue;
        int ma=sam[i].len;
        int mi=sam[i].fa->len+1;
        int _len=R[sam[i].id]-L[sam[i].id];
        if(_len>=ma) ans+=ma-mi+1;
        else if(_len<ma&&_len>=mi) ans+=_len-mi+1;
    }
    printf("%I64d\n",ans);
}

int main()
{
    while(scanf("%s",s)==1&&s[0]!='#')
    {
        SAM_build(s);
        gao(strlen(s));
    }
}
