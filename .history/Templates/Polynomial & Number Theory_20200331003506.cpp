// Polynomial & Number Theory

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

constexpr int P = 998244353, R = 3;

ll bin(ll x, ll n, ll MOD) {
    ll ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}

struct NumberTheory {
    typedef pair<int, int> pii;

    mt19937 rng;
    NumberTheory()
        : rng(chrono::steady_clock::now().time_since_epoch().count) {}

    int ex_gcd(int a, int b, int& x, int& y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        int ret = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return ret;
    }
};