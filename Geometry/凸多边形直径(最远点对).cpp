P ans1, ans2;
double diameter(vector<P> p) /// 凸多边形直径
{
    int First, Second; ///可以求出距离最远两点编号
    int n = p.size();
    if (n == 0) return 0;
    if (n == 1)
    {
        First = Second = 0;
        return 0;
    }
    #define nxt(i) ((i+1)%n)
    double maxd = 0;
    for (int i=0,j=1; i<n; i++)
    {
        while (cmp(det(p[nxt(i)]-p[i], p[j]-p[i]) -
                   det(p[nxt(i)] - p[i], p[nxt(j)] - p[i])) < 0)
            j=nxt(j);
        double d = dis(p[i], p[j]);
        if (d > maxd)
        {
            maxd = d;
            First = i, Second = j;
        }
        d = dis(p[nxt(i)], p[nxt(j)]);
        if (d > maxd)
        {
            maxd = d;
            First = nxt(i), Second = nxt(j);
        }
    }
    ans1 = p[First];
    ans2 = p[Second];
    return maxd;
}
