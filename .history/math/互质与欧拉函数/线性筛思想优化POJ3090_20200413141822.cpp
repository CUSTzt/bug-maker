 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-13 11:06:41
 # @Description: You build it.You run it
 ***********************************************/
//类似线性筛 法 
//利用p|n而且(p*p)|n  φ(N)=φ(N/p)*p
//利用p|n而且(p*p)不能整除n  φ(N)=φ(N/p)*(p-1)
//时间复杂度O(n)
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1010;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int prime[maxn],v[maxn],phi[maxn];
// void euler(int n ){
// 	memset(v, 0 , sizeof(v));//最小质因数
// 	int m = 0; //质数数量
// 	for(int i =2; i <= n;i++){
// 		if(v[i] == 0){ //i是质数
// 			v[i] = i,prime[++m] = i;
// 			phi[i] = i-1;
// 		}
// 		//给当前的数i乘上一个质因数
// 		for(int j = 1; j <= m;j++){
// 			if(prime[j] > v[i] || prime[j] > n/i)break;//i有比prime[j]更小的质因数或超过n的范围，停止循环
// 			//prime[j]是合数i*prime[j]的最小质因子
// 			v[i*prime[j]] = prime[j];
// 			phi[i*prime[j]] = phi[i] * (i%prime[j]?prime[j]-1:prime[j]);

// 		}
// 	}
// }
int main()
{
	int t;
	euler(1001);
	cin >> t;
	for(int kase = 1; kase <= t;kase ++){
		int n ;
		cin >> n ;
		ll ans = 0;
		for(int i = 1; i <= n;i++){
			ans += phi[i];
		}
		printf("%d %d %lld\n", kase , n , 3+2*ans);
	}


}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/