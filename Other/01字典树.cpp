// N个二进制数建一个字典树，求一个数与这些数异或的第 k 大值。
const int M = 1000 * 32;
const int N = 1234;
int ch[M][2], L, ed[M];
int newnode() { ch[L][0] = ch[L][1] = -1; ed[L++] = 0; return L-1; }
void init() { L = 0; newnode(); }
int a[N];
void insert(int s)
{
    int u = 0;
    for (int i=29;i>=0;i--) {
        int &tmp = ch[u][s>>i&1];
        ed[u] ++;
        if (tmp==-1) tmp = newnode();
        u = tmp;
    }
    ed[u] ++;
}
void del(int s)
{
    int u = 0;
    for (int i=29;i>=0;i--) {
        int &tmp = ch[u][s>>i&1];
        ed[u] --;
        if (tmp==-1) tmp = newnode();
        u = tmp;
    }
    ed[u] --;
}
int find_max(int s, int k)
{
    int u = 0;
    LL ret = 0;
    for (int i=29;i>=0;i--) {
        int c = (s >> i & 1);
        int _ = c ^ 1;
        if (ch[u][_] > 0 && ed[ch[u][_]] >= k)
        {
            u = ch[u][_];
            ret = (ret << 1 | _);
        }
        else {
            if (ch[u][_] > 0) k -= ed[ch[u][_]];
            u = ch[u][c];
            ret = (ret << 1 | c);
        }
    }
    return ret ^ s;
}
