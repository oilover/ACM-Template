//二维平面一个n个节点的简单多边形，多边形内有一个灯泡，求照明面积。
const double eps = 1e-8;
const double pi = acos(-1.);
using namespace std;
int dblcmp( double x )
{
    if( fabs(x) < eps )    return 0;
    return x > 0 ? 1 : -1;
}
double nowAng;
struct point
{
    double x, y, a;
    point(){}
    point( double _x, double _y ) : x(_x), y(_y)
    {
        a = atan2(y, x);
    }
    bool operator<( const point p )    const
    {
        if( dblcmp(a-p.a) == 0 )
            return x*x+y*y < p.x*p.x+p.y*p.y;
        return a < p.a;
    }
} p[60000], O;
inline double dis( point a, point b )
{
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
inline double cross( point k, point a, point b )
{
    return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);
}
point inter( point a1, point a2, double ang )
{
    point b1 = point(0, 0), b2 = point(cos(ang), sin(ang));
    double u = cross(a1, a2, b1), v = cross(a2, a1, b2);
    return point((b1.x*v+b2.x*u)/(v+u), (b1.y*v+b2.y*u)/(v+u));
}
struct line
{
    point a, b;
    line(){};
    line( point _a, point _b ) : a(_a), b(_b){};
    bool operator<( const line p )    const
    {
        if( fabs(a.x-p.a.x) < eps && fabs(a.y-p.a.y) < eps )
            return cross(a, b, p.b) < 0;
        point d1 = inter(a, b, nowAng);
        point d2 = inter(p.a, p.b, nowAng);
        return d1.x*d1.x+d1.y*d1.y < d2.x*d2.x+d2.y*d2.y;
    }
};
struct Event
{
    double ang;
    int id, st;
    line L;
    bool operator<( const Event p )    const
    {
        if( dblcmp(ang-p.ang) == 0 )
            return st > p.st;
        return ang < p.ang;
    }
} E[200000];
int c;
void add( point a, point b, int k )
{
    if( b < a )
        swap(a, b);
    E[c].ang = a.a, E[c].st = 1, E[c].L = line(a, b), E[c++].id = k;
    E[c].ang = b.a, E[c].st = 0, E[c++].id = k;
}
multiset<line> S;
multiset<line>::iterator itArr[100000];
inline double cal( line L, double d1, double d2 )
{
    point a = inter(L.a, L.b, d1);
    point b = inter(L.a, L.b, d2);
    return fabs(0.5*cross(O, a, b));
}
int main()
{
    int i, j, k, n;
    double d, t, ans, pre;
    while( scanf("%lf %lf", &O.x, &O.y) != EOF )
    {
        c = 0;
        scanf("%d", &n);
        for( i = 0; i < n; ++i )
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            p[i].x -= O.x, p[i].y -= O.y;
            p[i].a = atan2(p[i].y, p[i].x);
        }
        O.x = O.y = 0;
        p[n] = p[0];
        for( i = k = 0; i < n; ++i )
        {
            d = fabs(p[i+1].a-p[i].a);
            if( d < pi )
                add(p[i], p[i+1], k++);
            else
            {
                point tmp = inter(p[i], p[i+1], pi);
                tmp.a = pi*dblcmp(p[i].a);
                add(p[i], tmp, k++);
                tmp.a = pi*dblcmp(p[i+1].a);
                add(p[i+1], tmp, k++);
            }
        }
        sort(E, E+c);
        S.clear();
        ans = 0;    pre = -pi;
        for( i = 0; i < c; ++i )
        {
            nowAng = E[i].ang;
            if( E[i].st )
            {
                if( S.size() > 0 )
                    ans += cal(*S.begin(), pre, E[i].ang);
                itArr[E[i].id] = S.insert(E[i].L);
            }
            else
            {
                ans += cal(*S.begin(), pre, E[i].ang);
                S.erase(itArr[E[i].id]);
            }
            pre = E[i].ang;
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
