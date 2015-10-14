//二维平面有n(0 < n <= 50000)条线段，要求判断n条线段是否存在交点，如果有，输出相交线段的编号。
#define MP make_pair
#define PI pair
#define FI first
#define SE second
#define PB push_back
#define SZ size()
const double eps = 1e-10;
const double pi = acos(-1.);
const int mod = 1000000007;
const int maxn = 50100;
const int INF = 99999999;
struct point
{
    int x, y;
    bool operator<( const point p )    const
    {
        if( x == p.x )    return y < p.y;
        return x < p.x;
    }
} L[maxn][2];
int tim;
struct eve
{
    int x, id, st;
    eve(){}
    eve( int _x, int _id, int _st ) : x(_x), id(_id), st(_st) {}
    bool operator<( const eve p )     const
    {
        if( p.x == x )    return st > p.st;
        return x < p.x;
    }
} E[maxn*2];

void getLine( point x, point y, double& a, double& b, double& c )
{
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x*x.y - x.x*y.y;
}
struct ele
{
    int id;
    double k, c;
    ele( int _id )
    {
        id = _id;
        if( L[id][0].x == L[id][1].x )
            k = 0, c = L[id][0].y;
        else
        {
            double A, B, C;
            getLine(L[id][0], L[id][1], A, B, C);
            k = -A/B, c = -C/B;
        }
    }
    bool operator<( const ele p )    const
    {
        return tim*k+c < tim*p.k+p.c;
    }
};
set<ele> S;
set<ele>::iterator itArr[maxn];
inline set<ele>::iterator preIt( set<ele>::iterator it )
{
    return it == S.begin() ? S.end() : --it;
}

inline set<ele>::iterator nxtIt( set<ele>::iterator it )
{
    return it == S.end() ? S.end() : ++it;
}

int cross( point& k, point& a, point& b )
{
    return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);
}

int dot( point& k, point& a, point& b )
{
    return (a.x-k.x)*(b.x-k.x) + (a.y-k.y)*(b.y-k.y);
}

inline int sgn( int x )
{
    if( x > 0 )    return 1;
    if( x < 0 )    return -1;
    return x;
}

bool inter( int a, int b )
{
    int d1 = sgn(cross(L[a][0], L[a][1], L[b][0]));
    int d2 = sgn(cross(L[a][0], L[a][1], L[b][1]));
    int d3 = sgn(cross(L[b][0], L[b][1], L[a][0]));
    int d4 = sgn(cross(L[b][0], L[b][1], L[a][1]));
    if( (d1^d2)==-2 && (d3^d4)==-2 )    return 1;
    if( d1 == 0 && dot(L[b][0], L[a][0], L[a][1]) <= 0 )    return 1;
    if( d2 == 0 && dot(L[b][1], L[a][0], L[a][1]) <= 0 )    return 1;
    if( d3 == 0 && dot(L[a][0], L[b][0], L[b][1]) <= 0 )    return 1;
    if( d4 == 0 && dot(L[a][1], L[b][0], L[b][1]) <= 0 )    return 1;
    return 0;
}

bool solve( int n )
{
    sort(E, E+n);
    S.clear();
    for( int i = 0; i < n; ++i )
    {
        tim = E[i].x;
        int id = E[i].id;

        if( E[i].st == 1 )
        {
            ele t = ele(id);
            set<ele>::iterator nxt = S.lower_bound(t), pre = preIt(nxt);
            if( nxt != S.end() && inter((*nxt).id, id) )
            {
                printf("YES\n%d %d\n", (*nxt).id, id);
                return 1;
            }
            if( pre != S.end() && inter((*pre).id, id) )
            {
                printf("YES\n%d %d\n", (*pre).id, id);
                return 1;
            }
            itArr[id] = S.insert(nxt, t);
        }
        else
        {
            set<ele>::iterator pre = preIt( itArr[id] ), nxt = nxtIt( itArr[id] );
            if( pre != S.end() && nxt != S.end() && inter((*pre).id, (*nxt).id) )
            {
                printf("YES\n%d %d\n", (*pre).id, (*nxt).id);
                return 1;
            }
            S.erase(itArr[id]);
        }
    }

    return 0;
}

int main()
{
    srand(4);
    int T, cases = 1;
    int i, j, k, e;
    double A, B, C;
    int N, M;
    scanf("%d", &N);
    for( i = 1; i <= N; ++i )
    {
        scanf("%d %d %d %d", &L[i][0].x, &L[i][0].y, &L[i][1].x, &L[i][1].y);
        if( L[i][1] < L[i][0] )
            swap(L[i][0], L[i][1]);
    }
    for( i = 1, e = 0; i <= N; ++i )
    {
        E[e++] = eve(L[i][0].x, i, +1);
        E[e++] = eve(L[i][1].x, i, -1);
    }
    if( !solve(e) )
        puts("NO");
    return 0;
}
