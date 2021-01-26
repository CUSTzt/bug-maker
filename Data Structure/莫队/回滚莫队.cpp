#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 100100
#define maxb 5050
#define ll long long
int aa[maxn], typ[maxn], cnt[maxn], cnt2[maxn], belong[maxn], lb[maxn], rb[maxn], inp[maxn];
ll ans[maxn];
struct query {
	int l, r, id;
} q[maxn];
int n, m, sz, bnum;
#define isdigit(x) ((x) >= '0' && (x) <= '9')
inline int read() {
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
	return res;
}
int cmp(query a, query b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : a.r < b.r; 
}
int main() {
	n = read(), m = read();
	sz = sqrt(n);
	bnum = ceil((double) n / sz);
	for(int i = 1; i <= bnum; ++i) {
		lb[i] = sz * (i - 1) + 1;
		rb[i] = sz * i;
		for(int j = lb[i]; j <= rb[i]; ++j) belong[j] = i;
	}
	rb[bnum] = n;
	for(int i = 1; i <= n; ++i) inp[i] = aa[i] = read();
	sort(inp + 1, inp + n + 1);
	int tot = unique(inp + 1, inp + n + 1) - inp - 1;
	for(int i = 1; i <= n; ++i) typ[i] = lower_bound(inp + 1, inp + tot + 1, aa[i]) - inp;
	for(int i = 1; i <= m; ++i) {
		q[i].l = read(), q[i].r = read();
		q[i].id = i;
	}
	sort(q + 1, q + m + 1, cmp);
	int i = 1;
	for(int k = 0; k <= bnum; ++k) {
		int l = rb[k] + 1, r = rb[k];
		ll now = 0;
		memset(cnt, 0, sizeof(cnt));
		for( ; belong[q[i].l] == k; ++i) {
			int ql = q[i].l, qr = q[i].r;
			ll tmp;
			if(belong[ql] == belong[qr]) {
				tmp = 0;
				for(int j = ql; j <= qr; ++j) cnt2[typ[j]] = 0;
				for(int j = ql; j <= qr; ++j) {
					++cnt2[typ[j]]; tmp = max(tmp, 1ll * cnt2[typ[j]] * aa[j]);
				}
				ans[q[i].id] = tmp;
				continue;
			}
			while(r < qr) {
				++r; ++cnt[typ[r]]; now = max(now, 1ll * cnt[typ[r]] * aa[r]);
			}
			tmp = now;
			while(l > ql){
				--l; ++cnt[typ[l]]; now = max(now, 1ll * cnt[typ[l]] * aa[l]);
			} 
			ans[q[i].id] = now;
			while(l < rb[k] + 1) {
				--cnt[typ[l]];
				l++;
			}
			now = tmp;
		}
	}
	for(int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
	return 0;
}