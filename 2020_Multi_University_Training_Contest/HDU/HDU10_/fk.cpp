// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;
constexpr int threshold = 10000000;
using ull = unsigned long long;
unsigned long long k1, k2;
int n, m;
long long a[threshold << 1], b[threshold << 1];
unsigned long long xorShift128Plus() {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
void gen(int n, ull _k1, ull _k2) {
    k1 = _k1, k2 = _k2;
    for (int i = 1; i <= n; i++) {
        a[i] = xorShift128Plus() % threshold + 1;
        b[i] = xorShift128Plus() % threshold + 1;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    while (cin >> n >> m >> k1 >> k2) {
        gen(n, k1, k2);
        ull ans = 0;
        
        // for (int i = 1; i <= n; i++) {
        //     cout << a[i] << " \n"[i == n];
        // }
        // for (int i = 1; i <= n; i++) {
        //     cout << b[i] << " \n"[i == n];
        // }
        return 0;
    }
}