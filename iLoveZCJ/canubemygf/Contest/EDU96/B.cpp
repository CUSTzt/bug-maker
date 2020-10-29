// can i beat Mod Love? 
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
typedef long long ll;
ll bin(ll x, ll n, ll MOD) {ll ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = acos(-1.0);
constexpr ll mod = 1e9+7;
constexpr int maxn = 1e6+100; // remember to calculate.

int a[maxn];
int main()
{
	close;
	
	int _;cin >> _;while(_--){
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n +1);
	ll ans = 0;
	for(int i = n; i >= n-k; i--){
		ans+=a[i];
	}cout << ans << endl;}
	return 0;
}