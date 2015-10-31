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
    for (int i=0;i<26;i++) {
        int &v = ch[0][i];
        if (v != -1) {
            q.push(v);
            fail[v] = 0;
        } else v = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i=0;i<26;i++) {
            int &v = ch[u][i];
            if (v==-1) {
                v = ch[fail[u]][i];
            } else {
                fail[v] = ch[fail[u]][i];
                q.push(v);
            }
        }
    }
}
int tmp[M];  
int query(char buf[],int len)  
{  
    for(int i=0;i<Size;i++) tmp[i]=end[i];  
    int res=0,u=root;  
    for(int i=0;i<len;i++)  
    {  
        u=ch[u][buf[i]-'a'];  
        for(int v=u;v!=root;v=fail[v])  
        {  
            res+=tmp[v];  
            tmp[v]=0;  /// 加上这句话，aaba中a出现了1次，不加就是出现了3次
        }  
    }  
    return res;  
} 
