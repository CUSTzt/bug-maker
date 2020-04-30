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
int x, y, a, b, c, pp;
pii zz[maxn];
int cmp(pii a, pii b) { return a.fi > b.fi; }
int main() {
    close;
    cin >> x >> y >> a >> b >> c;
    int cnt = 0;
    for (int i = 1; i <= a; i++) {
        cin >> pp;
        zz[++cnt] = make_pair(pp,1);
    }
    for(int i = 1; i <= b; i++) {
        cin >> pp;
        zz[++cnt] = make_pair(pp,3);
    }
    for (int i = 1; i <= c; i++) {
        cin >> pp;
        zz[++cnt] = make_pair(pp,3);
    }
    sort(zz + 1, zz + cnt + 1, cmp);
    for(int i = 1; i <= cnt; i++){
        printf("zz[%d].fi == %d  zz[%d].se == %d \n",i,zz[i].fi,zz[i].se);
    }
    ll ans = 0;
    vector<pii> v;
    for (int i = 1; i <= cnt; i++) {
        if (zz[i].se == 1) {
            if (x >= 1) {
                x--;
                ans += zz[i].fi;
                cout<< "i == " << i  << "ans === " << ans << endl;
            }
        }
        if (zz[i].se == 2) {
            if (y >= 1) {
                y--;
                ans += zz[i].fi;
                cout<< "i == " << i  << "ans === " << ans << endl;
            }
        }
        if (zz[i].se == 3) {
            v.eb(zz[i]);
        }
    }
    cout << "x+y" << x+y << endl;
    for (int i = 0; i < (x + y); i++) {
        ans += v[i].fi;
        cout<< "i == " << i  << "ans === " << ans << endl;

    }
    cout << ans << endl;
}