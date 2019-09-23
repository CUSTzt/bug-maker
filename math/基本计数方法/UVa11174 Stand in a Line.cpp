 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-15 19:46:02
 # @Description: You build it.You run it
 ***********************************************/
//ex_gcd 求逆元
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
vector<int >g[maxn];
ll v[maxn];
//找出a,b最大公因数，且求出x，y满足ax+by =gcd(a,b)。
ll ext_gcd(ll a, ll b, ll &x,ll &y){
	int d = a;
	if(b != 0){
		d = ext_gcd(b , a%b ,y , x);
		y -= (a / b) * x;
	}else {
		x = 1;
		y = 0;
	}
	return d;
}
ll dfs(int x){
	if(v[x])return v[x];
	for(int i = 0; i < g[x].size();i++){
		v[x] += dfs(g[x][i]);
	}
	return ++v[x];
}
int main()
{
	int t ;
	cin >> t;
	int n , m;
	while(t--){
		scanf("%d %d", &n, &m);
		memset(v,0,sizeof(v));
		for(int i = 0; i <= n;i++)
			g[i].clear();
		int aa, bb ;
		for(int i = 0; i < m ;i++){
			scanf("%d %d" ,&aa, &bb);
			g[bb].push_back(aa);
		}
		ll ans = 1,b = 1;
		for(ll i = 1; i <= n;i++)
			ans = (ans * i)%mod;
		for(int i = 1; i <= n;i++)
			b = (b*dfs(i))%mod;
		ll p,k, d=1;
		d = ext_gcd(b,mod, p,k);
		ans = ((ans*p)+mod)%mod;
		ans = (ans + mod)%mod;
		cout << ans << endl;
	}

}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/