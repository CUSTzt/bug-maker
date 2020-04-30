//二次剩余模板题，from claris
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod_pow(ll x, ll n ,ll mod){
	ll res = 1;
	while(n > 0){
		if(n & 1)res = res *x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
ll ToneLLi_Shanks(ll n , ll p){ // 无解返回-1，有解返回其中一个解r，另一个解p-r
    if(n == 0)return 0;
    if(p == 2)return (n & 1) ? 1 : -1;
    if(mod_pow(n , p >> 1, p) != 1)return -1;
    if(p & 2)return mod_pow(n , p+1 >> 2, p);
    int s = __builtin_ctzll(p ^ 1);
    ll q = p >> s, z = 2;
    for(; mod_pow(z , p >> 1 , p) == 1; ++z);
    ll c = mod_pow(z , q, p);
    ll r = mod_pow(n , q+1 >> 1, p);
    ll t = mod_pow(n , q , p), tmp;
    for(int m = s, i ;t != 1;){
        for(i = 0, tmp = t;tmp != 1; ++i)tmp = tmp * tmp % p;
        for(; i < --m;)c = c * c % p;
        r = r * c % p;
        c = c * c % p;
        t = t * c % p;
    }
    return r;
}
int main(){
    int _;
    cin >> _;
    while(_--){
        int n , p;
        cin >> n >> p;
        int ansa = ToneLLi_Shanks(n , p), ansb;
        if(ansa == -1){cout << "Hola!\n";continue;}
        ansb = p - ansa;
        if(ansb < ansa)swap(ansa , ansb);
        if(ansb == ansa || !ansa){cout << ansa << endl;continue;}
        cout << ansa << " " << ansb << endl;
    }
}