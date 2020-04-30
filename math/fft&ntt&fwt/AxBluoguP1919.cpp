// fft不同位数的乘法。A*B 看作A = 累加a*10^Pi
#include <bits/stdc++.h>
typedef double LD;
#define FOR(i, x, y) \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
using namespace std;
const int MAXN = 1e6 + 10;
const int maxn = 1e6 + 10;
const LD PI = acos(-1);
struct C {
    LD r, i;
    C(LD r = 0, LD i = 0) : r(r), i(i) {}
};
C operator+(const C& a, const C& b) { return C(a.r + b.r, a.i + b.i); }
C operator-(const C& a, const C& b) { return C(a.r - b.r, a.i - b.i); }
C operator*(const C& a, const C& b) {
    return C(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}

void FFT(C x[], int n, int p) {
    for (int i = 0, t = 0; i < n; ++i) {
        if (i > t) swap(x[i], x[t]);
        for (int j = n >> 1; (t ^= j) < j; j >>= 1)
            ;
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
    if (p == -1) FOR(i, 0, n)
    x[i].r /= n;
}

void conv(C a[], C b[], int n) {
    FFT(a, n, 1);
    FFT(b, n, 1);
    FOR(i, 0, n)
    a[i] = a[i] * b[i];
    FFT(a, n, -1);
}

int limit = 1, bit = 0;  // limit为最终扩充的长度 limit = 1<<bit
int wz[maxn << 2];
int re[maxn << 2];  //存储结果
C a[maxn << 2], b[maxn << 2];
char s1[maxn], s2[maxn];  //存储两个整数
int main() {
    scanf("%s%s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    while (limit <= len1 + len2) {
        limit <<= 1;
        bit++;
    }
    // cout << "limit === "  << limit << endl << "bit ==== " << bit << endl;
    for (int i = len1 - 1, j = 0; i >= 0; i--, j++) {
        a[j].r = s1[i] - 48;
        a[j].i = 0;
    }
    for (int i = len2 - 1, j = 0; i >= 0; i--, j++) {
        b[j].r = s2[i] - 48;
        b[j].i = 0;
    }
    // for(int i=0;i<limit;i++)
    // wz[i]=(wz[i>>1]>>1)|((i&1)<<(bit-1));
    conv(a, b, limit);
    memset(re, 0, sizeof(re));
    for (int i = 0; i <= limit; i++) {
        re[i] += (int)(a[i].r + 0.5);
        if (re[i] >= 10)  //进位
        {
            re[i + 1] += re[i] / 10;
            re[i] %= 10;
            if (i == limit) ++limit;
        }
    }
    while (!re[limit] && limit >= 1)  //去除高位的0
        limit--;
    while (limit >= 0) printf("%d", re[limit--]);
    printf("\n");
    return 0;
}