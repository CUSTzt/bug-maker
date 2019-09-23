//p 是质数的情况下  求Lucas
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m ,p;
ll a[1000010];
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
ll C(ll n , ll m , ll p){
	if (m > n)return 0;
	return ((a[n]*quickPow(a[m],p-2,p))%p*quickPow(a[n-m],p-2,p)%p);
}
ll Lucas(ll n , ll m , ll p ){
	if(!m)return 1;
	return C(n%p,m%p,p)*Lucas(n/p,m/p,p)%p; 
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> p;
		a[0] = 1;
		for(int i = 1; i <= p;i++)
			a[i] = (a[i-1] * i)%p;
		cout << Lucas(n+m, n , p)<<endl;
	}
}
