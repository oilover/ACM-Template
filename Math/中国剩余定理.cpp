// 参数说明：n是同余方程个数，a[i]是余数，m[i]是对应的模数
ll CRT(ll a[], ll m[], int n)
{
    ll M = 1;
    for (int i=0;i<n;i++) M *= m[i];
    ll ret = 0;
    for (int i=0;i<n;i++) {
        ll tm = M / m[i];
        ll x = inv(tm, m[i]);
        ret = (ret + mul( mul(tm, x, M) , a[i] , M)) % M;
    }
    return (ret + M) % M;
}
