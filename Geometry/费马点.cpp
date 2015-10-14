//模拟退火求费马点 保存在ptres中
double fermat_point(Point *pt, int n, Point& ptres)
{
    Point u, v;
    double step = 0.0, curlen, explen, minlen;
    int i, j, k, idx;
    bool flag;
    u.x = u.y = v.x = v.y = 0.0;
    REP(i, n)
    {
        step += fabs(pt[i].x) + fabs(pt[i].y);
        u.x += pt[i].x;
        u.y += pt[i].y;
    }
    u.x /= n;
    u.y /= n;
    flag = 0;
    while(step > eps)
    {
        for(k = 0; k < 10; step /= 2, ++k)
            for(i = -1; i <= 1; ++i)
                for(j = -1; j <= 1; ++j)
                {
                    v.x = u.x + step*i;
                    v.y = u.y + step*j;
                    curlen = explen = 0.0;
                        REP(idx, n)
                    {
                        curlen += dist(u, pt[idx]);
                        explen += dist(v, pt[idx]);
                    }
                    if(curlen > explen)
                    {
                        u = v;
                        minlen = explen;
                        flag = 1;
                    }
                }
    }
    ptres = u;
    return flag ? minlen : curlen;
}
