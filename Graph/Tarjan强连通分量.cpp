int scc,dfn[2*N],low[2*N],cur;  
#include<stack>  
stack<int> s;  
int ins[N];  
void dfs(int u)  
{  
    dfn[u]=low[u]=++cur;  
    s.push(u);  
    ins[u]=1;  
    for(int i=0;i<g[u].size();i++)  
    {  
        int v=g[u][i];  
        if(!dfn[v])  
        {  
            dfs(v);  
            low[u]=min(low[u],low[v]);  
        }else{  
            if(ins[v])  
                low[u]=min(low[u],dfn[v]);  
        }  
    }  
    if(low[u]==dfn[u])  
    {  
        ++scc;  int v;  
        do {  
            v=s.top(); s.pop();  
            ins[v]=0;  
            fa[v]=scc;  
        }while(v!=u);  
    }  
}  
