#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef unsigned long long ll;
const int N = 50003;
struct P
{
	int x, y, r;
	bool operator<(P b) const
	{
		return x < b.x;
	}
	ll d(P b)
	{
		ll dx = x - b.x, dy = y - b.y;
		return dx*dx + dy*dy;
	}
}p[N];
inline double  sqr(double x) { return x*x; }
struct Line  ///从左向右扫描节点
{
	int id;
	bool in;
        Line() {}
        Line(int _id, bool _in) { id = _id, in = _in; }
        void Read(int _id, bool _in) { id = _id, in = _in; }
        inline int getx() const { return p[id].x + p[id].r * (in ? -1 : 1) ;}
        bool operator < (const Line &b) const { return getx() < b.getx() ; }
} l[N<<1] ;
int LineNow;
struct Node  ///从上至下排序节点
{
        int id;
        int up;
        Node() {}
        Node(int _id, bool _up) { id = _id; up = _up; }
        inline double gety() const
        {
                return p[id].y + sqrt(sqr(p[id].r) - sqr(LineNow - p[id].x) ) * (up ? 1 : -1);
        }
        bool operator < (Node b) const
        {
                double y1 = gety();
                double y2 = b.gety();
                return abs(y1-y2) > 1e-7 ? y1 > y2 : up > b.up;
        }
};
set<Node> s;
set<Node>::iterator it, itn;

int n;
int lines;
void ReadData()
{
        lines = 0;
        for (int i=0; i<n;i++) {
                scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].r);
                l[lines++] = Line(i , true);
                l[lines++] = Line(i, false);
        }
}
int cnt[N];
int gao()
{
        int ans = 0;
        sort(l , l+lines);
        s.clear();
        for (int i=0;i<lines;i++) {
                LineNow = l[i].getx();
                int id = l[i].id;
                if (!l[i].in) /// out
                {
                        s.erase(Node(id, true));
                        s.erase(Node(id, false));
                        continue;
                }
                it = itn = s.insert(Node(id, true)).first;
                itn ++;
                if (it==s.begin() || itn==s.end())
                        cnt[id] = 1;
                else {
                        it--;
                        if (it->id == itn->id ) cnt[id] = cnt[it->id] + 1;
                        else cnt[id] = max(cnt[it->id], cnt[itn->id]);
                }
                ans = max(ans, cnt[id]);
                s.insert(Node(id, false));
        }
        return ans;
}
int main()
{
        while (scanf("%d", &n)==1 && n) {
                ReadData();
                int ans = gao();
                printf("%d\n", ans);
        }
        return 0;
}
