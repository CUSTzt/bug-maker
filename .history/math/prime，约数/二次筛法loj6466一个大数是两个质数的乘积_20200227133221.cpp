
/*#include <bits/stdc++.h>

#pragma optimize("no-stack-protector")
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define ALL(a) a.begin(), a.end()
#define lowbit(x) ((x) & -(x))

using namespace std;
typedef __int128 LL;
typedef long long ll;
typedef __uint128_t uLL;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef pair<int, int> pi;
typedef vector<int> VI;

namespace io {
	const int L = (1 << 21) + 1;
	char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, L, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
	inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	template <class I> inline void gi (I & x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	template <class I> inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0', x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline char read () {
		for (c = gc(); c < 'a' || c > 'z'; c = gc());
		return c;
	}
	inline void gs (char *s) {
		int l;
		for (c = gc(); c < 'a' || c > 'z'; c = gc());
		for (l = 0; c <= 'z' && c >= 'a'; c = gc()) s[l] = c, ++l;
		s[l] = 0;
	}
	inline void ps (const char *s) {
		int l = strlen(s), i;
		for (i = 0; i < l; i ++) putc(s[i]);
	}
	struct IOC { ~ IOC () { flush (); } } _ioc_;
} ;
using io::gi;
using io::gs;
using io::ps;
using io::putc;
using io::read;
using io::print;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<class A> string to_string(A v) {
	bool first = true; string res = "{";
	for (const auto &x : v) {
		if (!first) res += ", ";
		first = false, res += to_string(x);
	}
	res += "}";
	return res;
}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H), debug_out(T...); }

template <class T> inline bool chkmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }

namespace Quadratic {
	
	const int Smooth = 12000, D = 1440;
	typedef pair<uLL, uLL> PII;
	
	struct Bitset {
		ull xx[(D >> 6) + 1];
		Bitset(){ memset(xx, 0, sizeof(xx)); }
		inline bool operator [](int p){ return xx[p >> 6] >> (p & 63) & 1; }
		inline void flip(int p){ xx[p >> 6] ^= 1ll << (p & 63); }
		inline Bitset operator ^ (Bitset a){
			for (int x = 0; x <= D >> 6; x ++) xx[x] ^= a.xx[x];
			return *this;
		}
		inline Bitset& operator ^= (Bitset a){ return *this = *this ^ a; }
	} ;
	
	int pr[D], pc;
	uLL n;
	
	inline int ctz(uLL a){
		static const ull p = ~0llu;
		return (a & p) ? __builtin_ctzll(a & p) : 64 + __builtin_ctz(a >> 64);
	}
	uLL gcd(uLL a, uLL b){
		int shift = ctz(a | b);
		for (b >>= ctz(b), a >>= ctz(a); a; a -= b, a >>= ctz(a)) if (a < b) swap(a, b);
		return b << shift;
	}
	
	uLL mul(uLL x, uLL y){
		static const int mag = (1 << 25) - 1;
		uLL z = 0;
		for (; y; y >>= 25) z += (y & mag) * x, x = (x << 25) % n;
		return z % n;
	}
	
	struct no {
		uLL x, y; Bitset w;
		no(){ x = y = 1; }
		inline friend no operator * (no a, no b) {
			no c; int i;
			c.x = mul(a.x, b.x), c.y = mul(a.y, b.y);
			c.w = a.w ^ b.w;
			for (i = 1; i <= pc; i ++) if (a.w[i] & b.w[i]) c.y = mul(c.y, pr[i]);
			return c;
		}
	} ;
	
	namespace linearbase {
		Bitset mat[D], res[D];
		no bas[D];
		int pos[D], m;
		void update(PII &in){
			int i;
			for (i = 1; i <= pc; i ++) if (mat[m][i]) {
				if (!pos[i]) return (void)(pos[i] = m);
				mat[m] ^= mat[pos[i]], res[m] ^= res[pos[i]];
			}
			no ret;
			for (i = 1; i <= m; i ++) if (res[m][i]) ret = ret * bas[i];
			if ((ret.x + ret.y) % n > 0 && ret.x != ret.y) in = PII(ret.x, ret.y);
			mat[m] = res[m] = Bitset(), bas[m] = no(), --m;
		}
		void ins(uLL x, PII &in){
			++m, res[m].flip(m), bas[m].x = x, x = x * x - n;
			for (int i = 1; i <= pc && x >= pr[i]; i ++) while (x % pr[i] == 0) {
				if (mat[m][i]) bas[m].y *= pr[i];
				mat[m].flip(i), bas[m].w.flip(i), x /= pr[i];
			}
			update(in);
		}
		void ins(uLL x, uLL y, PII &in){
			++m, res[m].flip(m), bas[m].x = mul(x, y), x = x * x - n, y = y * y - n;
			for (int i = 1; i <= pc && max(x, y) >= pr[i]; i ++) {
				while (x % pr[i] == 0) {
					if (mat[m][i]) bas[m].y *= pr[i];
					mat[m].flip(i), bas[m].w.flip(i), x /= pr[i];
				}
				while (y % pr[i] == 0) {
					if (mat[m][i]) bas[m].y *= pr[i];
					mat[m].flip(i), bas[m].w.flip(i), y /= pr[i];
				}
			}
			bas[m].y = mul(bas[m].y, x), update(in);
		}
		void clear(){
			memset(pos, 0, sizeof(pos));
			for (; m; --m) mat[m] = res[m] = Bitset(), bas[m] = no();
		}
	}
	
	void init(){
		const int N = Smooth;
		int i, j;
		bitset <N> fl = 0;
		for (i = 2; i < N; i ++) if (!fl[i]) for (pr[++pc] = i, j = i + i; j < N; j += i) fl[j] = 1;
	}
	ull sqrt(uLL n){
		ull l = 1, r = ~0llu, mid = l + ((r - l) >> 1);
		while (l < r) {
			if ((uLL)mid * mid > n) r = mid;
			else l = mid + 1;
			mid = l + ((r - l) >> 1);
		}
		return mid;
	}
	
	static const int N = 1e8 + 5;
	int lst[N], pos, ps[D];
	
	uLL sieve(uLL t){
		namespace lb = linearbase;
		n = t, t = sqrt(n), pos = 0;
		int i, j, p;
		vector <uLL> rem; PII ans(-1, -1);
		for (i = 1; i <= pc; i ++) {
			p = pr[i], ps[i] = -1;
			for (j = 0; j < p; j ++) if (j * j % p == n % p) { ps[i] = j; break; }
		}
		for (int Length = 1 << 10; ; Length *= 1.5) {
			int m = Length, x1, x2;
			while ((t + m) * (t + m) >= 2 * n) --m;
			rem.resize(m + 1);
			for (i = pos; i <= m; i ++) rem[i] = (uLL)(i + t) * (i + t) - n;
			for (i = 1; i <= pc; i ++) if (~ps[i]) {
				p = pr[i];
				x1 = ps[i] - (int)(t % p);
				x2 = p - ps[i] - (int)(t % p);
				x1 += (pos - x1 - 1) / p * p + p;
				x2 += (pos - x2 - 1) / p * p + p;
				for (j = x1; j <= m; j += p) while (rem[j] % p == 0) rem[j] /= p;
				for (j = x2; j <= m; j += p) while (rem[j] % p == 0) rem[j] /= p;
			}
			for (i = pos; i <= m; i ++) if (rem[i] < N) {
				if (rem[i] == 1) lb::ins(t + i, ans);
				else if (lst[rem[i]]) lb::ins(lst[rem[i]] + t, i + t, ans);
				else lst[rem[i]] = i;
				if (~ans.fi) break;
			}
			if (~ans.fi) {
				lb::clear();
				assert(mul(ans.fi, ans.fi) == mul(ans.se, ans.se));
				assert(ans.fi != ans.se);
				return gcd(ans.fi + ans.se, n);
			}
			pos = Length + 1;
		}
		throw "???"; 
	}
}

int main () {
	srand(size_t(new char) ^ 0x19260817);
	Quadratic::init();
	uLL n, d;
	gi(n);
	d = Quadratic::sieve(n);
	if (d > n / d) d = n / d;
	print(d), putc(' '), print(n / d);
}

*/