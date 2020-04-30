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
#define eps 1e-8
#define int long long
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
int sss(int x) { return x * x; }

int calc(int x, int y, int z) {
    return ((sss(x - y) + sss(x - z) + sss(y - z)));
}
void solve1() {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<int> r(nr + 1), g(ng + 1), b(nb + 1);
    vector<int> y, z;
    for (int i = 1; i <= nr; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= ng; i++) {
        cin >> g[i];
        y.eb(g[i]);
    }
    for (int i = 1; i <= nb; i++) {
        cin >> b[i];
        z.eb(b[i]);
    }
    SORT_UNIQUE(y), SORT_UNIQUE(z);

    int ans = linf;
    for (int i = 1; i <= nr; i++) {
        int it = lower_bound(y.begin(), y.end(), r[i]) - y.begin();
        if (it != y.size()) {
            int tp = (r[i] + g[it]) / 2;
            int iq = lower_bound(z.begin(), z.end(), r[i]) - z.begin();
            int x1 = g[i], x2 = r[it], x3 = b[iq];
            ans = min(ans, calc(x1, x2, x3));
        }
    }
}

int nr, ng, nb;

int cc(vector<int> a, int nn1, vector<int> b, int nn2, vector<int> c, int nn3) {
    int res = linf;
    for (int i = 0; i < nn1; i++) {
        int LE = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int RI = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        if (LE >= nn2 || b[LE] > a[i]) {
            if (LE > 1) --LE;
        }
        if (LE < nn2 && RI < nn3) {
            int t1 = a[i];
            int t2 = b[LE];
            int t3 = c[RI];
            res = min(res, calc(t1, t2, t3));
        }
        LE = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        RI = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        if (LE >= nn3 || c[LE] > a[i]) {
            if (LE > 1) LE--;
        }

        if (LE < nn3 & RI < nn2) {
            int t1 = a[i];
            int t2 = c[LE];
            int t3 = b[RI];
            res = min(res, calc(t1, t2, t3));
        }
    }
    return res;
}
void solve2() {
    cin >> nr >> ng >> nb;
    vector<int> r(nr), g(ng), b(nb);
    vector<int> y, z;
    for (int i = 0; i < nr; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < ng; i++) {
        cin >> g[i];
        y.eb(g[i]);
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
        z.eb(b[i]);
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    int zz = linf;
    zz = min(zz, cc(r, nr, b, nb, g, ng));
    zz = min(zz, cc(b, nb, r, nr, g, ng));
    zz = min(zz, cc(g, ng, r, nr, b, nb));
    cout << zz << endl;
}

int a[maxn], b[maxn], c[maxn], nn1, nn2, nn3;
int FUCK(int *a, int *b, int *c, int nn1, int nn2, int nn3) {
    int res = linf;
    FOR(i, 1, 1+nn1) {
        int LE = lower_bound(b + 1, b + 1 + nn2, a[i]) - b;
        int RI = lower_bound(c + 1, c + 1 + nn3, a[i]) - c;
        int t1, t2 , t3;
        // if (LE > nn3 || c[LE] > a[i]) {
        //     if (LE > 1) LE--;
        // }

        // if (LE <= nn3 & RI <= nn2) {
        //     t1 = a[i],t2 = c[LE],t3 = b[RI];
        //     res = min(res, calc(t1, t2, t3));
        // }
        if (LE > nn2 || b[LE] > a[i]) {
            if (LE > 1) LE-=1;
        }
        if (LE <= nn2 && RI <= nn3) {
            t1 = a[i],t2 = b[LE],t3 = c[RI];
            res = min(res, calc(t1, t2, t3));
        }
        LE = lower_bound(c + 1, c + 1 + nn3, a[i]) - c;
        RI = lower_bound(b + 1, b + 1 + nn2, a[i]) - b;

        if (LE > nn3 || c[LE] > a[i]) {
            if (LE > 1) LE--;
        }

        if (LE <= nn3 & RI <= nn2) {
            t1 = a[i],t2 = c[LE],t3 = b[RI];
            res = min(res, calc(t1, t2, t3));
        }
    }
    return res;
}
void solve3() {
    cin >> nn1 >> nn2 >> nn3;
    FOR(i, 1, nn1 + 1) cin >> a[i];
    FOR(i, 1, nn2 + 1) cin >> b[i];
    FOR(i, 1, nn3 + 1) cin >> c[i];
    sort(a + 1, a + 1 + nn1);
    sort(b + 1, b + 1 + nn2);
    sort(c + 1, c + 1 + nn3);
    int zz = linf;
    zz=min(zz,FUCK(c,a,b,nn3,nn1,nn2));
    zz=min(zz,FUCK(a,b,c,nn1,nn2,nn3));
    zz=min(zz,FUCK(b,a,c,nn2,nn1,nn3));
    cout << zz << endl;
}
int32_t main() {
    close;
    CASET { solve3(); }
}