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
int main() {
    close;
    CASET {
        int n;
        cin >> n;
        vi v1[10], v2[10];
        for (int i = 1; i <= n; i++) {
            for (int j = 7; j >= 0; --j) {
                if ((i - 1) & (1 << j))
                    v2[j].eb(i);
                else
                    v1[j].eb(i);
            }
        }
        int ans = 0;
        for (int i = 0; i <= 6; i++) {
            if (v1[i].size() == 0 || v2[i].size() == 0) {
                continue;
            }
            cout << v1[i].size() << ' ' << v2[i].size() << " ";
            for(int j = 0; j < v1[i].size();j++){
                cout << v1[i][j] << ' ';
            }
            for(int j = 0; j < v2[i].size();j++){
                cout << v2[i][j] << " ";
            }cout << endl;
            int x;
            cin >> x ;
            ans = max(ans , x);
        }
        cout << -1 << " " << ans << endl;
    }