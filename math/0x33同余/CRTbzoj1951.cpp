 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-20 10:39:57
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const ll mod = 999911658;
int n, G , farc[maxn],a[5],b[5]={0,2,3,4679,35617},val;
ll mul(ll a,ll b,ll p) {
    ll ret=0;
    while(b) {
        if(b&1)
            ret=(ret+a)%p;
        a=(a<<1)%p;
        b=b>>1;
    }
    return ret;
}
ll quickPow(ll a,ll b,ll p) {
    ll ret=1;
    while(b) {
        if(b&1)
            ret=mul(ret,a,p);  
        a=mul(a,a,p);
        b=b>>1;
    }
    return ret;
}
void init(int p){
	farc[0] = 1;
	for(int i = 1; i <= p;i++)
		farc[i] = farc[i-1]*i%p;
}
int C(int n , int m , int p){
	if(n < m )return 0 ;
	return farc[n]*quickPow(farc[m],p-2,p)%p*quickPow(farc[n-m],p-2,p)%p;
}
int Lucas(int n , int m , int p){
	if(n < m )return 0;
	if(!n )return 1;
	return Lucas(n/p, m/p , p)*C(n%p, m%p,p)%p;
}
void CRT(){
	for(int i = 1; i < 5;i++){
		val = (val + a[i]*(mod/b[i])%mod*quickPow(mod/b[i],b[i]-2,b[i]))%mod;
        //cout << i << "   == "<<val<<endl;
	}
}
main()
{
	cin >> n >>G;
	if(G%(mod+1)==0){
		cout << 0 << endl;
		return 0;
	}
		for(int k = 1;k < 5;k++){
			init(b[k]);
			for(int i = 1; i*i <= n;i++){
            if(n%i == 0){
                a[k]=(a[k]+Lucas(n,i,b[k]))%b[k];
                if(i*i != n){
                    a[k]=(a[k]+Lucas(n,n/i,b[k]))%b[k];
                }
            }
        }
    }
    /*for(int i = 1; i < 5; i++){
    	cout << "a[" << i << "]=====" << a[i] << endl;
    }*/
	CRT();
	//cout << "val =====" << val << endl;
	int ans = quickPow(G , val , mod+1);
	cout << ans  << endl;
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/