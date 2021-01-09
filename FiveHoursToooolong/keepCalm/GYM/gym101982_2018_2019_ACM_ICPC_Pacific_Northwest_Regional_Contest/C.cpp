// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back

const int N = 3e3 + 100;
const int mod = 998244353;
ll dp[N][N], n, k, cnt, a[N], kp;
map<ll, ll> mp;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> kp;
        if (mp.count(kp) == 0) {
            mp[kp] = ++cnt;
            a[cnt] = 1;
        } else {
            a[mp[kp]]++;
        }
    }
    //dp[i][j] 前i种选了j种的方案数
    for (int i = 0; i <= cnt; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = ((dp[i][j] + 1ll * dp[i - 1][j - 1] * a[i] % mod) % mod + 1ll * dp[i - 1][j]) % mod;
        }
    }
    cout << dp[cnt][k] % mod << endl;
    return 0;
}