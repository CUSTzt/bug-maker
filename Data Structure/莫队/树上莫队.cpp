#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 200200
#define isdigit(x) ((x) >= '0' && (x) <= '9')
inline int read() {
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
	return res;
}
int aa[maxn], cnt[maxn], first[maxn], last[maxn], ans[maxn], belong[maxn], inp[maxn], vis[maxn], ncnt, l = 1, r, now, size, bnum; //莫队相关
int ord[maxn], val[maxn], head[maxn], depth[maxn], fa[maxn][30], ecnt;
int n, m;
struct edge {
	int to, next;
} e[maxn];
void adde(int u, int v) {
	e[++ecnt] = (edge){v, head[u]};
	head[u] = ecnt;
	e[++ecnt] = (edge){u, head[v]};
	head[v] = ecnt;
}
void dfs(int x) {
	ord[++ncnt] = x;
	first[x] = ncnt;
	for(int k = head[x]; k; k = e[k].next) {
		int to = e[k].to;
		if(to == fa[x][0]) continue;
		depth[to] = depth[x] + 1;
		fa[to][0] = x;
		for(int i = 1; (1 << i) <= depth[to]; ++i) fa[to][i] = fa[fa[to][i - 1]][i - 1];
		dfs(to);
	}
	ord[++ncnt] = x;
	last[x] = ncnt;
}
int getlca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	for(int i = 20; i + 1; --i) 
		if(depth[u] - (1 << i) >= depth[v]) u = fa[u][i];
	if(u == v) return u;
	for(int i = 20; i + 1; --i)
		if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
struct query {
	int l, r, lca, id;
} q[maxn];
int cmp(query a, query b) {
	return (belong[a.l] ^ belong[b.l]) ? (belong[a.l] < belong[b.l]) : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
void work(int pos) {
	vis[pos] ? now -= !--cnt[val[pos]] : now += !cnt[val[pos]]++;
	vis[pos] ^= 1;
}
//给定 n 个结点的树，每个结点有一种颜色。m 次询问，每次询问给出 u,v，回答 u,v 之间的路径上的结点的不同颜色数。
int main() {
	n = read(); m = read();
	for(int i = 1; i <= n; ++i) 
		val[i] = inp[i] = read();
	sort(inp + 1, inp + n + 1);
	int tot = unique(inp + 1, inp + n + 1) - inp - 1;
	for(int i = 1; i <= n; ++i)
		val[i] = lower_bound(inp + 1, inp + tot + 1, val[i]) - inp;
	for(int i = 1; i < n; ++i) adde(read(), read());
	depth[1] = 1;
	dfs(1);
	size = sqrt(ncnt), bnum = ceil((double) ncnt / size);
	for(int i = 1; i <= bnum; ++i)
		for(int j = size * (i - 1) + 1; j <= i * size; ++j) belong[j] = i;
	for(int i = 1; i <= m; ++i) {
		int L = read(), R = read(), lca = getlca(L, R);
		if(first[L] > first[R]) swap(L, R);
		if(L == lca) {
			q[i].l = first[L];
			q[i].r = first[R];
		}
		else {
			q[i].l = last[L];
			q[i].r = first[R];
			q[i].lca = lca;
		}
		q[i].id = i;
	}
	sort(q + 1, q + m + 1, cmp);
	for(int i = 1; i <= m; ++i) {
		int ql = q[i].l, qr = q[i].r, lca = q[i].lca;
		while(l < ql) work(ord[l++]);
		while(l > ql) work(ord[--l]);
		while(r < qr) work(ord[++r]);
		while(r > qr) work(ord[r--]);
		if(lca) work(lca);
		ans[q[i].id] = now;
		if(lca) work(lca);
	}
	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;
}