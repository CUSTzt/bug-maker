 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-11 15:37:49
 # @Description: You build it.You run it
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef unsigned long long ull;
const int maxn = 1e6;
const int INF = 1e9;
const ull linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ull mod = 1e9+7;
int main()
{
	ull n , m , ans;
	while(cin >> n >> m&&n + m){
		if(n > m )swap(n , m);
		ans = n * m * (m + n - 2) + 2 * n * (n-1)*(3*m-n-1)/3;
		cout << ans << endl;
	}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/