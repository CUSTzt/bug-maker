 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月08日 星期二 18时52分02秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
// 50000组询问  每次给定a,b,k  求有多少个对二元组(x,y) 满足 x <= a,y <= b 
// 并且gcd(a, b) == k   1 <= k <= a,b <= 50000

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 50001;
int miu[N];
bool v[N];

void Zap() {
	int a, b, k, ans = 0;
	scanf("%d %d %d", &a, &b, &k);
	a /= k;
	b /= k;
	if (a > b) swap(a, b);
	for (int x = 1, gx; x <= a; x = gx + 1) {  //分块处理  
		gx = min(a / (a / x), b / (b / x));
		ans += (miu[gx] - miu[x-1]) * (a / x) * (b / x);
	}
	printf("%d\n", ans);
}

int main() {
	for (int i = 1; i < N; i++) {
		miu[i] = 1;
		v[i] = 0;
	}
	for (int i = 2; i < N; i++) {
		if (v[i]) continue;
		miu[i] = -1;
		for (int j = 2 * i; j < N; j += i) {
			v[j] = 1;
			if (j / i % i == 0) miu[j] = 0;
			else miu[j] *= -1;
		}
	}
	for (int i = 1; i < N; i++) miu[i] += miu[i-1];
	int n;
	cin >> n;
	while (n--) Zap();
	return 0;
}
/*****************************************************************
 *stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
