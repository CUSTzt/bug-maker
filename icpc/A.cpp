// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e3 + 100;
int dp[N][N], suf_s[N][26], suf_t[N][26];
char s[N], t[N];
void up() {
    int n;
    // string s, t;
    cin >> n >> s + 1 >> t + 1;
    string ss = s + 1, tt = t + 1;
    sort(ss.begin(), ss.end()), sort(tt.begin(), tt.end());
    if (ss != tt) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < 2100; i++) {
        for (int j = 0; j < 26; j++) {
            dp[i][j] = 0;
            suf_s[i][j] = 0;
            suf_t[i][j] = 0;
        }
    }
    // cout << "dud "<< endl;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            suf_s[i][j] = suf_s[i + 1][j];
            suf_t[i][j] = suf_t[i + 1][j];
        }
        suf_s[i][s[i] - 'a']++;
        suf_t[i][t[i] - 'a']++;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            if (s[i] == t[j]) {
                int fl = 1;
                for (int k = 0; k < 26; k++) {
                    if (suf_s[i][k] < suf_t[j][k]) {
                        fl = 0;
                    }
                }
                if (fl) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << n - dp[n][n] << endl;
}
int main() {
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}