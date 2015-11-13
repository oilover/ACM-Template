LL mul(LL a,LL b,LL mod) {
    if(!a) return 0;
    return ((a&1)*b%mod + (mul(a>>1,b,mod)<<1)%mod)%mod;
}
LL quickPow(LL a,LL d,LL n) {
    LL ret = 1;
    while(d) {
        if(d&1) ret = mul(ret,a,n);
        d >>= 1;
        a = mul(a,a,n);
    }
    return ret;
}
bool check(LL a,LL d,LL n) {
    if(n == a) return true;
    while(~d&1) d >>= 1;
    LL t = quickPow(a,d,n);
    while(d < n-1 && t != 1 && t != n-1) {
        t = mul(t,t,n);
        d <<= 1;
    }
    return (d&1) || t == n-1;
}
bool isP(LL n) {
    if(n == 2) return true;
    if(n < 2 || 0 == (n&1)) return false;
    static int p[5] = {2,3,7,61,24251};
    for(int i = 0; i < 5; ++i)
        if(!check(p[i],n-1,n)) return false;
    return true;
}
LL gcd(LL a,LL b) {
    if(a < 0) return gcd(-a,b);//特别注意，没这个TLE
    return b?gcd(b,a%b):a;
}
LL Pollard_rho(LL n,LL c) {
    LL i = 1,k = 2,x = rand()%n,y = x;
    while(true) {
        x = (mul(x,x,n) + c)%n;
        LL d = gcd(y - x,n);
        if(d != 1 && d != n) return d;
        if(y == x) return n;
        if(++i == k) {
            y = x;
            k <<= 1;
        }
    }
}
LL Fac[maxn],tot;
void factorization(LL n) { // 调用之前要让 tot = 0，调用后还要去重，n>1
    if(isP(n)) {
        Fac[tot++] = n;
        return;
    }
    LL p = n;
    while(p >= n) p = Pollard_rho(p,rand()%(n-1)+1);
    factorization(p);
    factorization(n/p);
}
快速分解10^12以内的质因子：
const int N = 1e6+7;
int prime[N];
bool p[N];
vector<int> fj(int n)
{
    vector<int> vec;
    for (int i=0;prime[i]*prime[i]<=n;i++)if(n%prime[i]==0) {
        while (n % prime[i] == 0) n/=prime[i];
        vec.push_back(prime[i]);
    }
    if (n > 1)  vec.push_back(n);
    return vec;
}
int main()
{
    tot = 0;
    memset(p,true,sizeof p);p[1]=false;
    for (int i=2;i<N;i++)if(p[i]) {
        prime[tot ++] = i;
        for (int j=i+i;j<N;j+=i) p[j]=false;
    }
}
