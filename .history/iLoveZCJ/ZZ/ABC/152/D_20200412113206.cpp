// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int dp[50][50], dp[50][50];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        dp[s[0]-'0'][s[s.size()-1]-'0']++;
    }
    ll ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            ans += dp[i][j] * dp[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}