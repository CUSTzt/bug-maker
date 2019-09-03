/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-19 09:57:08
 * @Description: You build it, You run it.  
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
const int maxn = 5e3+10;
#define eps 1e-8
using namespace std;
int S[maxn][maxn];
int ans;
int main()
{
	int n,r;
	cin>>n>>r;
	int aa,bb,cc;
	for(int i = 0; i < n ;i++){
		cin>>aa>>bb>>cc;
		S[aa+1][bb+1] += cc;
	}
	for(int i = 1; i <= 5001; i++)
		for(int j = 1; j <= 5001; j++)
			S[i][j] += S[i-1][j];
	for(int i = 1; i <= 5001; i++)
		for(int j = 1; j <= 5001; j++)
			S[i][j] += S[i][j-1];

	for(int i = r;i <= 5001; i++){
		for(int j = r; j <= 5001; j++){
			ans = max(ans,S[i][j]+S[i-r][j-r]-S[i][j-r]-S[i-r][j]);
		}
	}
	cout << ans<<endl;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
