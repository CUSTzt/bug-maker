//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(),(x).end()
#define trav(a,x) for (auto& a: x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260811, P_2=999998639;
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
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
const int N = 1000010;
int n, m, i, j, k, o, x, l, d, a[N], g[N], nxt[N], t, q[N], b[N], ans[N];
bool v[N];
int cal(int x) {
    int i, k = m, t = 1;
    for (i = 2; i * i <= x; i++)
        if (x % i == 0) {
            while (x % i == 0) x /= i, t *= i;
            while (k % i == 0) k /= i, t *= i;
        }
    if (x > 1)
        for (t *= x; k % x == 0; k /= x, t *= x)
            ;
    return t;
}
int main() {
    read(n), read(m);
    for (i = 1; i <= n; i++) read(a[i]);
    for (i = 1; i <= n; i++)
        if (!v[i]) {
            t = v[i] = 1;
            for (j = a[i]; j != i; j = a[j]) v[j] = 1, t++;
            nxt[i] = g[t], g[t] = i;
        }
    for (i = 1; i <= n; i++)
        if (g[i]) {
            for (t = 0, j = g[i]; j; j = nxt[j]) q[++t] = j;
            d = gcd(l = cal(i), m);
            if (t % d) return puts("−1"), 0;
            for (x = 1; x <= t; x += d) {
                for (j = 0; j < d; j++)
                    for (k = 0, o = q[x + j]; k < i; k++, o = a[o])
                        b[(j + 1LL * k * m) % l] = o;
                for (j = 0; j < l; j++) ans[b[j]] = b[(j + 1) % l];
            }
        }
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
}
