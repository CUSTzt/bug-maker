#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef unsigned long long ull;
#define lsiz(x) int(x.size())
#define lch rt<<1
#define rch rt<<1|1
const ll Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
const int MAXN = 1e6+10;
int n, k, ans, sum;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k; sum = 0;
	vector<int> a(n+1, 1);
	for(int i = 1; i <= k; i++) {
		int x; cin >> x; 
		for(int j = x; j <= n; j += x) {
			sum -= !a[j];
			sum += a[j];
			a[j] ^= 1;
		}
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}