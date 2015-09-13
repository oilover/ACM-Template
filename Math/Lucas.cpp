///Lucas(n, m, p)=c[n%p][m%p]*lucas(n/p, m/p, p);  组合数取模 p<10^5
ll fac[100100];  
void get_fac(ll p)  
{  
    fac[0]=1;  
    for(int i=1;i<=p+10;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}   
ll C(ll n,ll m,ll fac[],ll mod)  
{  
    if(n<m) return 0;  
    return fac[n] * inv(fac[n-m]*fac[m], mod)%mod;  
}  
ll Lucas(ll n,ll m,ll fac[],ll mod)  
{  
    if(m==0) return 1;  ll p=mod;  
    return C(n%p,m%p,fac,mod) * Lucas(n/p,m/p,fac,mod);  
} 
