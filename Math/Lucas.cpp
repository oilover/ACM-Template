///Lucas(n, m, p)=c[n%p][m%p]*lucas(n/p, m/p, p);  组合数取模 p<10^5
ll fac[1021100];
ll mul(ll a, ll n, ll m)
{
    ll r = 0;
    for (; n>0; n>>=1,a=(a+a)%m) if(n&1) r = (r + a) % m;
    return r;
}
ll pmod(ll a, ll n, ll m)
{
    a %= m;
    ll r = 1;
    for (; n>0; n>>=1,a=a*a%m) if (n&1) r=mul(r, a, m);
    return r;
}
ll inv(ll a, ll m) { if(a==1) return 1;return pmod(a, m-2, m); }
void get_fac(ll p)
{
    fac[0]=1;
    for(int i=1;i<=p+10;i++)
        fac[i]=(fac[i-1]*i)%p;
}
ll C(ll n,ll m,ll mod)
{
    if (n < m) return 0;
    ll Comb = mul(mul(fac[n], inv(fac[n-m], mod) , mod),
                  inv(fac[m], mod) , mod) ;
    return Comb;
}
ll Lucas(ll n,ll m,ll mod)
{
    if(m==0) return 1;  ll p=mod;
    return mul(C(n%p, m%p, mod) , Lucas(n/p,m/p,mod) , mod) % mod;
}
