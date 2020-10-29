#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn = 2e5 + 10;
int n, m, P, f[maxn], r[maxn];
int C(int n, int m) { return n < m ? 0 : f[n] * r[n - m] % P * r[m] % P; }
int lucas(int n, int m) {
    if (n < m) return 0;
    if (!m || n == m) return 1;
    return C(n % P, m % P) * lucas(n / P, m / P) % P;
}
int32_t main() {
    int _, i;
    // freopen("P3807_1.in","r",stdin);
    // freopen("out.txt","w",stdout);
    cin >> _;
    while (_--) {
        cin >> n >> m >> P;
        for (r[0] = r[1] = f[0] = f[1] = 1, i = 2; i < P; i++) {
            f[i] = f[i - 1] * i % P, r[i] = -r[P % i] * (P / i) % P;
            while (r[i] < 0) r[i] += P;
        }
        for (i = 2; i < P; i++) {
            r[i] = 1ll * r[i] * r[i - 1] % P;
        }
        cout << lucas(n + m, n) << endl;
    }
}