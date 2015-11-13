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
//能兼容多个模数不互质的代码：
LL china2(LL m1,LL r1,LL m2,LL r2)  
{  
    LL ans,y,k,r=r2-r1;  
    r=(r%m2+m2)%m2;  
    LL g=ex_gcd(m1,m2,y,k);  
    y=(y%m2+m2)%m2;  
    if(r%g) return -1;  
    y*=r/g;  
    return (y*m1+r1)%lcm(m1,m2);  
}//c2 
LL china(LL n,LL *m,LL *r)  
{  
    LL am=m[0],ar=r[0];  
    LL i;  
    for(i=1;i<n;i++)  
    {  
        ar=china2(am,ar,m[i],r[i]);  
        if(ar<0) return -1;  
        am=lcm(am,m[i]);  
    }  
    return ar;  
}  
