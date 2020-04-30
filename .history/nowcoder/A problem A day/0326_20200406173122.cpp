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
constexpr int maxn = 60;
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
char a[maxn], b[maxn];
int dp[maxn][maxn][maxn][maxn];
//区间dp
int main() {
    CASET {
        scanf("%s%s", a + 1, b + 1);
        int lena = strlen(a + 1);
        int lenb = strlen(b + 1);
        int ans = 0;
        for (int i = 0; i <= lena; i++) {      // a的长度
            for (int j = 0; j <= lenb; j++) {  // b的长度
                for (int l1 = 1, r1 = l1 + i - 1; r1 <= lena; l1++, r1++) { //枚举a的起点终点部分
                    for (int l2 = 1, r2 = l2 + j - 1; r2 <= lenb; l2++, r2++) { //枚举b的起点终点部分
                        if (i + j <= 1) {
                            dp[l1][r1][l2][r2] = 1;
                        } else {
                            if(s1[l1]==s1[r1]&&r1>0) f[l1][r1][l2][r2]|=f[l1+1][r1-1][l2][r2];
                            if(s1[l1]==s2[r2]&&r2>0) f[l1][r1][l2][r2]|=f[l1+1][r1][l2][r2-1];
                            if(s2[l2]==s2[r2]&&r2>0) f[l1][r1][l2][r2]|=f[l1][r1][l2+1][r2-1];
                            if(s2[l2]==s1[r1]&&r1>0) f[l1][r1][l2][r2]|=f[l1][r1-1][l2+1][r2];
                        }
                        if (dp[l1][r1][l2][r2])
                            ans = max(ans, r1 - l1 + r2 - l2 + 2);
                    }
                }
            }
        }
    }
}