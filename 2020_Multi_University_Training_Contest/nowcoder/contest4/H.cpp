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
#define endl '\12'
#define eb emplace_back
#define pb push_back
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
    int ret = ex_gcd(b, a % b, y, x);
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
constexpr int maxn = 1e6 + 10, N = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
// vis[x]为x对应的最小质因子
int vis[N];
int prime[N];
int cnt;
void euler_sieve(int n) {
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) prime[cnt++] = i, vis[i] = i;
        for (int j = 0; i * prime[j] <= n; j++) {
            vis[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}
 
int zz[maxn];
void up(){
    int n;
    cin >> n;
    for(int i = 0; i < n+5; i++) zz[i] = 0;
    int pos = lower_bound(prime , prime + cnt, n) - prime;
    set<int> s;
    while(prime[pos] > n) pos--;
    // cout << " max === " << prime[pos] << endl;
    // int now = prime[pos];
    vector<pair <int , int > > ans;
    for(int i = pos; i >= 0; i--){
        vi tmp; tmp.clear();
        for(int j = prime[i]; j <= n; j+=prime[i]){
            if(!zz[j]){
                zz[j] = 1;
                tmp.eb(j);
            }
        }
        // cout << "prime == " << prime[i] << "    " << tmp.size() << endl;
        if(tmp.size() & 1){
            if(tmp.size() == 1) continue;
            s.insert(tmp[1]);
            ans.eb(tmp[0], tmp[2]);
            for(int k = 3; k < tmp.size(); k+=2){
                ans.pb({tmp[k], tmp[k+1]});
            }
        }else{
            for(int k = 0; k < tmp.size(); k+=2){
                ans.pb({tmp[k], tmp[k+1]});
            }
        }
    }
    while(s.size() >= 2){
        int a = *s.begin();
        s.erase(a);
        int b = *s.begin();
        s.erase(b);
        ans.push_back({a, b});
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it.fi << ' ' << it.se << endl;
    }
}
int main() {
    close;
    euler_sieve(maxn - 5);
    CASET { up(); }
    return 0;
}