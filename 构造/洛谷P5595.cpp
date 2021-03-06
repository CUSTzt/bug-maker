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
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Z') {
            pos = i;
            break;
        }
    }
    int fl = 0;
    if (pos != -1)
        for (int i = pos + 1; i < n; i++) {
            if (s[i] != 'Z') fl = 1;
        }
    if (fl) return cout << -1 << endl, 0;
    string X = "", Y = "";
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            X.append("1");
            Y.append("1");
        }
        if (s[i] == 'Y') {
            X.append("1");
            Y.append("2");
        }
        if (s[i] == 'X') {
            X.append("2");
            Y.append("1");
        }
    }
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    cout << X << endl << Y ;
}