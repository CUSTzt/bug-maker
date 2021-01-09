//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define int long long
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
constexpr int mod = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int n, a[maxn];
const int MAXN = 3e5 + 100;
int prime[MAXN], phi[MAXN], miu[MAXN], cnt, vis[MAXN];
bool is_prime[MAXN];
// int sieve(int n)
// {
//     cout <<"kk \n";
//     int p=0;
//     for(int i=0;i<=n;i++) is_prime[i]=true;
//     is_prime[0]=is_prime[1]=false;
//     cout << "skj\n";
//     for(int i=2;i<=n;i++)
//     {
//         if(is_prime[i]) prime[++p]=i;
//         for(int j=0;j<p;j++)
//         {
//             if(prime[j]*i>n) break;
//             is_prime[prime[j]*i]=false;
//             if(i%prime[j]==0) break;
//         }
//     }
//     cout << "pp "<< endl;
//     return p;
// }
void sieve(int xt) {
    int up = 3e5;
    //    memset(vis , 0 , sizeof(vis)) ;
    vis[1] = 1;
    for (int i = 2; i <= up; i++) {
        if (!vis[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= up; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
vi v[maxn];
void ADD(int x) {
    for (int i = 1; i <= cnt; i++) {
        if (1 * prime[i] * prime[i] > x) break;
        if (x % prime[i] == 0) {
            int tp = 0;
            while (x % prime[i] == 0) {
                tp++;
                x /= prime[i];
            }
            v[prime[i]].eb(tp);
        }
    }
    if (x > 1) v[x].eb(1);
}
ll calc(int x, int y) {
    ll ans = 1ll;
    FOR(i, 1, y + 1) ans *= x;
    return ans;
}
int32_t main() {
    close;
    // cout << 1 << endl;
    sieve(MAXN - 1);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        ADD(a[i]);
    }
    int ans = 1;
    int zz = 0;
    for (int i = 1; i <= cnt; i++) {
        int x = prime[i];
        sort(v[x].begin(), v[x].end());
        if ((v[x]).size()) zz++;
        if ((v[x]).size() == n - 1) ans *= calc(x, v[x][0]);
        if ((v[x]).size() == n) ans *= calc(x, max(v[x][1], v[x][0]));
    }
    cout << ans << endl;
    // sort(a+1,a+n+1);
    // set<pii> fac;
    // int m = a[1],pp=sqrt(a[1]+0.5);
    // for(int i = 2; i <= pp;i++){
    //     if(m%i == 0){
    //         int tp = 0;
    //         while(m % i == 0){
    //             m /= i;
    //             tp++;
    //         }
    //         fac.insert({i,tp});
    //     }
    //     if(m > 1)fac.insert({m,1});
    // }
    // for(int i = 2; i <= n; i++){
    //     int m = a[i];
    //     for(auto it : fac){
    //         int tp = 0;
    //         if(m % it.fi == 0){
    //             m /= it.first;
    //             tp++;
    //         }
    //         it.second = max(it.second,tp);
    //     }
    // }
    // ll ans = 1;
    // for(auto it : fac){
    //     for(int i = 1; i <= it.second;i++){
    //         ans*= it.first;
    //     }
    // }
    // cout << ans << endl;
}