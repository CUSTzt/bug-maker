/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-04 22:43:01
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int32_t main()
{
	int t , n;
	cin >> t;
	while(t--){
		cin >> n;
		ll ans = n;
		while(n/10){
			ans += n/10;
			n = (n % 10) + n /10;
		}//ans+=n;
		cout << ans << endl;
	}
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/