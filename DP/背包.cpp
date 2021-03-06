void pack01(int cost,int weight)
{
	for(int i=V;i>=cost;i--)
		dp[i]=max(dp[i-cost]+weight,dp[i]);
}
void packCM(int cost,int weight)    ///完全背包
{
	for(int i=cost;i<=V;i++)
		dp[i]=max(dp[i-cost]+weight,dp[i]);
}
void packMU(int cost,int weight,int num)  ///多重背包 O(logM)
{
	if(num*cost>=V)
	{
		packCM(cost,weight);
		return ;
	}
	int k=1;
	while(k<num)
	{
		pack01(cost*k, weight*k);
		num-=k;
		k*=2;
	}
	pack01(cost*num, weight*num);
}
///分组背包
for(int i=1;i<=n;i++)///每一组
	for(int v=V;v>=0;v--)///01背包
		for(int k=0;k<n&&v[k]<=v;k++)///对该组内每一个物品
			dp[i][k]=max(dp[i][k],dp[i-1][V-v[k]]+C[k]);
