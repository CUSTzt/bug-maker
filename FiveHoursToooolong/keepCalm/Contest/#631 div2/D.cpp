// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

const int N = 1e6 + 100;
int mod;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
void up() {
    int d, m;
    cin >> d >> m;
    mod = m;
    vector<int> dp(120);
    int cnt = 0;
    int dd = d;
    while (dd) {
        dd /= 2;
        cnt++;
    }
    dp[0] = 1;
    for (int i = 1; i < cnt; i++) {
        int zz = 1 << (i - 1);
        for (int j = 0; j < i; j++) {
            dp[i] += zz * dp[j] % m;
            dp[i] %= m;
        }
    }
    int zz = d - ((1 << (cnt - 1)) - 1);
    for (int j = 0; j < cnt; j++) {
        dp[cnt] = (dp[cnt] + zz * dp[j] % m) % m;
    }
    int ans = 0;
    for (int i = cnt; i > 0; i--) {
        // ans = (ans + dp[i] ) % m;
        add(ans, dp[i]);
    }
    cout << ans % m << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}