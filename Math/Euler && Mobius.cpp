    memset(phi,0,sizeof  phi); phi[1]=1;
    for(int i=2;i<N;i++)if(!phi[i])
        for (int j=i;j<N;j+=i)
    {
        if(!phi[j])phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
    }
    
    memset(mu, -1, sizeof mu);
    mu[1] = 1;
    for (int i=2;i<N;i++) for (int j=i+i;j<N;j+=i) {
        mu[j] -= mu[i];
    }
