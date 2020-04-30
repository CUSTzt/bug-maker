// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int dp[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, s, t;
    cin >> m >> s >> t;
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            m -= 10;
            dp[i] = dp[i-1] + 60;
        }else {
            m+=4;
            dp[i] = dp[i-1];
        }
    }
    for(int i = 1; i <= t; i++){
        if(dp[i] <= dp[i-1])
    }
    return 0;
}