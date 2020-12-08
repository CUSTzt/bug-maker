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
namespace SegmentTree {
#define mid ((l + r) >> 1)
#define ls k << 1
#define rs k << 1 | 1
#define lson ls, l, mid
#define rson rs, mid + 1, r
struct Node {
    int l, r, mn, mx;
} tr[maxn << 2];
void build(int k, int l, int r) {
    tr[k].l = l, tr[k].r = r;
    if (l == r) {
        cin >> tr[k].mx;
        tr[k].mn = tr[k].mx;
        return;
    }
    build(lson);
    build(rson);
    tr[k].mx = max(tr[ls].mx, tr[rs].mx);
    tr[k].mn = min(tr[ls].mn, tr[rs].mn);
}
int query_min(int k, int l, int r) {
    if (tr[k].l > r || tr[k].r < l) {
        return INF;
    }
    if (tr[k].l >= l && tr[k].r <= r) {
        return tr[k].mn;
    }
    return min(query_min(ls, l , r), query_min(rs, l , r));
}
int query_max(int k, int l, int r) {
    if (tr[k].l > r || tr[k].r < l) {
        return -INF;
    }
    if (tr[k].l >= l && tr[k].r <= r) {
        return tr[k].mx;
    }
    return max(query_max(ls, l , r), query_max(rs, l , r));
}
}  // namespace SegmentTree

int main() {
    close;
    CASET {
        int n;
        cin >> n;
        SegmentTree::build(1, 1, n);
        for (int x = 1; x < n - 1; x++) { // 枚举第一个断点x
            int l = x + 1, r = n - 1;//二分第二个断点y   区间分为了三段：[1,x][x+1,y][y+1,n]
            int mx1 = SegmentTree::query_max(1, 1,x);
            while(l <= r){
                int y = (l+r)>>1;
                int mnn = SegmentTree::query_min(1, x+1, y);
                int mxx = SegmentTree::query_max(1, y+1, n);
                if(mx1 < mnn || mx1<mxx){
                    l = y+1;
                }else if(mx1 >mnn || mx1 >mxx){
                    r = y-1;
                }else{
                    cout << "YES\n";cout << x<< " " << y-x << " " << n-y <<endl;
                    goto end; 
                }
            }
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}