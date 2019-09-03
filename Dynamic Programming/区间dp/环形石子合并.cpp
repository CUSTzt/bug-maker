/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-29 19:34:13
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e3+10;
using namespace std;
int n;
int sum[maxn];
int a[maxn];
int dp_min[maxn][maxn],dp_max[maxn][maxn];
int main()
{
	cin>>n;
	for(int i = 1; i <= n;i++){
		cin>>a[i];
		a[i+n] = a[i];
	}
	for(int i = 1; i < 2*n;i++){
		sum[i] = sum[i-1] + a[i];
		dp_max[i][i] = 0;
		dp_min[i][i] = 0;
	}
	for(int len = 2; len <= n;len++){
		for(int l = 1; l <= 2*n-len+1;l++){
			int r = l + len - 1;
			dp_min[l][r] = 0x3f3f3f3f;
			for(int k = l; k < r; k++){
				dp_min[l][r] = min(dp_min[l][r],dp_min[l][k]+dp_min[k+1][r]+sum[r]-sum[l-1]);
				dp_max[l][r] = max(dp_max[l][r],dp_max[l][k]+dp_max[k+1][r]+sum[r]-sum[l-1]);
			}
		}
	}
	int ans1 = 0;
	int ans2 =0x3f3f3f3f;
	for(int i  = 1; i <= n;i++){
		ans1 = max(ans1, dp_max[i][i+n-1]);
		ans2 = min(ans2, dp_min[i][i+n-1]);
	}
	cout << ans2 <<endl<<ans1<<endl;
}

/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
