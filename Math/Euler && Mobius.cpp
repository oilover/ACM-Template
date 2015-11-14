    memset(phi,0,sizeof  phi); phi[1]=1;
    for(int i=2;i<N;i++)if(!phi[i])
        for (int j=i;j<N;j+=i)
    {
        if(!phi[j])phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
    }
    int phi[N];
int main()
{
    int i,j,k;
    for(i=1; i<N; i++) phi[i]=i; //先初始化为本身
    for(i=2; i<N; i++) //像筛素数一样，从2开始
    {
        if(phi[i]==i) //如果自己的值没有变(还是i)，表示i是素数
        {
            for(j=i; j<N; j+=i) //对于i的每一个倍数j，j都有i这个素因子
            {
                phi[j]=phi[j]/i*(i-1);//按公式来
            }
        }
    }
    for(i=1; i<30; i++) printf("phi[%02d] = %d\n",i,phi[i]);
    return 0;
}
    memset(mu, -1, sizeof mu);
    mu[1] = 1;
    for (int i=2;i<N;i++) for (int j=i+i;j<N;j+=i) {
        mu[j] -= mu[i];
    }
