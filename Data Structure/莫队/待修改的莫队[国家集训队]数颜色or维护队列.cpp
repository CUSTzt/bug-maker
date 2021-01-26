#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 1001000
#define maxc 1001000
int a[maxn], cnt[maxc], ans[maxn], belong[maxn];
struct query {
	int l, r, time, id;
} q[maxn];
struct modify {
	int pos, color, last;
} c[maxn];
int cntq, cntc, n, m, size, bnum;
int cmp(query a, query b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.r] ^ belong[b.r]) ? belong[a.r] < belong[b.r] : a.time < b.time);
}
#define isdigit(x) ((x) >= '0' && (x) <= '9')
inline int read() {
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
	return res;
}
int main() {
	n = read(), m = read();
	size = pow(n, 2.0 / 3.0);
	bnum = ceil((double)n / size);
	for(int i = 1; i <= bnum; ++i) 
		for(int j = (i - 1) * size + 1; j <= i * size; ++j) belong[j] = i;
	for(int i = 1; i <= n; ++i) 
		a[i] = read();
	for(int i = 1; i <= m; ++i) {
		char opt[100];
		scanf("%s", opt);
		if(opt[0] == 'Q') {
			q[++cntq].l = read();
			q[cntq].r = read();
			q[cntq].time = cntc;
			q[cntq].id = cntq;
		}
		else if(opt[0] == 'R') {
			c[++cntc].pos = read();
			c[cntc].color = read();
		}
	}
	sort(q + 1, q + cntq + 1, cmp);
	int l = 1, r = 0, time = 0, now = 0;
	for(int i = 1; i <= cntq; ++i) {
		int ql = q[i].l, qr = q[i].r, qt = q[i].time;
		while(l < ql) now -= !--cnt[a[l++]];
		while(l > ql) now += !cnt[a[--l]]++;
		while(r < qr) now += !cnt[a[++r]]++;
		while(r > qr) now -= !--cnt[a[r--]];
		while(time < qt) {
			++time;
			if(ql <= c[time].pos && c[time].pos <= qr) now -= !--cnt[a[c[time].pos]] - !cnt[c[time].color]++;
			swap(a[c[time].pos], c[time].color);
		}
		while(time > qt) {
			if(ql <= c[time].pos && c[time].pos <= qr) now -= !--cnt[a[c[time].pos]] - !cnt[c[time].color]++;
			swap(a[c[time].pos], c[time].color);
			--time;
		}
		ans[q[i].id] = now;
	}
	for(int i = 1; i <= cntq; ++i) 
		printf("%d\n", ans[i]);
	return 0;
}