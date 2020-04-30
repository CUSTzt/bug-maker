#include <bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, n, a) for (int i = n; i >= a; i--)
#define int long long
#define ll long long
using namespace std;
const ll INF(0x3f3f3f3f3f3f3f3fll);
const int inf(0x3f3f3f3f);

const int N = 3e3 + 10, mod = 998244353;
int len1, len2;
char s[N], t[N];
int dp[N][N];
void solve(int i, int j) {
    int len = j - i + 1;
    char c = s[len + 1];
    if (i >= 2) {
        if (i - 1 <= len2) {
            if (c == t[i - 1]) dp[i - 1][j] += dp[i][j], dp[i - 1][j] %= mod;
        } else
            dp[i - 1][j] += dp[i][j], dp[i - 1][j] %= mod;
    }
    if (j + 1 <= len1) {
        if (j + 1 <= len2) {
            if (c == t[j + 1]) dp[i][j + 1] += dp[i][j], dp[i][j + 1] %= mod;
        } else
            dp[i][j + 1] += dp[i][j], dp[i][j + 1] %= mod;
    }
}
signed main() {
    ios;
    char s[N], t[N];
int dp[N][N];
    return 0;
}
