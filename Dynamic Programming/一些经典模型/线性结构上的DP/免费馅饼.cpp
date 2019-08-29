 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-23 14:08:10
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int dp[100008][12];
int fyz[100008][12];
int main()
{
	int a,b;
	close;
	int n;
	while(cin>>n&&n){
		//memset(fyz,0,sizeof(fyz));
		memset(dp,0,sizeof(dp));
		int t = 0;
		for(int i = 0;i < n;i++)
		{
			cin>>a>>b;
			dp[b][a]++;
			t=max(t ,b );
		}
		for(int i = t-1; i >= 0 ;i-- )
		{
			dp[i][0]+=max(dp[i+1][1],dp[i+1][0]);
			for(int j = 1;j <= 10; j++){
				dp[i][j]+=max(dp[i+1][j],max(dp[i+1][j+1],dp[i+1][j-1]));
			}
		}
		cout<<dp[0][5]<<endl;
	}
}