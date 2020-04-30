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
    cin >> s + 1 >> t + 1;
    len1 = strlen(s + 1);
    len2 = strlen(t + 1);
    rep(i, 1, len1) {
        char c = s[1];
        if (i <= len2) {
            if (c == t[i]) dp[i][i] = 2;
        } else
            dp[i][i] = 2;
    }
    rep(len, 1, len1 - 1) rep(i, 1, len1) {
        int j = i + len - 1;
        if (j > len1) break;
        solve(i, j);
    }
    int ans = 0;
    rep(i, len2, len1) ans = (ans + dp[1][i]) % mod;
    cout << ans << '\n';
    return 0;
}
