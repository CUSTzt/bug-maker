/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-18 13:29:06
# @Description: You build it. You run it 
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
//ll mod = 1e9+7;
int fac[1002]; 
int32_t main()
{
	int n , mod;
	cin >> n >> mod;
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	if(n == 2){
		cout << 2 << endl;
		return 0;
	}
	if(n == 3){
		cout << 6 << endl;
		return 0;
	}
	fac[1] = 1;
	for(int i = 2; i <= n;i++){
		fac[i] = fac[i-1] * i % mod;
	}
	cout << (fac[n] - fac[n-2] + mod) % mod << endl;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
