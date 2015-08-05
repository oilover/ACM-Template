#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
const int N = 2333;

    int len;
    int size;
    int A[N];

#define lson (i<<1)
#define rson (i<<1|1)
void heapify(int i)
{

    int id = i;
    if (lson<=size && A[lson]>A[id]) id = lson;
    if (rson<=size && A[rson]>A[id]) id = rson;
    if (id==i) return;
    swap(A[i], A[id]);
    heapify( id);
}
void build()
{
    size = len;
    for (int i=len/2;i>=1;i--) {
        heapify( i);
    }
}
void heapsort()
{
    build();
    int n = len;
    for (int i=len;i>=2;i--) {
        swap(A[i], A[1]);
        size--;
        heapify( 1);
    }
}

int main()
{
    A[1] = 5; A[2] = 4; A[3] = 8;  A[4] = 6;
    len = 4;
    heapsort();
    for (int i=1;i<=4;i++) printf("%4d", A[i]);
}
