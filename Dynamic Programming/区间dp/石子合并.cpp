/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-29 17:31:49
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 310;
using namespace std;
int N ;
int sum [maxn];
int a[maxn],f[maxn][maxn];
int main()
{
	cin >> N;
	for(int i = 1; i <= N;i++)
		cin>>a[i];
	memset(f, 0x3f,sizeof(f));
	for(int i = 1; i <= N ;i++){
		f[i][i] = 0;
		sum[i] = sum[i-1] + a[i];
	}
	for(int len = 2;len <= N;len++){  //阶段
		for(int l = 1; l <= N - len + 1;l++){
			int r = l +len - 1;//状态：右端点
			for(int k = l; k < r; k++) //决策
				f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+sum[r] - sum[l-1]);
			//f[l][r] += sum[r] - sum[l-1];
		}
	}
	cout << f[1][N]<<endl;
}

/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
