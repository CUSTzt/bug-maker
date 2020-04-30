/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 11:28:10
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 500;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int tp , dp[maxn][maxn];
int main()
{
    close;
    cin >> tp;
    while (tp--){
        string s, t;
        cin >> s >> t;
        int lens = s.length();
        int lent = t.length();
        for(int a = 1; a <= lent; a++){
            memset(dp, -1 , sizeof dp);
            dp[0][0] = 0;
            for(int i = 0; i < lens ; i++){
                for(int j = 0 ; j < a ; j++){
                    if(dp[i][j] != -1){
                        int k = a + dp[i][j];
                        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (k < lent && s[i] == t[k]) );
                        if(j < a && s[i] == t[j])dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]); 
                    }
                }
            } 
            if(dp[lens][a] >= lent - a){
                puts("YES");continue;
            }
        } puts("NO");
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/