//旋转卡壳计算平面点集最大三角形面积
int rotating_calipers(Point p[],int n)
{
    int ans = 0;
    Point v;
    for(int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        int k = (j+1)%n;
        while(j != i && k != i)
        {
            ans = max(ans,abs((p[j]-p[i])^(p[k]-p[i])));
            while( ((p[i]-p[j])^(p[(k+1)%n]-p[k])) < 0 )
                k = (k+1)%n;
            j = (j+1)%n;
        }
    }
    return ans;
}
Point p[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n == -1)break;
        for(int i = 0; i < n; i++)list[i].input();
        Graham(n);
        for(int i = 0; i < top; i++)p[i] = list[Stack[i]];
        printf("%.2f\n",(double)rotating_calipers(p,top)/2);
    }
    return 0;
}
