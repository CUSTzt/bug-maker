//适用于p不是质数
#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
ll ex_gcd(ll a, ll b , ll &x, ll &y){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	ll res = ex_gcd(b , a%b, x, y),t;
	t = x; x = y; y = t - a/b * y;
	return res;
}
ll mul(ll a,ll b,ll mod) {
    ll ret=0;
    while(b) {
        if(b&1)
            ret=(ret+a)%mod;
        a=(a<<1)%mod;
        b=b>>1;
    }
    return ret;
}
ll quickPow(ll a,ll b,ll mod) {
    ll ret=1;
    while(b) {
        if(b&1)
            ret=mul(ret,a,mod);  
        a=mul(a,a,mod);
        b=b>>1;
    }
    return ret;
}
ll fac(ll n , ll pi,ll pk)
