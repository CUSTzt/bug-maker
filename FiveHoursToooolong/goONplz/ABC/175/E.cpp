// can i beat Mod Love?
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
typedef long long ll;
ll bin(ll x, ll n, ll MOD) {
    ll ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;
    return ret;
}
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = acos(-1.0);
constexpr ll mod = 1e9 + 7;
constexpr int maxn = 3333; // remember to calculate.
ll n, m, k, x, y, z, dp[maxn][maxn][4], a[maxn][maxn], f[maxn][maxn];
ll solve(int x, int y, int h) {
    if(x > n || y > m || h > 3)
        return -linf;
    if(x == n && y == m) {
        if(h < 3 && f[x][y])
            return a[x][y];
        return 0;
    }
    if(dp[x][y][h] != -1)
        return dp[x][y][h];
    ll ans = -linf;
    ans = max(ans, solve(x, y + 1, h));
    ans = max(ans, solve(x + 1, y, 0));
    if(f[x][y] && h < 3) {
        ans = max(ans, solve(x, y + 1, h + 1) + a[x][y]);
        ans = max(ans, solve(x + 1, y, 0) + a[x][y]);
    }
    return dp[x][y][h] = ans;
}
int main() {
    close;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        cin >> x >> y >> z;
        a[x][y] = z;
        f[x][y] = 1;
    }
    memset(dp, 0xff, sizeof dp);
    cout << solve(1, 1, 0) << endl;
    return 0;
}
