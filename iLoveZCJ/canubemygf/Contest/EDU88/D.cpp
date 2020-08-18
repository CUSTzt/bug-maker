// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
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
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;
	vector<ll> val(n, -1ll<<40);
	ll ans = 0;
	for(int i = -30; i <= 30; i++){
		for(int j = 0; j < n; j++){
			if(a[j] == i){
				val[j] = i;
			}
		}
		ll mx = -1ll << 40, pre = -1ll << 40;
		for(int j = 0; j < n;j++){
			pre = max(pre,0ll) + val[j];
			mx = max(mx,pre);
		}
		ans = max(ans, mx - i);
	}
	cout << ans << endl;
	return 0;
}


// //~ while (clock()<=69*CLOCKS_PER_SEC)
// //~ #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
// //~ #pragma GCC target ("avx2")
// //~ #pragma GCC
// // target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #include <algorithm>
// #include <cassert>
// #include <chrono>
// #include <cmath>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <random>
// #include <set>
// #include <stack>
// #include <string>
// #include <vector>
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// // using namespace __gnu_pbds;
// using namespace std;
// using LL = long long;
// #define eps 1e-8
// #define fi first
// #define se second
// #define int long long
// #define eb emplace_back
// #define SZ(a) int(a.size())
// #define ALL(x) (x).begin(), (x).end()
// #define trav(a, x) for (auto &a : x)
// #define LOG(FMT...) fprintf(stderr, FMT)
// #define close \
//     std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
// #define rep(i, x, y) for (LL i = (x), _##i = (y); i <= _##i; ++i)
// #define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
// #define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
// #define SORT_UNIQUE(c)         \
//     (sort(c.begin(), c.end()), \
//      c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
// #define CASET    \
//     int ___T;    \
//     cin >> ___T; \
//     for (int __CS = 1; __CS <= ___T; __CS++)
// typedef long long ll;
// typedef unsigned long long ull;
// typedef vector<int> vi;
// typedef pair<int, int> pii;
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
// int rnd(int x) { return mrand() % x; }
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// LL bin(LL x, LL n, LL MOD) {
//     LL ret = MOD != 1;
//     for (x %= MOD; n; n >>= 1, x = x * x % MOD)
//         if (n & 1) ret = ret * x % MOD;
//     return ret;
// }
// inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
// const double PI = acos(-1.0);
// constexpr int maxn = 1e6 + 10, N = 3e5 + 10;
// constexpr int mod = 1e9 + 7;
// constexpr int INF = 0x3f3f3f3f;
// constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
// constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
// void umax(int &a, int b) {
//     if (a < b) a = b;
// }
// void umin(int &a, int b) {
//     if (a > b) a = b;
// }
// void add(int &a, int b) {
//     a += b;
//     if (a >= mod) a -= mod;
// }
// void dec(int &a, int b) {
//     a -= b;
//     if (a < 0) a += mod;
// }
// struct seg_tree {
//     int l, r;
//     int sum, lm, rm;
//     int tot;
// } t[N << 2];
// int n, a[N];
// void push(int p) {
//     t[p].rm = max(t[p * 2 + 1].rm, t[p * 2 + 1].sum + t[p * 2].rm);
//     t[p].lm = max(t[p * 2].lm, t[p * 2].sum + t[p * 2 + 1].lm);
//     t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
// }
// void build(int p, int l, int r, int *a) {
//     t[p].l = l;
//     t[p].r = r;
//     if (l == r) {
//         t[p].sum = t[p].lm = t[p].rm = a[l];
//         return;
//     }
//     int mid = (l + r) / 2;
//     build(p * 2, l, mid, a), build(p * 2 + 1, mid + 1, r, a);
//     push(p);
// }
// void update(int p, int delta, int val) {
//     if (t[p].l == t[p].r) {
//         t[p].sum = t[p].lm = t[p].rm = val;
//         return;
//     }
//     int mid = (t[p].l + t[p].r) / 2;
//     if (delta <= mid)
//         update(p * 2, delta, val);
//     else
//         update(p * 2 + 1, delta, val);
//     push(p);
// }
// int ans, pos[N];
// int cmp(int i, int j) { return a[i] > a[j]; }
// int suf, pre, zz[N];
// seg_tree query_ans(int p, int l, int r) {
//     if (l <= t[p].l && t[p].r <= r) return t[p];
//     int mid = (t[p].l + t[p].r) / 2;
//     if (l <= mid && mid < r) {
//         seg_tree self, lc = query_ans(p * 2, l, r),
//                        rc = query_ans(p * 2 + 1, l, r);
//         self.lm = max(lc.lm, lc.sum + rc.lm);
//         self.rm = max(rc.rm, rc.sum + lc.rm);
//         self.sum = lc.sum + rc.sum;
//         return self;
//     }
//     if (l > mid)
//         return query_ans(p * 2 + 1, l, r);
//     else
//         return query_ans(p * 2, l, r);
// }
// void up() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) pos[i] = i, zz[i] = i;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     build(1, 1, n, a);
//     sort(pos + 1, pos + 1 + n, cmp);
//     for (int i = 1; i <= n; i++) {
//         int x = pos[i];
//         suf = 0;

//         if (x < n) suf = max(suf, query_ans(1, x + 1, n).lm);
//         pre = 0;
//         if (x > 1) pre = max(pre, query_ans(1, 1, x - 1).rm);
//         umax(ans, pre + suf);
//         t[i].tot = pre+suf;
//         update(1, x, -INF);
//     }
//     cout << ans << endl;
// }
// int32_t main() {
//     close;
//     up();
//     return 0;
// }
