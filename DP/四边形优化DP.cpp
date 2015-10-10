#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long ll;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 2333;
LL dp[N][N], s[N];
int a[N], n, o[N][N];
vector<string> ans;
void dfs(int l, int r, string s)
{
    if (l==r) { ans.push_back(s); return; }
    dfs(l, o[l][r]-1, s+"0");
    dfs(o[l][r], r, s+"1");
}
int main()
{
    memset(dp, 63, sizeof dp);
    while (scanf("%d", &n)==1) {
        s[0] = 0;
        memset(dp, 63, sizeof dp);
        for (int i=1;i<=n;i++) scanf("%d", a+i), dp[i][i] = 0, s[i]=s[i-1]+a[i];
        for (int i=1;i<n;i++)
            dp[i][i+1]=a[i]*1LL + 1LL*a[i+1],
            o[i][i+1] = i+1;
        for (int L = 3; L <= n; L++) {
            for (int i=1;i+L-1<=n;i++) {
                int j = i + L - 1;
                for (int k=o[i][j-1]; k<=o[i+1][j]; k++) {
                    if (dp[i][j] > dp[i][k-1] + dp[k][j]) {
                        dp[i][j] = dp[i][k-1] + dp[k][j];
                        o[i][j] = k;
                    }
                }
                dp[i][j] += s[j] - s[i-1];
            }
        }
        ans.clear();
        dfs(1, n, "");
        for (auto x: ans) cout<<x<<endl;
    }
}
