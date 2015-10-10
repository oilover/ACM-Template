#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const int N = 505000;
int M;
ll S[N];
int n;
ll dp[N];
ll Y(int j)
{
    return dp[j] + S[j] * S[j];
}
ll X(int j)
{
    return  S[j];
}
bool cmp(int k, int j, int i) // j tao tai
{   // k < j < i
    return (Y(j) - Y(k)) * (X(i) - X(j)) >=
    (Y(i) - Y(j)) * (X(j) - X(k));
}
int q[N];
ll sqr(ll x)
{
    return x * x;
}
int main()
{
    while (scanf("%d%d", &n, &M)==2) {
        S[0] = 0;
        for (int i=1;i<=n;i++) {
            int c; scanf("%d", &c);
            S[i] = S[i-1] + c;
        }
        dp[0] = 0;
        int head = 0, tail = -1;
        q[++tail] = 0;
        for (int i=1;i<=n;i++) {
            while (tail - head + 1 >= 2  ) {
                int k = q[head];
                int j = q[head+1];
                if (Y(j) - Y(k)<=2*S[i]*(X(j) - X(k))) {
                    head++;
                }
                else break;
            }
            int j = q[head];
            dp[i] = dp[j] + sqr(S[i] - S[j]) + M;
            while (tail - head + 1 >= 2) {
                int k = q[tail - 1];
                int j = q[tail];
                if (cmp(k, j, i)) tail--;
                else break;
            }
            q[++tail] = i;
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
