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
int l[maxn], r[maxn], a[maxn], d[maxn], sum[maxn];
int n, q;
int main() {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        a[l[i]]++;
        a[r[i] + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    memcpy(d, a, sizeof d);
    int ans = -1;
    for (int j = 1; j <= q; j++) {
        for (int i = 0; i <= n + 10; i++) {
            sum[i] = 0;
        }
        for (int i = l[j]; i <= r[j]; i++) {
            if (a[i] >= 1) d[i]--;
        }
        int cnt = n;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 0) {
                cnt--;
            }
            if (d[i] == 1) {
                sum[i] = 1;
            }
            sum[i] += sum[i - 1];
        }
        int mx = INF;
        for (int i = 1; i <= q; i++) {
            if (i == j) continue;
            int g = sum[r[i]] - sum[l[i] - 1];
            mx = max(mx, g);
        }
        if(cnt - mx > ans){
            ans = cnt-mx;
        }
        for(int i = l[j]; i <= r[j];i++){
            d[i] = a[i];
        }
    }cout << ans << endl;
}