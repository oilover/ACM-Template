const int M=1e6+7,N=1e5+8;  
int ch[M][26],fail[M];  
bool end[M];  
int pos[N],node[N];  
char str[M];  
int Size,root;  
int newnode() { memset(ch[Size],-1,sizeof ch[0]); end[Size++]=0; return Size-1; }  
void AC_init() { Size=0; root=newnode(); }  
void insert(char s[],int id)  
{  
    int n=strlen(s),u=root;  
    for(int i=0;i<n;i++)  
    {  
        int& tmp=ch[u][s[i]-'a'];  
        if(tmp==-1)tmp=newnode();  
        u=tmp;  
    }  
    end[u]=1;  
    node[id]=u;  
}  
void AC_build()  
{  
    queue<int> q;  
    for(int i=0;i<26;i++)  
    {  
        int& tmp=ch[root][i];  
        if(tmp==-1) tmp=root;  
        else { fail[tmp]=root; q.push(tmp); }  
    }  
    while(!q.empty())  
    {  
        int u=q.front(); q.pop();  
        for(int i=0;i<26;i++)  
        {  
            int& tmp=ch[u][i];  
            if(tmp==-1) tmp=ch[fail[u]][i];  
            else { fail[tmp]=ch[fail[u]][i]; q.push(tmp); }  
        }  
    }  
}  
int tmp[M];  
int query(int buf[],int len)  
{  
    for(int i=0;i<Size;i++) tmp[i]=end[i];  
    int res=0,u=root;  
    for(int i=0;i<len;i++)  
    {  
        u=ch[u][buf[i]-'a'];  
        for(int v=u;v!=root;v=fail[v])  
        {  
            res+=tmp[v];  
            tmp[v]=0;  
        }  
    }  
    return res;  
} 
