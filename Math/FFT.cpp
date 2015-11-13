typedef complex<double> Complex;
const double PI = acos(-1.0);
const int MAXN = 100100 << 2;
// oper = 1 FFT     oper = -1 逆FFT
void FFT(Complex A[], int n, int oper) 
{
    for (int i=1,j=0;i<n-1;i++) {
        for (int s=n;j^=s>>=1,~j&s;);
        if (i < j) swap(A[i], A[j]);
    }
    for (int m=1;m<n;m<<=1) {
        int m2 = m * 2;
        double a = oper * PI / m;
        Complex unit = Complex(cos(a), sin(a));
        for (int i=0;i<n;i+=m2) {
            Complex w = 1;
            for (int j=0;j<m;j++) {
                Complex t = A[i + j + m] * w;
                Complex u = A[i + j];
                A[i + j + m] = u - t;
                A[i + j] = u + t;
                w *= unit;
            }
        }
    }
    if (oper == -1) for (int i=0;i<n;i++) A[i]/=n;
}
