const double PI = acos(-1.0);
const double eps = 1e-8;
int cmp(double x)
{
    return x < -eps ? -1 : x > eps;
}
struct P
{
    double x, y, r;
    P() { x = 0, y = 0, r = 1; }
    P(double xx, double yy, double rr =  1)
    {
        x = xx, y = yy, r = rr;
    }
    P getP(double a)
    {
        return P(x + cos(a)*r, y + sin(a)*r);
    }
    void in() { scanf("%lf%lf%lf", &x, &y, &r); }
    P operator * (double k) { return P(x*k, y*k, r*k); }
    P operator / (double k) {
        assert(abs(k) > 1e-8);
        return P(x/k, y/k);
    }
    void out()
    {
        printf("%.10f %.10f %.10f\n", x, y, r);
    }
};
double pf(double x) { return x * x; }
P operator-(P a, P  b)
{
    return P(a.x - b.x, a.y - b.y);
}
P operator+(P a, P  b)
{
    return P(a.x + b.x, a.y + b.y);
}
double abs(P p) { return sqrt(pf(p.x) + pf(p.y)); }
double dis(P a, P b) { return abs(a - b); }
typedef P Circle ;
P a, b, o;
double dot(P a, P b) { return a.x*b.x + a.y*b.y; }
P cuizhu(P p, P s, P t) ///点到直线垂足
{
    double r = dot(t-s, p-s)/dot(t-s, t-s);
    return s + (t-s)*r;
}
/// 圆的切线，返回切线条数，见白书 267 页
int getTan(Circle A, Circle B, P a[], P b[])
{
    int cnt = 0;
    if (A.r < B.r) { swap(A, B); swap(a, b); }
    double d2 = pf(dis(A, B));
    double rdiff = (A.r - B.r);
    double rsum = A.r + B.r;
    if (d2 < pf(rdiff)) return 0;
    double base = atan2(B.y - A.y, B.x - A.x);
    if (d2 == 0 && A.r == B.r)  return -1;
    if (d2 == pf(rdiff)) {
        a[cnt] = A.getP(base); b[cnt++] = B.getP(base);
        return cnt;
    }
    double ang = acos((A.r - B.r) / sqrt(d2));
    a[cnt] = A.getP(base+ang); b[cnt++] = B.getP(base + ang);
    a[cnt] = A.getP(base - ang); b[cnt++] = B.getP(base - ang);
    if (d2 == rsum * rsum) {
        a[cnt] = A.getP(base); b[cnt++] = B.getP(PI + base);
    }
    else if (d2 > rsum * rsum) {
        double ang = acos((A.r + B.r) / sqrt(d2));
        a[cnt] = A.getP(base + ang); b[cnt++] = B.getP(base + ang);
        a[cnt] = A.getP(base - ang); b[cnt++] = B.getP(base - ang);
    }
    return cnt;
}
