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
#define int long long 
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
int prime[maxn], v[maxn], phi[maxn];
void euler(int n) {
    memset(v, 0, sizeof(v));  //最小质因数
    int m = 0;                //质数数量
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {  // i是质数
            v[i] = i, prime[++m] = i;
            phi[i] = i - 1;
        }
        //给当前的数i乘上一个质因数
        for (int j = 1; j <= m; j++) {
            if (prime[j] > v[i] || prime[j] > n / i)
                break;  // i有比prime[j]更小的质因数或超过n的范围，停止循环
            // prime[j]是合数i*prime[j]的最小质因子
            v[i * prime[j]] = prime[j];
            phi[i * prime[j]] =
                phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
        }
    }
}
int32_t main() {
    euler(maxn);
    int n , k ;
    cin >> n >> k;
    vector<int > factor;
    for(int i = 1; i * i <= k; i++){
        if(k % i == 0){
            factor.eb(i);
            if(i != k / i){
                factor.eb(k / i);
            }
        }
    }
    ll ans = 0;
    int si = factor.size();
    for(int i = 0; i < si; i++){
        ans += 
    }
}