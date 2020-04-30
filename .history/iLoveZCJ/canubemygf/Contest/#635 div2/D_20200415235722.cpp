#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using LL = long long;
#define eps 1e-8
#define int long long
#define fi first
#define se second
#define eb emplace_back
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET    \
    int ___T;    \
    cin >> ___T; \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int sss(int x) { return x * x; }

int calc(int x, int y, int z) {
    return ((sss(x - y) + sss(x - z) + sss(y - z)));
}
void solve1() {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<int> r(nr + 1), g(ng + 1), b(nb + 1);
    vector<int> y, z;
    for (int i = 1; i <= nr; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= ng; i++) {
        cin >> g[i];
        y.eb(g[i]);
    }
    for (int i = 1; i <= nb; i++) {
        cin >> b[i];
        z.eb(b[i]);
    }
    SORT_UNIQUE(y), SORT_UNIQUE(z);

    int ans = linf;
    for (int i = 1; i <= nr; i++) {
        int it = lower_bound(y.begin(), y.end(), r[i]) - y.begin();
        if (it != y.size()) {
            int tp = (r[i] + g[it]) / 2;
            int iq = lower_bound(z.begin(), z.end(), r[i]) - z.begin();
            int x1 = g[i], x2 = r[it], x3 = b[iq];
            ans = min(ans, calc(x1, x2, x3));
        }
    }
}

int nr, ng, nb;

int cc(vector<int>a,int n1 , vector<int>b,int n2, vector<int>c,int n3){
    int res = linf;
    for(int i = 0; i < n1; i++){
        int one = lower_bound(b.begin() , b.end() , a[i]) - b.begin();
		int two = lower_bound(c.begin() , c.end() , a[i]) - c.begin();
		if(one >= n2 || b[one] > a[i])
		{
			if(one>1) --one;
		}
		if(one < n2 && two < n3)
		{
			int t1 = a[i];
			int t2 = b[one];
			int t3 = c[two];
			res = min(res , calc(t1 , t2 , t3));
		}
		one = lower_bound(c.begin() , c.end() , a[i]) - c.begin();
		two = lower_bound(b.begin() , b.end() , a[i]) - b.begin();

		if(one >= n3 || c[one] > a[i])
		{
			if(one > 1) one -- ;
		}

		if(one < n3 & two < n2)
		{
			int t1 = a[i];
			int t2 = c[one];
			int t3 = b[two];
			res = min(res,calc(t1 , t2 , t3));
		}
    }
    return res;
}
void solve2() {
    cin >> nr >> ng >> nb;
    vector<int> r(nr), g(ng), b(nb);
    vector<int> y, z;
    for (int i = 0; i < nr; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < ng; i++) {
        cin >> g[i];
        y.eb(g[i]);
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
        z.eb(b[i]);
    }
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());
    int zz = linf;
    zz=min(zz,cc(r,nr,b,nb,g,ng));
    zz=min(zz)
}
int32_t main() {
    close;
    CASET { solve2(); }
}