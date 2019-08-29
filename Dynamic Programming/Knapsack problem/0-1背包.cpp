/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-23 20:23:19
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/

//   一般写法
/*#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e3+10;
using namespace std;
int N , V;
int v[maxn],w[maxn];   //v 表示体积,  w 表示价值
int dp[maxn][maxn];
int main()
{
	cin>>N>>V;
	for(int i = 1 ; i <= N; i++){
		cin >> v[i] >> w[i];
	}
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= V;j++){
			dp[i][j] = (i == 1 ?0 : dp[i-1][j]);
			if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i]);
		}
	}
	cout << dp[N][V]<<endl;
}*/
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
//优化  滚动数组  但是 解的打印变得困难了  
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;
int v[maxn],w[maxn],N,V;
int f[maxn];
int main(){
	cin>>N>>V;
	for(int i = 1; i <= N ;i++){
		cin>> v[i]>>w[i];
	}
	memset(f,0,sizeof(f));
	for(int i = 1; i <= N ;i++){
		for(int j =V ; j >= 0; j--){  //j必须从V开始枚举
			if(j >= v[i])
				f[j] = max(f[j], f[j - v[i]]+w[i]);
		}
	}
	cout << f[V]<<endl ;
}