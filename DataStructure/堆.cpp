#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
const int N = 2333;

    int len; // array
    int size;  //heap
    int A[N];

#define lson (i<<1)
#define rson (i<<1|1)
void sink(int i) // da gen dui
{
    int id = i;
    if (lson<=size && A[lson]>A[id]) id = lson;
    if (rson<=size && A[rson]>A[id]) id = rson;
    if (id==i) return;
    swap(A[i], A[id]);
    sink( id);
}
void build()
{
    size = len;
    for (int i=size/2;i>=1;i--) {
        sink( i);
    }
}
void jump(int v) {
    if (v==1) return;
    if (A[v/2] < A[v]) {
        A[v/2] = A[v];
        jump(v/2);
    }
}
void insert(int x) {
    A[++size] = x;
    jump(size);
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
