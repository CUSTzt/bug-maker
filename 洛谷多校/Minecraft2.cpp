#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 101111

int n, m;
unordered_set <unsigned long long> G;

void add(unsigned long long x) {
	if (G.count(x)) G.erase(x);
	else G.insert(x);
}
unsigned long long hh[N];
struct UFS {
	int f[N];
	unsigned long long H[N];
	int getf(int x) {
		return f[x] == x ? x : (f[x] = getf(f[x]));
	}
	void merge(int x, int y) {
		x = getf(x), y = getf(y);
		if (x != y) {
			add(H[x]);
			add(H[y]);
			H[x] ^= H[y];
			add(H[x]);
			f[y] = x;
		}
	}
	void init() {
		for (int i = 1;i <= n; i++) f[i] = i, H[i] = hh[i];
	}
} f[2];

mt19937_64 rnd(1231231312);

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) hh[i] = rnd();
	f[0].init(), f[1].init();
	for (int i = 1; i <= m; i++) {
		int op, x, y;
		read(op); read(x); read(y);
		f[op - 1].merge(x, y);
		puts(G.size() ? "B" : "A");
	}
}
