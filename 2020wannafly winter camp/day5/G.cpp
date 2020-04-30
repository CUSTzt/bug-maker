/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-16 20:26:01
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
using LL = long long ;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
#define int long long 
const int maxn = 2e5;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int t , n, inv[maxn];

int32_t main()
{
	cin >> t;
	while(t--){
		cin >> n;
		inv[1] = 1;
		/*for(int i = 2; i < maxn; i++){
			inv[i] = (n - n / i) * inv[n % i] % n;
		}*/
		std::vector<int > l , r;
		int mx = INF;
		for(int i = 2; i < maxn; i++){
			inv[i] = (n - n / i) * inv[n % i] % n;
			if(inv[i] < i && inv[i] < mx)break;
			if(inv[i] < mx){
				mx = inv[i];
				l.emplace_back(i);
				if(i != inv[i])l.emplace_back(inv[i]);
			}
		}
		sort(l.begin(), l.end());
		int ANS = l.size();
		printf("%lld\n",ANS );
		for(int i = 0; i < ANS ; i++){
			printf("%lld %lld\n",l[i], l[ANS - 1 - i] );
		}
	}

	return 0;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
