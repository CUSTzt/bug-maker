// Polynomial & Number Theory
// farm plz
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __uint128_t;

constexpr int P = 99824435, R = 3;

ll bin(ll x, ll n, ll MOD) {
    ll ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
