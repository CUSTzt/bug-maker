/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-23 15:38:18
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
#define inf 0x3f3f3f3f
const int maxn = 1e6+10;
using namespace std;
double dp[105][105];
int n ;
int x[105],y[105];
double dist(int a,int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
void read(){
	for(int i = 1; i <= n;i++){
		cin>>x[i]>>y[i];
	}
}
double solve(){
	for(int i = 3; i <= n;i++){
		dp[i][i-1] = inf;
		for(int j = 1; j < i-1; j++){
			dp[i][i-1] = min(dp[i][i-1], dp[i-1][j]+dist(i,j));
			dp[i][j] = dp[i-1][j]+dist(i, i-1);
		}
	}
	double ans = inf;
	for(int i = 1; i < n;i++)
		ans = min(ans ,dp[n][i]+dist(n,i));
	return ans;
}
int main()
{
	while(cin>>n){
		read();
		memset(dp,0,sizeof(dp));
		dp[2][1] = dist(1,2);
		printf("%.2f\n", solve());
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
