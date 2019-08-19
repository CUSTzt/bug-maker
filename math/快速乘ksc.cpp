typedef long long ll;

//快速乘  有一种小技巧就是开成 __int128  这样一定不会爆 了
ll mul (ll a, ll b ,ll mod){
	ll ans = 0;
	for(; b ; b >>= 1){
		if(b & 1)ans = (ans + a) % mod;
		a = a *2 % mod;
	}
	return ans;
}