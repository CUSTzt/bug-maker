/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-09-05 15:41:39
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#include <iostream>
#define ll long long int 
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
ll f[maxn];
int main()
{
	f[3] = 0;
	for(ll i = 4; i <= 1000000;i++){
		f[i] = f[i-1] + ((i-1)*(i-2)/2 - (i-1)/2)/2;
	}
	int n ;
	while(cin >> n ){
		if( n < 3)break;
		cout << f[n] << endl;
	}
	return 0;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
