int cmp(double x)
{
    return x<-eps?-1:x>eps;
}
bool zero(double x)
{
    return cmp(x)==0;
}
bool eq(double a, double b)
{
    return zero(a-b);
}
struct P
{
    double x, y;
    P(double _x = 0, double _y = 0)
    {
        x = _x, y = _y;
    }
    double operator ^(const P &b)const //叉积
    {
        return x*b.y - y*b.x;
    }
    double operator *(const P &b)const //点积
    {
        return x*b.x + y*b.y;
    }
    void out()
    {
        printf("%.16f %.16f\n", x, y);
    }
    P rotate(double A)  ///把点绕原点逆时针旋转弧度A
    {
        return P(x * cos(A) - y * sin(A), x * sin(A) + y * cos(A));
    }
    P operator + (P b)
    {
        return P(x+b.x, y+b.y);
    }
    bool operator == (P b) const
    {
        return eq(x,b.x) && eq(y, b.y);
    }
    void operator += (P b)
    {
        x += b.x, y += b.y;
    }
    bool operator < (P b) const
    {
        return x < b.x || (x == b.x && y < b.y);
    }
    double len()
    {
        return sqrt(x*x+y*y);
    }
};


P operator-(P a, P  b)
{
    return P(a.x-b.x, a.y-b.y);
}
P operator*(P a, double k)
{
    return P(a.x*k, a.y*k);
}
P operator / (P a, double k)
{
    return P(a.x/k, a.y/k);
}
struct Line
{
    P s,e;
    double k;
    Line() {}
    Line(P _s,P _e)
    {
        s = _s;
        e = _e;
        k = atan2(e.y - s.y,e.x - s.x);
    }
    P operator &(const Line &b)const //直线的交点
    {
        P res = s;
        double t = ((s - b.s)^(b.s - b.e))/((s - e)^(b.s - b.e));
        res.x += (e.x - s.x)*t;
        res.y += (e.y - s.y)*t;
        return res;
    }
};
//半平面交，直线的左边代表有效区域
bool HPIcmp(Line a,Line b)
{
    if(fabs(a.k - b.k) > eps)return a.k < b.k;
    return ((a.s - b.s)^(b.e - b.s)) < 0;
}
Line Q[N];
vector<P> HPI(Line line[], int n) /// 半平面交
{
    int tot = n;
    sort(line,line+n,HPIcmp);
    tot = 1;
    for(int i = 1; i < n; i++)
        if(fabs(line[i].k - line[i-1].k) > eps)
            line[tot++] = line[i];
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    vector<P> res;
    for(int i = 2; i < tot; i++)
    {
        if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s)) < eps ||
                fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
            return res;;
        while(head < tail && (((Q[tail]&Q[tail-1]) -
                               line[i].s)^(line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (((Q[head]&Q[head+1]) -
                               line[i].s)^(line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (((Q[tail]&Q[tail-1]) -
                           Q[head].s)^(Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (((Q[head]&Q[head-1]) -
                           Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
        head++;

    if(tail <= head + 1) return res;;
    for(int i = head; i < tail; i++)
        res.push_back(Q[i]&Q[i+1]);
    if(head < tail - 1)
        res.push_back(Q[head]&Q[tail]);
    return res;
}
/************半平面交结束*******************/
