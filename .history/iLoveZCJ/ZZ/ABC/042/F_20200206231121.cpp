// Wqr_
// Time : 20/02/06
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main(){
/*#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif*/
  std::ios::sync_with_stdio(false),cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> s(n+10);
  vector<vector<string>> dp(n+10, vector<string>(k+100));
  for(int i = 1; i <= n; i++){
    cin >> s[i];
  }
  auto minst = [&](const string& a, const string& b){
    if(a < b) return a;
    return b;
  };
  for(int i = 1; i <= n; i++){
    string cur = s[i];
    int curl = cur.length();
    for(int j = 1; j <= curl - 1; j++)
      dp[i][j] = dp[i - 1][j];
    for(int j = curl; j <= k; j++){
      dp[i][j] = "\256";
      if(dp[i-1][j].length() == j)
        dp[i][j] = minst(dp[i][j], dp[i - 1][j]);
      if(dp[i-1][j-curl].length() == j-curl)
        dp[i][j] = minst(dp[i][j], dp[i - 1][j - curl] + cur);
    }
  }
  string ans = "\256";
  for(int i = 1; i <= n; i++){
    ans = minst(ans, dp[i][k]);
  }
  cout << ans << endl;
  return 0;
}