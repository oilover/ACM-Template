#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long LL;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);
struct P
{
    double x, y;
    P(double _x = 0, double _y = 0) { x = _x, y = _y; }
    P rotate(double A)  ///把点绕原点逆时针旋转弧度A
    {
        return P(x * cos(A) - y * sin(A), x * sin(A) + y * cos(A));
    }
    P operator + (P b) {  return P(x+b.x, y+b.y);  }
    double len()
    {
        return sqrt(x*x+y*y);
    }
    double operator ^(const P &b)const //叉积
    {
        return x*b.y - y*b.x;
    }
    double operator *(const P &b)const //点积
    {
        return x*b.x + y*b.y;
    }
};

int cmp(double x) { return x<-eps?-1:x>eps; }
bool zero(double x) { return cmp(x)==0; }

P operator-(P a, P  b){  return P(a.x-b.x, a.y-b.y);  }
P operator*(P a, double k)
{
    return P(a.x*k, a.y*k);
}
P operator / (P a, double k)
{
    return P(a.x/k, a.y/k);
}
bool operator==(P a,P b)
{
    return zero(a.x-b.x) && zero(a.y-b.y);
}
bool operator!=(P a, P b)
{ return !(a==b);  }
double getAngle(P a)    ///点与X轴正方向的夹角
{
    return atan2(a.y, a.x);
}
double stdto(double t)      ///把角度转化成[0, 2*PI)范围内
{
    while(t < 0) t += 2 * PI;
    while(t >= 2*PI) t -= 2 * PI;
    return t;
}
double det(P a, P b)    ///叉积（叉积大于0 那么B在A的逆时针方向）
{
    return a.x*b.y - a.y*b.x;
}
double operator *(P a, P b)   ///叉积  计算向量A和B构成的平行四边形面积  人面向A的方向 B在左边 叉积大于0
{
    return det(a, b);
}
double cross(P a, P b, P c)  ///三角形面积的两倍，平行四边形面积
{
    return (b-a) * (c-a);
}
double dot(P a, P b)    ///点积（点积小于0 两个向量夹角大于90度）  dot(a, b) = |a||b|cos(a)
{
    return a.x * b.x + a.y * b.y;
}
double dis(P a, P b)    ///两个点的距离
{
    return sqrt(dot(a-b, a-b));
}
bool dots(P a, P b, P c)   ///判断三点共线
{
    return cmp(det(b - a, c - a)) == 0;
}
bool on(P p, P s, P t)  ///判断点是否在线段上（包括端点）
{
    return cmp(dis(p, s) + dis(p, t) - dis(s, t)) == 0;
}
double dis(P p, P s, P t)   ///点到直线的距离
{
    return fabs(det(s-p, t-p))/dis(s,t);
}
double disToSeg(P p, P s, P t)   ///点到线段的距离
{
    if (dot(p-s,t-s)>0 && dot(p-t, s-t)>0)
        return fabs(det(s-p, t-p))/dis(s,t);
    return min(dis(p,s), dis(p,t));
}

P cuizhu(P p, P s, P t) ///点到直线垂足
{
    double r = dot(t-s, p-s)/dot(t-s, t-s);
    return s + (t-s)*r;
}
bool jiao(const P &a, const P &b, const P &c, const P &d, P &res)  ///求直线交点，如果返回false表示平行
{
    double k1 = det(b-a, c-a), k2 = det(b-a, d-a);
    if(zero(k1 - k2)) return false;
    res = (d*k1 - c*k2) / (k1 - k2);
    return true;
}
/**
判两点在线段同侧
– 有点在线段上返回0,
– 在同侧返回1
– 不同侧返回-1
*/
int side(P a, P b, P s, P t)
{
    return cmp(cross(s,a,t)*cross(s,b,t));
}
bool cz(P a, P b, P c, P d)   ///判断两条直线垂直
{
    return cmp(dot(b-a, d-c))==0;
}
void move_d(P &a, P &b, double len)   ///直线沿着法向量平移len
{
    P d = b - a;
    d = d / d.len();
    d = d.rotate(PI/2);
    d = d * len;
    a = a + d, b = b + d;
}
