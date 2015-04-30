#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#include <vector>
#define SIZE(X) ((int)(X.size()))
#define PB push_back
#define MP make_pair
#include <algorithm>
const double eps = 1e-8;
const double pi = acos(-1);
struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0) { x = _x, y = _y; }
    Point rotate(double A)  ///把点绕原点逆时针旋转弧度A
    {
        return Point(x * cos(A) - y * sin(A), x * sin(A) + y * cos(A));
    }
    double len()
    {
        return sqrt(x*x+y*y);
    }
};
Point P(double x, double y) { return Point(x, y); }
#define point Point

int cmp(double x) { return x<-eps?-1:x>eps; }
bool zero(double x) { return cmp(x)==0; }

Point operator-(Point a, Point  b)
{
    return P(a.x-b.x, a.y-b.y);
}
Point operator*(Point a, double k)
{
    return Point(a.x*k, a.y*k);
}
point operator / (point a, double k)
{
    return Point(a.x/k, a.y/k);
}
bool operator==(point a,point b)
{
    return zero(a.x-b.x) && zero(a.y-b.y);
}
bool operator!=(point a, point b)
{
    return !(a==b);
}
double getAngle(point a)    ///点与X轴正方向的夹角
{
    return atan2(a.y, a.x);
}
double stdto(double t)      ///把角度转化成[0, 2*pi)范围内
{
    while(t < 0) t += 2 * pi;
    while(t >= 2*pi) t -= 2 * pi;
    return t;
}
double det(point a, point b)    ///叉积（叉积大于0 那么B在A的逆时针方向）
{
    return a.x*b.y - a.y*b.x;
}
double operator *(point a, point b)   ///叉积  计算向量A和B构成的平行四边形面积  人面向A的方向 B在左边 叉积大于0
{
    return det(a, b);
}
double cross(point a, point b, point c)  ///三角形面积的两倍，平行四边形面积
{
    return (b-a) * (c-a);
}
double dot(Point a, Point b)    ///点积（点积小于0 两个向量夹角大于90度）  dot(a, b) = |a||b|cos(a)
{
    return a.x * b.x + a.y * b.y;
}
double dis(point a, point b)    ///两个点的距离
{
    return sqrt(dot(a-b, a-b));
}
bool dots(point a, point b, point c)   ///判断三点共线
{
    return cmp(det(b - a, c - a)) == 0;
}
bool on(Point p, Point s, Point t)  ///判断点是否在线段上（包括端点）
{
    return cmp(dis(p, s) + dis(p, t) - dis(s, t)) == 0;
}
double dis(point p, point s, point t)   ///点到直线的距离
{
    return fabs(det(s-p, t-p))/dis(s,t);
}
point cuizhu(point p, point s, point t) ///点到直线垂足
{
    double r = dot(t-s, p-s)/dis(s, t);
    return s + (t-s)*r;
}
bool intersect(const point &a, const point &b, const point &c, const point &d, point &res)  ///求直线交点，如果返回false表示平行
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
int side(point a, point b, point s, point t)
{
    return cmp(cross(s,a,t)*cross(s,b,t));
}
bool cz(point a, point b, point c, point d)   ///判断两条直线垂直
{
    return cmp(dot(b-a, d-c))==0;
}
void move_d(point a, point b, double len)   ///直线沿着法向量平移len
{
    point d = b - a;
    d = d / d.len();
    d = d.rotate(pi/2);
    d *= len;
    a += d, b += d;
}
