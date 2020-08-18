ll n, k, dp[maxn][2], a[maxn], b[maxn];
ll up(ll *a, int len) {
    ll res = 1, last = 0;
    for (ll i = 1; i <= len; i++) {
        if (a[i] == -1)
            continue;
        else {
            if (i == 1) {
                last = i;
                continue;
            }
            if (!last) {
                res = res * (dp[i - 2][0] + (k - 1) * dp[i - 2][1]) % mod;
            } else {
                if (a[i] == a[last]) {
                    res = res * dp[i - last - 1][0] % mod;
                } else {
                    res = res * dp[i - last - 1][1] % mod;
                }
            }
            last = i;
        }
    }
    if (!last) {
        res = k;
        for (int i = 2; i <= len; i++) {
            res = (res * (k - 1)) % mod;
        }
    } else if (len != last) {
        res = res * (dp[len - last - 1][0] + (k - 1) * dp[len - last - 1][1] % mod) % mod;
    }
    return res;
}
int main() {
    close;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i & 1)
            cin >> a[(i + 1) >> 1];
        else
            cin >> b[i >> 1];
    }
    dp[0][0] = 0, dp[0][1] = 1;
    for (int i = 1; i <= ((n + 1) >> 1); i++) {
        if (i & 1) {
            dp[i][0]=(1ll*dp[i/2][0]*dp[i/2][0]%mod+dp[i/2][1]*dp[i/2][1]%mod*(k-1)%mod)%mod;
            dp[i][1]=(1ll*dp[i/2][0]*dp[i/2][1]*2%mod+(k-2)*dp[i/2][1]%mod*dp[i/2][1]%mod)%mod;
        } else {
            dp[i][0]=((k-1)%mod*dp[i - 1][1]%mod)%mod;
            dp[i][1]=(dp[i-1][0]+(k-2)*dp[i-1][1]%mod)%mod;
        }
    }
    cout << up(a, (n + 1) / 2) * up(b, n - (n + 1) / 2) % mod << endl;
    return 0;
}