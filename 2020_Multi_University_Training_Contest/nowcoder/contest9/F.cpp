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
const int MAXN = 2e6+10;
char buf[100000],*p1=buf,*p2=buf;
inline char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int w = 1, data = 0; char ch = 0;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = nc();
	if(ch == '-') w = -1, ch = nc();
	while(ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = nc();
	return w * data;
}
int n, m, tot, vis[MAXN], ans = Inf;
int a[MAXN];
int main() {
	n = read(); m = read();
	for(int i = 1; i <= n; i++) {
		int k = read(); a[i] = Inf;
		for(int j = 1; j <= k; j++) {
			int x = read();
			a[i] = min(a[i], x);
		}
	}
	sort(a+1, a+n+1);
	for(int i = m; i <= n; i++)
		ans = min(ans, a[i] - a[i-m+1]);
	cout << ans;
	return 0;
}
