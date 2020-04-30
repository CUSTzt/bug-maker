 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-10-31 14:47:50
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
#include <bits/stdc++.h>
//dp[i][j] 表示第i位比j小的数字有几个
using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int A, B, dp[11][50000], a[25],len;
int f(int n){
	int ans = 0, len = 1;
	while(n){
		ans += n % 10 *len;
		len *= 2;
		n /= 10;
	}
	return ans;
}
int dfs(int len, int ans , int flag){
	if(len < 0)
		return ans >= 0;
	if(ans < 0)
		return 0;
	int sum = 0;
	if(!flag && dp[len][ans] != -1)
		return dp[len][ans];
	int m = flag ? a[len] : 9;
	for(int i = 0; i <= m;i++){
		sum += dfs(len-1 , ans - i * (1 << len) , flag && i == m);
	}
	if(!flag)
		dp[len][ans] = sum;
	return sum;
}
int main()
{
	int t;
	cin >> t;
	memset(dp, -1 , sizeof dp);
	for(int kase = 1; kase <= t;kase++){
		cin >> A >> B;
		len = 0;
		while(B){
			a[len++] = B % 10;
			B /= 10;
		}
		printf("Case #%d: %d\n",kase, dfs(len-1, f(A) , 1));
	}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/