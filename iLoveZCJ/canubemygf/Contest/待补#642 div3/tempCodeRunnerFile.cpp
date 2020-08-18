#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;
int dp[N][2];
bool chk(char c) {
    if (c <= 'Z' && c >= 'A') return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int len = s.size();
    if(chk(s[0]))dp[0][0]++;
    else dp[0][1]++;
    for (int i = 1; i < len; i++) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        if (chk(s[i])) //daxie
            dp[i][0]++;
        else
            dp[i][1]++;
    }
    int mx = INT_MAX;
    for(int i = 0; i < len; i++){
        mx = min(mx, dp[i][1] + dp[len-1][0] - dp[i][0]);
    }
    cout << mx << endl;
    return 0;
}