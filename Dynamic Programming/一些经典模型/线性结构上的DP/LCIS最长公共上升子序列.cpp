
//LCS 最长公共子序列
/*
int dp[1100][1100];
int main()
{
	string s1,s2;
	while(cin>>s1>>s2){
		memset(dp,0,sizeof(dp));
		int len1 = s1.length();
		int len2 = s2.length();
		for(int i = 0;i < len1;i++)
		{
			for(int j = 0; j <  len2;j++)
			{
				if(s1[i] == s2[j]){
					dp[i+1][j+1]=dp[i][j]+1;
				}
				else {
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
}
*/

//LIS最长上升子序列
/*
void solve(){
	fill(dp,dp+n,INF);
	for(int i = 0;i < n;i++)
	{
		*lower_bound(dp,dp+n,a[i])=a[i];
	}
	printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
}

 */

//LCIS
//f[i][j]表示A1~Ai,B1~B可以构成以Bj为结尾的LCIS的长度
//用二维  而不用三维
#include <bits/stdc++.h>

using namespace std;
#define maxn 3050
int f[maxn][maxn];
int n;
int a[maxn],b[maxn];
int main()
{
	cin>>n;
	for(int i = 1; i <= n;i++)
		cin>>a[i];
	for(int j = 1; j <= n;j++)
		cin>>b[j];
	for(int i = 1; i <= n;i++){
		int val = 0;
		if(b[0] < a[i])val = f[i-1][0];
		for(int j = 1; j <= n;j++){
			if(a[i]==b[j])f[i][j] =val +1;
			else f[i][j] = f[i-1][j];
			if(b[j] < a[i])val = max(val, f[i-1][j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n;i++){
		ans = max(ans , f[n][i]);
	}
	cout << ans <<endl;
}