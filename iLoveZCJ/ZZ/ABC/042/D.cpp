/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-27 11:55:12
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
ll mod_pow(ll x, ll n ,ll mod){
	ll res = 1;
	while(n > 0){
		if(n & 1)res = res *x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
ll invf[maxn], fac[maxn] = {1};
void fac_inv_init(int n , int p){
    for(int i = 1; i < n;i++){
        fac[i] = i * fac[i-1] % p;
    }invf[n-1] = mod_pow(fac[n-1], p-2 , p);
    for(int i = n-2; i >= 0; i--){
        invf[i] = invf[i+1] * (i+1) % p;
    }
}
ll C(ll n , ll m){
    return n < m || m < 0 ? 0 : fac[n]*invf[m]%mod*invf[n-m]%mod;
}
int32_t main()
{
    int h , w , a , b ;
    cin >> h >> w >> a >> b;
    fac_inv_init(maxn, mod);
    int ans = 0;
    for(int i = 1; i <= h-a; i++){
        //ans = (ans + C(b+i-2,i-1)*C(w+h-b-i-1,w-b-1))%mod;
       ans = (ans +  C(b+i-2,i-1)*C(w+h-b-1-i,w-1-b))% mod;
    }cout << ans << endl;
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/