//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
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
#define trav(a, x) for (auto &a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close                                                              \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), \
        cout << fixed << setprecision(10)
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
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
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
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr int maxn =
    1e6 + 10;  // remember to calculate. if tle, check maxn first.
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
const int N = 200010, M = 524289;
int n, m, cnt, i, a[N], op[N][4], b[N];
int lower(int x) {
    int l = 1, r = cnt, t, mid;
    while (l <= r)
        if (b[mid = (l + r) >> 1] <= x)
            l = (t = mid) + 1;
        else
            r = mid - 1;
    return t;
}
struct node {
    int val, cnt, sum, p;
    node *l, *r;
    node() {
        val = sum = cnt = p = 0;
        l = r = NULL;
    }
    inline void up() { sum = l->sum + r->sum + cnt; }
} *blank = new (node), *T[M], pool[2000000], *cur;
void Rotatel(node *&x) {
    node *y = x->r;
    x->r = y->l;
    x->up();
    y->l = x;
    y->up();
    x = y;
}
void Rotater(node *&x) {
    node *y = x->l;
    x->l = y->r;
    x->up();
    y->r = x;
    y->up();
    x = y;
}
void Ins(node *&x, int y, int p) {
    if (x == blank) {
        x = cur++;
        x->val = y;
        x->l = x->r = blank;
        x->sum = x->cnt = 1;
        x->p = std::rand();
        return;
    }
    x->sum += p;
    if (y == x->val) {
        x->cnt += p;
        return;
    }
    if (y < x->val) {
        Ins(x->l, y, p);
        if (x->l->p > x->p) Rotater(x);
    } else {
        Ins(x->r, y, p);
        if (x->r->p > x->p) Rotatel(x);
    }
}
int Ask(node *x, int y) {  // ask how many <= y
    int t = 0;
    while (x != blank)
        if (y < x->val)
            x = x->l;
        else
            t += x->l->sum + x->cnt, x = x->r;
    return t;
}
void add(int v, int i, int p) {
    int a = 1, b = cnt, mid, f = 1, x = 1;
    while (a < b) {
        if (f) Ins(T[x], i, p);
        mid = (a + b) >> 1;
        x <<= 1;
        if (f = v <= mid)
            b = mid;
        else
            a = mid + 1, x |= 1;
    }
    Ins(T[x], i, p);
}
int kth(int l, int r, int k) {
    int x = 1, a = 1, b = cnt, mid;
    while (a < b) {
        mid = (a + b) >> 1;
        x <<= 1;
        int t = Ask(T[x], r) - Ask(T[x], l - 1);
        if (k <= t)
            b = mid;
        else
            k -= t, a = mid + 1, x |= 1;
    }
    return a;
}
void build(int x, int a, int b) {
    T[x] = blank;
    if (a == b) return;
    int mid = (a + b) >> 1;
    build(x << 1, a, mid), build(x << 1 | 1, mid + 1, b);
}
int main() {
    // freopen("inn.txt","r",stdin);
    blank->l = blank->r = blank;
    while (~scanf("%d", &n)) {
        read(m);
        cur = pool;
        for (i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
        cnt = n;
        for (i = 1; i <= m; i++) {
            // read(op[i][0]),
            op[i][0] = 2;
            read(op[i][1]), read(op[i][2]);
            if (op[i][0] == 1)
                b[++cnt] = op[i][2];
            else
                read(op[i][3]);
        }
        sort(b + 1, b + cnt + 1);
        for (i = 1; i <= n; i++) a[i] = lower(a[i]);
        for (i = 1; i <= m; i++)
            if (op[i][0] == 1) op[i][2] = lower(op[i][2]);
        build(1, 1, cnt);
        for (i = 1; i <= n; i++) add(a[i], i, 1);
        for (i = 1; i <= m; i++) {
            if (op[i][0] == 1)
                add(a[op[i][1]], op[i][1], -1),
                    add(a[op[i][1]] = op[i][2], op[i][1], 1);
            else
                printf("%d\n", b[kth(op[i][1], op[i][2], op[i][3])]);
        }
    }
}
