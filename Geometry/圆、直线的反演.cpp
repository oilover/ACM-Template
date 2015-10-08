#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long LL;
const int inf = 0x3f3f3f3f;
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
const double r = 1;
/// 圆的反演（结果是一个圆），反演中心O为原点，反演满足OC * OC' = r*r  这里 r = 1
/// 圆不经过反演中心
Circle inv(Circle a)
{
    double d1  =  abs(a);
    double r1 = a.r;
    double r2 = r1 / (d1 * d1 - r1 * r1) * r * r;
    double d2 = (r1 * r2 + r * r) / d1;
    double x = a.x / d1 * d2;
    double y = a.y / d1 * d2;
    return P(x, y, r2);
}
Circle inv(P s, P t) /// 直线的反演，直线不经过反演中心
{
    P O(0,0);
    P p = cuizhu(O, s, t);
    double d = dis(O, p);
    p = p * (0.5 / d / d);
    p.r = dis(p, O);
    return p;
}
