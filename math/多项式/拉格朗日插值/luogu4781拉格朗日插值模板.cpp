/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-09 16:34:40
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 998244353;
using LL = long long ;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
ll x[maxn], y[maxn], n , k;
int main()
{
	close;
	cin >> n >> k;
	for(int i = 1;i <= n ; i++){
		cin >> x[i] >> y[i];
	}
	int ans = 0, t = 0;
	for(int i = 1; i <= n; i++){
		t = 1;
		for(int j = 1; j <= n; j++)
			if(i != j){
				t = t * (x[i] + mod - x[j]) % mod;
			}
			t = bin( t , mod - 2, mod);
		for(int j = 1; j <= n; j++)
			if(i != j){
				t = t*(k + mod -x[j]) % mod; 
			}
		    t = t*y[i] % mod;
		    ans = ans + t ;
		    ans %= mod;
	}
	cout << ans << endl;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
