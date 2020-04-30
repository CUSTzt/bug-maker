#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define int long long 
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
const int N = 1e6 + 100;
int a[N], num[N], cnt[N];
int pre[N], suf[N], pcnt[N], scnt[N];
int ans = 1e18;
int32_t main() {
    int n, k, m = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int S = 0;
    for (int i = 1; i <= n; i++) {
        S++;
        if (a[i] != a[i + 1]) {
            m++;
            num[m] = a[i], cnt[m] = S;
            S = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + pcnt[i - 1] * (num[i] - num[i - 1]) +
                 cnt[i - 1] * (num[i] - num[i - 1] - 1);
        pcnt[i] = pcnt[i - 1] + cnt[i - 1];
    }
    for (int i = m - 1; i >= 1; i--) {
        suf[i] = suf[i + 1] + scnt[i + 1] * (num[i + 1] - num[i]) +
                 cnt[i + 1] * (num[i + 1] - num[i] - 1);
        scnt[i] = scnt[i + 1] + cnt[i + 1];
    }
    for (int i = 1; i <= m; i++) {
        int res = k - cnt[i];
        if (res <= 0) {
            puts("0");
            return 0;
        }
        if (i > 1 && i < m) ans = min(ans, pre[i] + suf[i] + res);

        if (i > 1 && pcnt[i] >= res) ans = min(ans, pre[i] + res);

        if (i < m && scnt[i] >= res) ans = min(ans, suf[i] + res);
    }
    return cout << ans << endl,0;
    
}