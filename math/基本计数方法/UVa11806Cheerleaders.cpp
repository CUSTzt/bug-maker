/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-09-05 15:57:43
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
//容斥原理
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 5e2+10;
const int mod = 1000007;
int C[maxn][maxn];
using namespace std;
int t ;
int n , m , k;
int main()
{
	//预处理很重要
	C[0][0] = 1;
	for(int i = 0; i <= maxn;i++){
		C[i][0] = C[i][i] = 1;   //边界  这一步很重要
		for(int j = 1; j < i ;j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
	}
	//想清楚怎么用容斥原理  以及  二进制
	cin >> t;
	for(int kase = 1; kase <= t;kase++){
		int sum = 0;
		cin >> n >> m >> k;
		for(int i = 0; i < 1<<4; i++){
			int b = 0, r = n, c = m;
			if(i & 1)r--, b++;
			if(i & 2)r--, b++;
			if(i & 4)c--, b++;
			if(i & 8)c--, b++;
			if(b & 1)sum = (sum + mod - C[r*c][k]) % mod;
			else sum = (sum + C[r*c][k]) % mod;
		}
		printf("Case %d: %d\n", kase , sum );
	}

}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
