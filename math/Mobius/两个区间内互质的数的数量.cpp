 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-10-02 14:13:34
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e7+10;
const int N = 1e7+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a, b , c , d;
int miu[maxn],v[maxn];
void init(){
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
}
int coprime(int a , int b){
	int ans = 0;
	if (a > b) swap(a, b);
	for (int x = 1, gx; x <= a; x = gx + 1) {
		gx = min(a / (a / x), b / (b / x));
		ans += (miu[gx] - miu[x-1]) * (a / x) * (b / x);
	}
	return ans;
}
int32_t main()
{
	init();
	for(int i = 2; i <= maxn;i++)
		miu[i] += miu[i-1];
	cin >> a >> b >> c >> d;
	int ans = coprime(b, d) - coprime(b, c-1) - coprime(a-1 ,d) + coprime(a-1,c-1);
	cout << ans << endl;
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/
