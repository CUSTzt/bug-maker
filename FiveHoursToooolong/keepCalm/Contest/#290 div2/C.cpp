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
constexpr int maxn = 100 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;

int n, du[maxn], a[maxn][maxn], len[maxn];
char s[maxn][maxn];
vi ans;
int topo(){
    for(int k = 1; k <= 26; k++){
        int pos = -1;
        for(int i = 0; i < 26; i++){
            if(du[i] == 0){
                pos = i;
                // cout << "pos === " << pos << "    du[" << i << "] === " << du[i] << endl;
                break;
            }
        }
        if(pos == -1)return 0;
        ans.eb(pos);
        // cout << "push  " << pos << endl;
        du[pos] = -1;
        for(int i = 0; i < 26; i++){
            if(a[pos][i])du[i]--;
        }
    }
    return 1;
}
int main() {
    close;
    int fl = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> (s[i] + 1), len[i] = strlen(s[i] + 1);
    for (int i = 2; i <= n; i++) {
        int l1 = len[i - 1], l2 = len[i];
        int j;
        for (j = 1; j <= min(l1, l2); j++) {
            int aa = s[i - 1][j] - 'a', bb = s[i][j] - 'a';
            if (aa != bb) {
                if (a[aa][bb] == 0) {
                    du[bb]++;
                    a[aa][bb] = 1;
                }
                break;
            }
        }
        if (j == min(l1 + 1, l2 + 1) && l1 > l2) {
            fl = 1;
            break;
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = i+1; j <26; j++){
            if(a[i][j] && a[j][i]){
                cout << "Impossible\n";return 0;
            }
        }
    }
    if(fl){
        cout << "Impossible\n";
        return 0;
    }
    if(topo()){
        for(auto it : ans) {
            cout << char(it+'a');
        }
    }else {
        cout << "Impossible\n";
    }
    return 0;
}