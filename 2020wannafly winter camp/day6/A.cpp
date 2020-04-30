/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-17 12:46:31
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long
using LL = long long; 
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 998244353;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
int n, sum;
int a[maxn];
int32_t main()
{
	close;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		sum %= mod;
	}
	int ans = 0;
	for(int i = 0; i < n;i++){
		ans = ans + bin(2 , (sum * a[i]) , mod );
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