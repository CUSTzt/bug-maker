//
#include <bits/stdc++.h>
typedef double LD;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
using namespace std;
const int MAXN = 1e6 + 10;
const LD PI = acos(-1);
struct C {
    LD r, i;
    C(LD r = 0, LD i = 0) : r(r), i(i) {}
} A[MAXN], B[MAXN];
C operator+(const C& a, const C& b) { return C(a.r + b.r, a.i + b.i); }
C operator-(const C& a, const C& b) { return C(a.r - b.r, a.i - b.i); }
C operator*(const C& a, const C& b) { return C(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }

void FFT(C x[], int n, int p) {
    for (int i = 0, t = 0; i < n; ++i) {
        if (i > t)
            swap(x[i], x[t]);
        for (int j = n >> 1; (t ^= j) < j; j >>= 1);
    }
    for (int h = 2; h <= n; h <<= 1) {
        C wn(cos(p * 2 * PI / h), sin(p * 2 * PI / h));
        for (int i = 0; i < n; i += h) {
            C w(1, 0), u;
            for (int j = i, k = h >> 1; j < i + k; ++j) {
                u = x[j + k] * w;
                x[j + k] = x[j] - u;
                x[j] = x[j] + u;
                w = w * wn;
            }
        }
    }
    if (p == -1)
        FOR(i, 0, n)
    x[i].r /= n;
}

void conv(C a[], C b[], int n) {
    FFT(a, n, 1);
    FFT(b, n, 1);
    FOR(i, 0, n)
    a[i] = a[i] * b[i];
    FFT(a, n, -1);
}

int n, m , mod;
int main() {
    scanf("%d%d%d")
}