///Lucas(n, m, p)=c[n%p][m%p]*lucas(n/p, m/p, p);  组合数取模 p<10^5
LL fact[100100];  
void get_fact(LL p)  
{  
    fact[0]=1LL;  
    for(int i=1;i<=p+10;i++)  
        fact[i]=(fact[i-1]*i)%p;  
}  
LL Lucas(LL n,LL m,LL p)  
{  
    ///lucas(n,m,p)=c[n%p][m%p]*lucas(n/p,m/p,p);  
    LL ret=1LL;  
    while(n&&m)  
    {  
        LL a=n%p,b=m%p;  
        if(a<b) return 0;  
        ret=(ret * fact[a] * PowMod((fact[b]*fact[a-b])%p, p-2, p))%p;  
        n/=p; m/=p;  
    }  
    return ret%p;  
}  
