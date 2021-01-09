//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define eps 1e-8
#define fi first
#define se second
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
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
void umax(int &a, int b) {
    if (a < b) a = b;
}
void umin(int &a, int b) {
    if (a > b) a = b;
}
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int a[55][55], n, m, h[55], l[55];
int main() {
    close;
    CASET {
        memset(h, 0, sizeof h);
        memset(l, 0, sizeof h);
        memset(a, 0, sizeof a);
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if (a[i][j]) {
                    h[i] = 1;
                    l[j] = 1;
                }
            }
        int hh = 0, lli = 0;
        for (int i = 1; i <= n; i++) {
            hh += (!h[i]);
        }
        for (int i = 1; i <= m; i++) lli += (!l[i]);
        if (min(hh, lli) & 1) {
            cout << "Ashish" << endl;
        } else
            cout << "Vivek" << endl;
        // int n, m ;
        // cin >> n >> m;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         cin >> a[i][j];
        //     }
        // }
        // int heng = 0, shu = 0;
        // for(int i = 1; i <= n; i++){
        //     int fl = 1;
        //     for(int j = 1; j <= m; j++){
        //         if(a[i][j])fl = 0;
        //     }
        //     heng+=fl;
        // }
        // for(int i = 1; i <= n; i++){
        //     int fl = 1;
        //     for(int j = 1; j <= m; j++){
        //         if(a[j][i])fl = 0;
        //     }
        //     shu+=fl;
        // }
        // // cout << "heng == "<< heng << "  shu == " << shu << endl;
        // if((min(heng ,shu) & 1 )== 0){
        //     cout << "Vivek" <<endl;
        // }else {
        //     cout << "Ashish" << endl;
        // }
    }
}