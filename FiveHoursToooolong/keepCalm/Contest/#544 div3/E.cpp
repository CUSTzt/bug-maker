// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5005;
int n, k, a[N], dp[N][N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int zz = n;
    for (int i = n; i >= 1; i--) {
        while (a[zz] > a[i] + 5) zz--;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[zz + 1][j - 1] + (zz + 1 - i));
        }
    }
    cout << dp[1][k];
    return 0;
}