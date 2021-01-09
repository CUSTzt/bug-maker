#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using LL = long long;
#define int long long
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET    \
    int ___T;    \
    cin >> ___T; \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int a[maxn], b[maxn], c[maxn], n1, n2, n3;
int sq(int x) { return x * x; }
int calc(int x, int y, int z) { return sq(x - y) + sq(x - z) + sq(y - z); }
bool Min(ll &a, ll b) {
    if (b < a) return a = b, 1;
    return 0;
}
ll f(std::set<ll>& s,ll x)
{
    auto it=s.lower_bound(x);
    if(it!=s.end())
    {
        if(it==s.begin())return *it;
        auto p=it--;
        return (*p)-x<x-*it?*p:*it;
    }
    else return *--it;
}
// ll f(set<int> s, int x) {
//     auto p = s.lower_bound(x);
//     if (p != s.end()) {
//         if (p == s.begin()) {
//             return *p;
//         }
//         auto pp = p--;
//         //return *p;
//         return (*pp)-x<x-*p?*pp:*p;
//     }
//     return *(--p);
// }
void slove() {
    set<int> y, z;
    cin >> n1 >> n2 >> n3;
    int ans = linf;
    for (int i = 1; i <= n1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n2; i++) {
        cin >> b[i];
        y.insert(b[i]);
    }
    for (int i = 1; i <= n3; i++) {
        cin >> c[i];
        z.insert(c[i]);
    }
    for (int i = 1; i <= n1; i++) {
        auto it1 = y.lower_bound(a[i]);
        if (it1 != y.end()) {
            ll p = f(z, (a[i] + *it1) / 2);
            Min(ans, calc(a[i], p, *it1));
        }
        if (it1 != y.begin()) {
            ll p = f(z, (a[i] + *(--it1)) / 2);
            Min(ans, calc(a[i], p, *it1));
        }
        it1 = z.lower_bound(a[i]);
        if (it1 != z.end()) {
            ll p = f(y, (a[i] + *it1) / 2);
            Min(ans, calc(a[i], p, *it1));
        }
        if (it1 != z.begin()) {
            ll p = f(y, (a[i] + *(--it1)) / 2);
            Min(ans, calc(a[i], p, *it1));
        }
    }
    cout << ans << endl;
}
int32_t main() {
    CASET { slove(); }
}