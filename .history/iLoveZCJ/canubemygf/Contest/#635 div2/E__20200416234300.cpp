// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3100;
const int mod = 998244353;
char s[N], t[N];
ll dp[N][N];
void add(ll &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> s + 1 >> t + 1;
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= m; i++) {
        dp[i][i - 1] = 1;
    }
    for (int i = 1, len = 1; i <= n; i++, len++) {
        for (int l = 1;; l++) {
            int r = l + len - 1;
            if(l > m || s[i] == t[l]){
                add(dp[l][r],dp[l+1][r]);
            }
            if(r > m || s[i]==t[r]){
                add(dp[l][r],dp[l][r-1]);
            } 
        }
    }
    ll ans = 0;
    for (int i = n; i >= m; i--) {
        add(ans, dp[1][i]);
    }
    cout << ans << endl;
    return 0;
}