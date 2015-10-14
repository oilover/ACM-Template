const int N = 101000;  
int str[N],ans[N<<1];  
int p[N<<1],pos,how;  
int n;  
void manacher()  
{  
    pos=-1;how=0;  
    memset(p,0,sizeof(p));  
    int len=2*n+2;  
    int mid=-1,mx=-1;  
    for(int i=0;i<len;i++)  
    {  
        int j=-1;  
        if(i<mx)  
        {  
            j=2*mid-i;  
            p[i]=min(p[j],mx-i);  
        }  
        else p[i]=1;  
  
        while(i+p[i]<len&&ans[i+p[i]]==ans[i-p[i]])  
        {  
            p[i]++;  
        }  
  
        if(p[i]+i>mx)  
        {  
            mx=p[i]+i; mid=i;  
        }  
        if(p[i]>how)  
        {  
            how=p[i]; pos=i;  
        }  
    }  
}  
void pre()  
{  
    memset(ans,0,sizeof ans);  
    ans[0] = -1;  
    ans[1] = -2;  
    for (int i=0;i<n;i++) {  
        ans[2*i+2] = str[i];  
        ans[2*i+3] = -2;  
    }  
    ans[2*n+2] = 0;  
    manacher();  
    for (int i=3;i<2*n+2;i+=2) {  
        p[(i-3)/2] = (p[i] - 1) / 2;  
    }  
}  
