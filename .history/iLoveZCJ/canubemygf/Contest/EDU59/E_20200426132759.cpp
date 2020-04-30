// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n, a[N];
char s[N];
int dp[110][110][110];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s + 1;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] -= '0';
    memset(dp, 0xcf, sizeof dp);
    for (int i = 1; i < n + 10; i++) {
        dp[i][i - 1][0] = 0;
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
            for(int c = 0; c < 2; c++){
                for(int x = 1; x <= len; x++){
                    int q =  c? (n+x) : x;
                    for(int e = 1; e +x < len; e++){
                        dp[l][r][q] = max(dp[l][r][q] , dp[l][l+e-1][0]+dp[l+e][r][q]);
                    }if()
                }
            }
        }
    }
    return 0;
}