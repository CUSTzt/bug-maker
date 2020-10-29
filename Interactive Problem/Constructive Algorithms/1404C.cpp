//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <bitset>
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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto& a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) {
    ll x, y;
    ex_gcd(a, mod, x, y);
    return norm(x + mod);
}
template <class T>
inline void umin(T& x, T y) {
    x = x > y ? y : x;
}
template <class T>
inline void umax(T& x, T y) {
    x = x < y ? y : x;
}
template <class T>
inline void dec(T& x, T y) {
    x -= y;
    if (x < 0) x += mod;
}
// template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr int maxn =
    4e6 + 10;  // remember to calculate. if tle, check maxn first.
struct Node {
    int x, y, id;
};
int a[maxn], add[maxn], ans[maxn];

vector<Node> qr[maxn];
void pushdown(int o, int l, int r) {
    if (add[o]) {
        add[o << 1] += add[o], add[o << 1 | 1] += add[o];
        add[o] = 0;
    }
}
void update(int o, int l, int r, int L, int R, int v) {
    if (L <= l && R >= r) {
        add[o] += v;
        return;
    }
    pushdown(o, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(o << 1, l, mid, L, R, v);
    if (R > mid) update(o << 1 | 1, mid + 1, r, L, R, v);
}
int query(int o, int l, int r, int x) {
    if (l == r) return add[o];
    pushdown(o, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
        return query(o << 1, l, mid, x);
    else
        return query(o << 1 | 1, mid + 1, r, x);
}
int n, q;
int main() {
    close;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        qr[n - y].eb((Node){x + 1, n - y, i});
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0 && a[i] + mx >= 0) {
            int l = 1, r = i;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                int val = query(1, 1, n, mid);
                if (a[i] + val < 0)
                    r = mid - 1;
                else
                    l = mid;
            }
            update(1, 1, n, 1, l, 1);
            mx++;
        }
        for (Node& u : qr[i]) ans[u.id] = query(1, 1, n, u.x);
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}