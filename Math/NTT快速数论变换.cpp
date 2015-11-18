#include<bits/stdc++.h>
using namespace std;
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
const int N = 100100 << 1;
const int MAXN = N;
const int G = 3;
const int P = (479 << 21) + 1;
LL wn[55];
LL pmod(LL a, LL n, LL m)
{
    a %= m; LL r = 1;
    for (; n>0; n>>=1,a=a*a%m) if (n&1) r = r * a % m;
    return r;
}
void GetWn()
{
    for (int i=0;i<=21;i++) {
        int t = 1<<i;
        wn[i] = pmod(G, (P-1)/t, P);
    }
}
void NTT(LL A[], int n, int oper)
{
    for (int i=1,j=0;i<n-1;i++) {
        for (int s=n;j^=s>>=1,~j&s;);
        if (i < j) swap(A[i], A[j]);
    }
    int id = 1;
    for (int m=1;m<n;m<<=1,++id) {
        int m2 = m * 2;
        for (int i=0;i<n;i+=m2) {
            LL w = 1;
            for (int j=0;j<m;j++) {
                LL u = A[i + j] % P;
                LL t = A[i + j + m] * w % P;
                A[i + j + m] = (u - t + P) % P;
                A[i + j] = (u + t) % P;
                w  = w * wn[id] % P;
            }
        }
    }
    if (oper == -1) {
        for (int i=1;i<n/2;i++)  swap(A[i], A[n-i]);
        LL inv = pmod(n, P-2, P);
        for (int i=0;i<n;i++) A[i] = A[i] * inv % P;
    }
}
LL A[MAXN], B[MAXN];
int ans[MAXN];
char s[MAXN];
int n;
int main()
{
    GetWn();
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        for (int i=0;i<len;i++) A[i] = s[len-1-i] - '0';
        int LA = len;
        n = len;
        scanf("%s", s); len = strlen(s);
        for (int i=0;i<len;i++) B[i] = s[len-1-i] - '0';
        int LB = len;
        n = max(n, len) * 2;
        int k = 0;
        while ((1<<k) < n) k++;
        n = 1<<k;
        for (int i=LA;i<n;i++) A[i] = 0;
        for (int i=LB;i<n;i++) B[i] = 0;
        NTT(A, n, 1); NTT(B, n, 1);
        for (int i=0;i<n;i++) A[i] = A[i] * B[i] % P;
        NTT(A, n, -1);
        for (int i=n-1;i>=0;i--) ans[i]= A[i];
        int i=0;
        for (i=0;i<n-1;i++) {
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }
        int top = n-1;
        while (top > 0 && ans[top] == 0) top--;
        for (int i=top;i>=0;i--) putchar(ans[i]+'0');
        putchar(10);
    }
}
