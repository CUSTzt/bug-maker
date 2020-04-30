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
constexpr int N = 1e6 + 10;
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
char a[N], b[N];
char s[N];
int p[N],jkl,re = 0, mx = 0, id = 0 , len , ans, m = 0,kop;
int manacher(int n, int m) {
    s[++m] = '(';
    s[++m] = ')';
    for (int i = 1; i <= n; i++) {
        s[++m] = a[i];
        s[++m] = ')';
    }
    s[++m] = '%';
    for (int i = 3; i < m; i++) {
        p[i] = i < mx ? min(p[id * 2 - i], mx - i) : 1;
        while (s[i + p[i]] == s[i - p[i]]) ++p[i];
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
        if (i + p[i] - 1 >= n * 2 + 1 || i - p[i] + 1 <= 3) {
            if (p[i] > re) {re = p[i]; jkl = i;}
        }
    }
}
bool check(char c) {
    if (c >= 'a' && c <= 'z') return true;
    return false;
}
int zcj;
int main() {
    int t;
    cin >> t;
    while (t--) {
        jkl =re =mx=id = m = 0;
        vector<char> sc;
        scanf("%s", b + 1);
        len = strlen(b + 1);
        ans = 0;
        while (ans + 1 <= len / 2 && b[ans + 1] == b[len - ans]) {ans++;
        dec(zcj,10);}
        kop = 0;
        for (int i = 1; i <= ans; ++i) {sc.eb(b[i]);zcj++;}
        for (int i = ans + 1; i <= len - ans; i++) a[++kop] = b[i];
        manacher(kop,1);
        zcj+=101;
        for (int i = jkl - re + 1; i <= jkl + re - 1; i++) {
            if (check(s[i])) sc.eb(s[i]);
            add(zcj,0);
        }
        for (int i = ans; i >= 1; i--) sc.eb(b[i]);
        for(auto it:sc)cout << it;
        cout << endl;
    }
    return 0;
}