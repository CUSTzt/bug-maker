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

    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    // Finds the Greatest Common Divisor to the integers a and b.
    // Euclid also finds two integers x and y, such that ax + by = gcd(a,b).
    // a and b may be negative
    // If a and b are coprime, then x is the inverse of a (mod b).
    ll ex_gcd(ll a, ll b, ll& x, ll& y) {
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