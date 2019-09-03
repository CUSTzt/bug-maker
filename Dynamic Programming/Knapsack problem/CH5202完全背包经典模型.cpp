/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-28 20:49:31
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
//典型的完全背包的模型
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int mod = 2147483648;
const int maxn = 1e6+10;
using namespace std;
int f[maxn];
main()
{
	int n;
	cin>>n;
	memset(f, 0,sizeof(f));
	f[0] = 1;
	for(int i =1; i <= n;i++){
		for(int j = i; j <= n;j++){
			f[j] = (f[j] + f[j-i])%mod;
		}
	}
	cout << (f[n]>0?f[n] - 1:mod)<<endl;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
