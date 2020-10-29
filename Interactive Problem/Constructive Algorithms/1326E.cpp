#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
    return;
}
template <typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}
struct SegmentTree {
    static const int MAXN = 1e6+10;
	struct Node {
		int lc, rc;
		int tag, Max;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].tag = 0;
		a[root].Max = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Max += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Max += a[root].tag;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Max += d;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(root);
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, int d) {
		modify(root, 1, n, l, r, d);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2; pushdown(root);
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return max(query(a[root].lc, l, mid, ql, mid), query(a[root].rc, mid + 1, r, mid + 1, qr));
	}
	int query(int l, int r) {
		if (l > r) return 0;
		else return query(root, 1, n, l, r);
	}
} ST;
const int maxn = 1e6+10;
int a[maxn], b[maxn], c[maxn], n;
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    ST.init(n);
    for(int i = 1; i <= n; i++){
        cin >> a[i]; c[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int tp = 1;
    for(int i = n; i >= 1; i--){
        ST.modify(1, c[i], 1);
        while(tp <= n && ST.query(1, n) > 0){
            ST.modify(1, b[tp], -1);
            cout << i << " ";
            tp++;
        }
    }
}