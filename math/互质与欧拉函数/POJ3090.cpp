/*************************************
 * Author : miniLCT
 * More : You build it. You run it
 ************************************/
//发现除了(0,1)(1,0)(1,1)   gcd(x,y) == 1时才能被看见
//  ans = 3 +2*∑（2～N）φ（i） 
//所以就是求出2～N中每个数的欧拉函数   类似于Eratosthenes筛法  我们按照欧拉函数计算式
//在NlogN时间内求出2～N中每个数的欧拉函数

#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#define ll long long
#define INF 0x3f3f3f3f 
#define lowbit(x) (x)&(-x)
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;++i) 
#define MT(x,i) memset(x,i,sizeof(x))
#define close std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000000009;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double E = exp(1);
const double EPS=1e-8;
const int maxn = 1e6+10;
ll phi[maxn];
void euler(int n ){
	for(int i = 2; i <= n;i++)
		phi[i] = i;
	for(int i = 2; i <= n;i++)
		if(phi[i] == i)
			for(int j = i ; j <= n;j+=i)
				phi[j] = phi[j] / i * (i-1);
}
int main()
{
	int t ;
	cin >> t;
	euler(1001);
	FOR(kase, 1, t){
		ll ans = 0;
		int n ;
		cin >> n;
		FOR(i , 1, n)ans += phi[i];
		printf("%d %d %lld\n",kase, n, 3+2*ans );
	}
     
}