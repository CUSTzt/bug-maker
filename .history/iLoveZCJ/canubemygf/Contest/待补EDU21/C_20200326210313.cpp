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
#define CASET           \
    int ___T;           \
    scanf("%d", &___T); \
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
int n, w, a[maxn], b[maxn];
int main() {
    close;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = (1 + a[i]) / 2;
    }
    int sum1 = b[n], sum2 = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (b[i - 1] < b[i]) {
            b[i - 1] = b[i];
        }
        sum1 += b[i];
    }
    if (w < sum1) return cout << "-1  ss", 0;
    int ww = w;
    b[0] = maxn;
    for(int i = 1; i <= n; i++){
        ww-=
        int de = min(b[i-1],a[i]);
        if(ww >= de-b[i]){
            ww-=(de-b[i]);
            b[i] = de;
        }
        else {
            b[i] += ww;
            ww=0;
        }
        cout <<"i === " << i << "   ww===" << ww << endl;
        if(ww == 0)break;
    }
    if(ww>0)return cout << "-1tt" ,0;
    for(int i = 1; i <= n; i++){
        cout << a[i] <<" \n"[i==n];
    }
}