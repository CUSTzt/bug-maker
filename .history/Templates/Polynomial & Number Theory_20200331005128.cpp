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
    // Attention : a and b may be negative
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
    // 卡常Euclid
    inline int ctz(ll x) { return __builtin_ctzll(x); }
    ll quick_gcd(ll a, ll b) {
        if (!a) return b;
        if (!b) return a;
        int t = ctz(a | b);
        a >>= ctz(a);
        do {
            b >>= ctz(b);
            if (a > b) swap(a, b);
            b -= a;
        } while (b);
        return a << t;
    }

    ll inv(ll a, ll p = P) {
        ll x, y;
        ex_gcd(a, p, x, y);
        if (x < 0) x += p;
        return x;
    }

    template <class Integer>
    bool quadRes(Integer a, Integer b) {
        if (a <= 1) return true;
        while (a % 4 == 0) a /= 4;
        if (a % 2 == 0) return (b % 8 == 1 || b % 8 == 7) == quadRes(a / 2, b);
        return ((a - 1) % 4 == 0 || (b - 1) % 4 == 0) == quadRes(b % a, a);
    }

    // assume p in prime, x in quadratic residue
    int sqrt(int x, int p = P) {
        if (p == 2 || x <= 1) return x;
        int w, v, k = (p + 1) / 2;
        do {
            w = rng() % p;
        } while (quadRes(v = int((w * (ll)w - x + p) % p), p));
        _P2_Field res(1, 0), a(w, 1);
        while (k) {
            if (k & 1)
                res = _P2_Field(
                    (res.first * (ll)a.first +
                     res.second * (ll)a.second % p * v) %
                        p,
                    (res.first * (ll)a.second + res.second * (ll)a.first) % p);
            if (k >>= 1)
                a = _P2_Field(
                    (a.first * (ll)a.first + a.second * (ll)a.second % p * v) %
                        p,
                    (a.first * (ll)a.second << 1) % p);
        }
        return min(res.first, p - res.first);
    }
};