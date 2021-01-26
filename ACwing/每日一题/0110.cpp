#include<bits/stdc++.h>
using namespace std;
int dp[1110][1111], n , a[1111][1111];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1e9;
        }
    }
    int ans = 0;
    dp[1][1] = a[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans , dp[n][i]);
    }
    cout << ans << endl;
}