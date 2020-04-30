
#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, k, dp[N][N], nxt[N][N];
string s[N];
string a[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                "1101011", "1101111", "1010010", "1111111", "1111011"};
int get(string s1, string s2) {
    int cnt = 0;
    // cout<<s1<<" "<<s2<<endl;
    for (int i = 0; i < 7; i++) {
        if (s1[i] == s2[i]) continue;
        if (s1[i] == '0' && s2[i] == '1')
            cnt++;
        else
            return -1;
    }
    return cnt;
}
int main() {
    //	freopen("tt.in","r",stdin);
    //	freopen("tt.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i];
    memset(dp, -1, sizeof(dp));
    dp[n + 1][0] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= 9; j++) {
            int t = get(s[i], a[j]);
            //	  cout<<j<<" "<<t<<endl;
            if (t == -1) continue;
            for (int y = t; y <= k; y++)
                if (dp[i + 1][y - t] != -1) dp[i][y] = j, nxt[i][y] = y - t;
        }
    }
    if (dp[1][k] == -1)
        cout << -1 << endl;
    else
        for (int i = 1; i <= n; i++) cout << dp[i][k], k = nxt[i][k];
    return 0;
}