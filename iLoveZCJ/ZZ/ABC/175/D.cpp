// can i beat Mod Love? 
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define eps 1e-8
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
typedef long long ll;
ll bin(ll x, ll n, ll MOD) {ll ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = acos(-1.0);
constexpr ll mod = 1e9+7;
constexpr int maxn = 5000+100; // remember to calculate.
int n , k , p[maxn], c[maxn], ans = -linf, vis[maxn];
int32_t main()
{
	close;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for (int i=1; i<=n; i++) {
		ll cur = 0;
		int tmp = 0;
		vector<bool> vis(n+1);
		vis[i] = true;
		int idx = i;
		while (tmp < k) {
			idx = p[idx];
			cur += c[idx];
			ans = max(ans, cur);
			tmp++;
			if (vis[idx]) break;
			vis[idx] = true;
		}
		if (cur > 0) {
			ll mul = k/tmp - 1;
			cur *= mul;
			ans = max(ans, cur);
			tmp = k - mul*tmp;
			idx = i;
			while (tmp--) {
				idx = p[idx];
				cur += c[idx];
				ans = max(ans, cur);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
