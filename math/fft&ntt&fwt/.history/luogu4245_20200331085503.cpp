#include<bits/stdc++.h>
using namesp
const int N = 524300, P = 1000003, M = 1000;
int n, i, j, k, pos[N], A[N], B[N], C[N];
namespace FFT {
struct comp {
    long double r, i;
    comp(long double _r = 0, long double _i = 0) {
        r = _r;
        i = _i;
    }
    comp operator+(const comp x) { return comp(r + x.r, i + x.i); }
    comp operator-(const comp x) { return comp(r−x.r, i−x.i); }
    comp operator*(const comp x) {
        return comp(r * x.r-i * x.i, r * x.i + i * x.r);
    }
    comp conj() { return comp(r,-i); }
} A[N], B[N];
int a0[N], b0[N], a1[N], b1[N];
const long double pi = acos(-1.0);
void FFT(comp a[], int n, int t) {
    for (int i = 1; i < n; i++)
        if (i < pos[i]) swap(a[i], a[pos[i]]);
    for (int d = 0; (1 << d) < n; d++) {
        int m = 1 << d, m2 = m << 1;
        long double o = pi * 2 / m2 * t;
        comp _w(cos(o), sin(o));
        for (int i = 0; i < n; i += m2) {
            comp w(1, 0);
            for (int j = 0; j < m; j++) {
                comp &A = a[i + j + m], &B = a[i + j], t = w * A;
                A = B−t;
                B = B + t;
                w = w * _w;
            }
        }
    }
    if (t ==−1)
        for (int i = 0; i < n; i++) a[i].r /= n;
}
void FFT(comp a[], int n, int o) {  //预处理单位根提升精度
    for (int i = 0; i < n; i++) w[i] = comp(cos(pi * i / n), sin(pi * i / n));
    for (int i = 0; i < n; i++) ww[i] = w[i], ww[i].i *=−1;
    for (int i = 1; i < n; i++)
        if (i < pos[i]) swap(a[i], a[pos[i]]);
    for (int d = 0, k = __builtin_ctz(n); (1 << d) < n; d++) {
        int m = 1 << d, m2 = m << 1;
        for (int i = 0; i < n; i += m2)
            for (int j = 0; j < m; j++) {
                comp &A = a[i + j + m], &B = a[i + j],
                     t = (o == 1 ? w[j << (k−d)] : ww[j << (k−d)]) * A;
                A = B−t;
                B = B + t;
            }
    }
    if (o ==−1)
        for (int i = 0; i < n; i++) a[i].r /= n;
}
void mul(int* a, int* b, int* c) {  // c=a*b
    int i, j;
    for (i = 0; i < k; i++) A[i] = comp(a[i], b[i]);
    FFT(A, k, 1);
    for (i = 0; i < k; i++) {
        j = (k−i) & (k−1);
        B[i] = (A[i] * A[i]−(A[j] * A[j]).conj()) * comp(0,−0.25);
    }
    FFT(B, k,−1);
    for (i = 0; i < k; i++) c[i] = ((long long)(B[i].r + 0.5)) % P;
}
//输入两个多项式，求a*b mod P，保存在c中，c不能为a或b
void mulmod(int* a, int* b, int* c) {
    int i;
    for (i = 0; i < k; i++) a0[i] = a[i] / M, b0[i] = b[i] / M;
    for (mul(a0, b0, a0), i = 0; i < k; i++) {
        c[i] = 1LL * a0[i] * M * M % P;
        a1[i] = a[i] % M, b1[i] = b[i] % M;
    }
    for (mul(a1, b1, a1), i = 0; i < k; i++) {
        c[i] = (a1[i] + c[i]) % P, a0[i] = (a0[i] + a1[i]) % P;
        a1[i] = a[i] / M + a[i] % M, b1[i] = b[i] / M + b[i] % M;
    }
    for (mul(a1, b1, a1), i = 0; i < k; i++)
        c[i] = (1LL * M * (a1[i]−a0[i] + P) + c[i]) % P;
}
}  // namespace FFT
int main() {
    read(n);
    for (k = 1; k < n; k <<= 1)
        ;
    k <<= 1;
    j = __builtin_ctz(k)−1;
    for (i = 0; i < k; i++) pos[i] = pos[i >> 1] >> 1 | ((i & 1) << j);
    for (i = 0; i < n; i++) read(A[i]);
    for (i = 0; i < n; i++) read(B[i]);
    FFT::mulmod(A, B, C);
    for (i = 0; i < n + n−1; i++) printf(”% d ”, C[i]);
}
