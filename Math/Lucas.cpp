typedef long long LL;
///Lucas(n, m, p)=c[n%p][m%p]*lucas(n/p, m/p, p);  组合数取模 p<10^5
LL fac[1021100];
LL mul(LL a, LL n, LL m)
{
    LL r = 0;
    for (; n>0; n>>=1,a=(a+a)%m) if(n&1) r = (r + a) % m;
    return r;
}
LL pmod(LL a, LL n, LL m)
{
    a %= m;
    LL r = 1;
    for (; n>0; n>>=1,a=a*a%m) if (n&1) r=mul(r, a, m);
    return r;
}
LL inv(LL a, LL m) { if(a==1) return 1;return pmod(a, m-2, m); }
void get_fac(LL p)
{
    fac[0]=1;
    for(int i=1;i<=p+10;i++)
        fac[i]=(fac[i-1]*i)%p;
}
LL C(LL n,LL m,LL mod)
{
    if (n < m) return 0;
    LL Comb = mul(mul(fac[n], inv(fac[n-m], mod) , mod),
                  inv(fac[m], mod) , mod) ;
    return Comb;
}
LL Lucas(LL n,LL m,LL mod)
{
    if(m==0) return 1;  LL p=mod;
    return mul(C(n%p, m%p, mod) , Lucas(n/p,m/p,mod) , mod) % mod;
}
LL C(LL n, LL m, LL p) {  // 另一种计算组合数方法
	if(n < m) {
		return 0;
	}
	m = min(m, n - m);
	LL ret = 1;
	for(LL i = 1, j = n; i <= m; i++, j--) {
		ret = ((ret * j) % p * inv(i, p)) % p;
	}
	return ret;
}
LL solve(LL n, LL m, LL p) {
	LL ret = 1;
	while(m > 0) {
		ret = ret * C(n % p, m % p, p) % p;
		n /= p;
		m /= p;
	}
	return ret;
}
