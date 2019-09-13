 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-13 12:51:28
 # @Description: You build it.You run it
 ***********************************************/
//扩展欧拉定理  

#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
//ll mod = 1e9+7;
ll phi(ll n){
	ll ans = n;
	for(ll i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			ans = ans / i *(i-1);
			while(n%i == 0)n/=i;
		}
	}
	if(n > 1) ans =ans / n * (n-1);  //质数
	return ans;
}
ll mod_pow(ll x, ll n ,ll mod){
	ll res = 1;
	while(n > 0){
		if(n & 1)res = res *x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res%mod;
}
ll solve(ll p){
	if(p == 1)return 0;
	ll t = phi(p);
	return mod_pow(2, solve(t)+t, p);
}
int main()
{
	ll t , p ;
	cin >> t;
	while(t--){
		cin >> p ;
		cout << solve(p)<<endl;
	}

}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/