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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
// #define int long long
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
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
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
    return;
}
template <typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}
template <class T>
inline void umin(T &x, T y) {
    x = x > y ? y : x;
}
template <class T>
inline void umax(T &x, T y) {
    x = x < y ? y : x;
}
template <class T>
inline void dec(T &x, T y) {
    x -= y;
    if (x < 0) x += mod;
}
template <class T>
inline void add(T &x, T y) {
    x += y;
    if (x >= mod) x -= mod;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    int d = exgcd(b, a % b, x, y), t = x;
    return x = y, y = t - a / b * y, d;
}
void print(ll c, ll d, ll e, ll f) {
    ll d1 = __gcd(c, d), d2 = __gcd(e, f);
    printf("%lld %lld %lld %lld\n", c / d1, d / d1, e / d2, f / d2);
}
pair<int, int> f[maxn];
void up() {
    int a, b;
    scanf("%d%d",&a,&b);
    if (b == 1) {
        puts("-1 -1 -1 -1");
        return;
    }
    int bb = b, tot = 0;
    int fuck = sqrt(bb + 0.5);
    for (int32_t i = 2; i <= fuck; ++i) {
        if (bb % i == 0) {
            int c = 0;
            while (bb % i == 0) bb /= i, ++c;
            f[++tot] = make_pair(i, c);
        }
    }
    if (bb > 1) f[++tot] = make_pair(bb, 1);
    if (tot == 1) {
        if (a % f[1].fi != 0) {
            puts("-1 -1 -1 -1");
        } else {
            int tmp = a / f[1].fi;
            print(tmp + 1, b / f[1].fi, 1, b / f[1].fi);
        }
    } else {
        int u = 1, v = 1;
        for (int i = 1; i <= f[1].se; i++) u *= f[1].fi;
        v = b / u;
        LL x, y;
        exgcd(v, u, x, y);
        if (y > 0) {
            LL tmp = (y + v - 1) / v;
            y -= tmp * v, x += tmp * u;
        }
        if (x < 0) {
            LL tmp = (-x + u - 1) / u;
            y -= tmp * v, x += tmp * u;
        }
        x *= a, y *= a;
        if (x > 0 && y < 0)
            print(x, u, -y, v);
        else
            puts("-1 -1 -1 -1");
    }
}
int32_t main() {
    CASET { up(); }
    return 0;
}