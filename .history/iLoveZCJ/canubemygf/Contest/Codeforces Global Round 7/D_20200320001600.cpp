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
#define int long long
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
#define CASET             \
    int ___T;             \
    scanf("%lld", &___T); \
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
char tmp[maxn];
int len[maxn];
bool check(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}
char b[maxn], aa[maxn], ss[maxn];
int p[maxn];
int lenb = 0, ans1, ans2, ret, mx, id, mm, ANS;
void WORK(int n) {
    ans1 = 0, ans2 = 0, ret = 0, mx = 0, id = 0, mm = 0, ANS = 0;
    memset(p, 0, sizeof p);
    ANS = 0;
    ss[++mm] = '^';
    ss[++mm] = '$';
    for (int i = 1; i <= n; i++) {
        ss[++mm] = aa[i];
        ss[++mm] = '$';
    }
    ss[++mm] = '%';
    for (int i = 3; i < mm; i++) {
        if (i < mx) {
            p[i] = min(p[id * 2 - i], mx - i);
        } else
            p[i] = 1;
        while (ss[i + p[i]] == ss[i - p[i]]) p[i] += 1;
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
        if (i + p[i] - 1 >= n * 2 + 1 || i - p[i] + 1 <= 3) {
            if (p[i] > ret) {
                ret = p[i];
                ANS = i;
            }
        }
    }
}
int32_t main() {
    CASET {
        scanf("%s", b + 1);
        lenb = strlen(b + 1);
        while (b[ans1 + 1] == b[lenb - ans1]) {
            if (ans1 + 1 <= lenb / 2) {
                ans1++;
            } else
                break;
        }
        for (int i = 1; i <= ans1; i++) {
            cout << b[i];
        }
        for (int i = ans1 + 1; i <= lenb - ans1; i++) {
            aa[++ans2] = b[i];
        }
        WORK(ans2);
        for (int i = ANS - ret + 1; i <= ANS + ret - 1; i++) {
            if (bool(ss[i])) cout << ss[i];
        }
        for (int i = ans1; i >= 1; --i) {
            cout << b[i];
        }
        cout << endl;
    }
}