#include <bits/stdc++.h>

using namespace std;

using f64 = double;
using f128 = __float128;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
using u128 = __uint128_t;

template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
template <class I>
string to_str(I x) {
    if (!x)
        return "0";
    if (x < 0)
        return "-" + to_str(-x);
    string res = "";
    while (x) res += x % 10 + '0', x /= 10;
    reverse(res.begin(), res.end());
    return res;
}
ostream &operator<<(ostream &cout, i128 x) { return (cout << to_str(x)); }
ostream &operator<<(ostream &cout, u128 x) { return (cout << to_str(x)); }

namespace Solver {

u64 pow_64(u64 a, u64 t, u64 mod) {
    u64 r = 1;
    for (; t; t >>= 1, a = u128(a) * a % mod)
        if (t & 1)
            r = u128(r) * a % mod;
    return r;
}
bool check_prime(u64 n) {
    static const int jp[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    if (n == 1)
        return false;
    for (int p : jp)
        if (n % p == 0)
            return n == p;
    u64 r = n - 1, x, y;
    int e = 0;
    while (~r & 1) r >>= 1, ++e;
    for (int p : jp) {
        x = pow_64(p, r, n);
        for (int t = 0; t < e && x > 1; ++t) {
            y = (i128)x * x % n;
            if (y == 1 && x != n - 1)
                return false;
            x = y;
        }
        if (x != 1)
            return false;
    }
    return true;
}
u64 next_prime(u64 n) {
    n += ~n & 1;
    while (!check_prime(n += 2))
        ;
    return n;
}

u128 ctz(u128 x) { return u64(x) ? __builtin_ctzll(x) : __builtin_ctzll(x >> 64) + 64; }
u128 gcd(u128 a, u128 b) {
    if (!a || !b)
        return a | b;
    int shift = ctz(a | b);
    for (b >>= ctz(b); a; a -= b)
        if ((a >>= ctz(a)) < b)
            swap(a, b);
    return b << shift;
}

struct u256 {
    u128 lo, hi;
    u256() {}
    u256(u128 lo, u128 hi) : lo(lo), hi(hi) {}
    static u256 mul128(u128 a, u128 b) {
        u64 a_hi = a >> 64, a_lo = u64(a);
        u64 b_hi = b >> 64, b_lo = u64(b);
        u128 p01 = u128(a_lo) * b_lo;
        u128 p12 = u128(a_hi) * b_lo + u64(p01 >> 64);
        u64 t_hi = p12 >> 64, t_lo = p12;
        p12 = u128(a_lo) * b_hi + t_lo;
        u128 p23 = u128(a_hi) * b_hi + u64(p12 >> 64) + t_hi;
        return u256(u64(p01) | (p12 << 64), p23);
    }
};

struct Mont {
    u128 mod, inv, r2;
    Mont(u128 n) : mod(n) {
        assert(n & 1);
        inv = n;
        for (int i = 0; i < 6; ++i) inv *= 2 - n * inv;
        r2 = -n % n;
        for (int i = 0; i < 4; ++i)
            if ((r2 <<= 1) >= mod)
                r2 -= mod;
        for (int i = 0; i < 5; ++i) r2 = mul(r2, r2);
    }
    u128 reduce(u256 x) const {
        u128 y = x.hi - u256::mul128(x.lo * inv, mod).hi;
        return i128(y) < 0 ? y + mod : y;
    }
    u128 reduce(u128 x) const { return reduce(u256(x, 0)); }
    u128 init(u128 n) const { return reduce(u256::mul128(n, r2)); }
    u128 mul(u128 a, u128 b) const { return reduce(u256::mul128(a, b)); }
} mont(1);

i128 N;
i128 add(i128 a, i128 b) { return (a += b) <= N ? a : a - N; }
i128 sub(i128 a, i128 b) { return (a -= b) < 0 ? a + N : a; }
i128 mul(i128 a, i128 b) { return mont.mul(a, b); }
void exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (b == 0)
        return (void)(x = 1, y = 0);
    exgcd(b, a % b, y, x), y -= a / b * x;
}
i128 inv128(i128 t) {
    i128 q = N, x, y;
    exgcd(t, q, x, y);
    return (x % N + N) % N;
}

const int L = 250;
int prime[L], pcnt, root[L];
u128 _mont_prime[L];
f64 logp[L];

struct word {
    bitset<L> mask;
    u128 lhs, rhs;
    int bit;
    word() { mask = lhs = rhs = 0, bit = L; }
    void merge(word &x) {
        lhs = mul(lhs, x.lhs), rhs = mul(rhs, x.rhs);
        bitset<L> cons = mask & x.mask;
        for (int pos = cons._Find_first(); pos < L; pos = cons._Find_next(pos))
            rhs = mul(rhs, _mont_prime[pos]);
        mask ^= x.mask, bit = mask._Find_first();
    }
};
vector<word> smooth;
unordered_map<i64, word> data;
void insert(word &o) {
    int x;
    for (x = 0; x < smooth.size(); ++x) {
        if (smooth[x].bit > o.bit)
            break;
        if (smooth[x].bit == o.bit)
            o.merge(smooth[x]);
    }
    if (o.bit == L) {
        u128 g = gcd(o.lhs + o.rhs, N);
        if (g != 1 && g != N) {
            if (g > N / g)
                g = N / g;
            cout << g << ' ' << N / g << endl;
            cerr << clock() << endl;
            exit(0);
        }
    } else
        smooth.insert(smooth.begin() + x, o);
}
void try_insert(i128 x, i128 y) {
    while (x < 0) x += N;
    word ins;
    ins.lhs = x, ins.rhs = 1;
    for (int k = 1; k <= pcnt; ++k) {
        int cnt = 0;
        while (y % prime[k] == 0) y /= prime[k], ++cnt;
        if (cnt)
            for (ins.mask[k] = cnt & 1, cnt >>= 1; cnt; --cnt) ins.rhs *= prime[k];
    }
    ins.lhs = mont.init(ins.lhs % N);
    ins.rhs = mont.init(ins.rhs % N);
    ins.bit = ins.mask._Find_first();
    if (y != 1) {
        if (data.count(y)) {
            ins.merge(data[y]);
            ins.rhs = mul(ins.rhs, mont.init(add(y, N)));
            y = 1;
        } else
            data[y] = ins;
    }
    if (y == 1)
        insert(ins);
}
void init() {
    int i, j;
    int B = pow(log(1. * N), 2) * .6;
    vector<char> mark((B >> 1) + 5);
    for (i = 3; i * i <= B; i += 2)
        if (!mark[i >> 1])
            for (j = i * i; j <= B; j += i << 1) mark[j >> 1] = true;
    auto append = [&](int p) { prime[++pcnt] = p, _mont_prime[pcnt] = mont.init(p), logp[pcnt] = log(p); };
    for (append(2), i = 3; i <= B; i += 2)
        if (!mark[i >> 1])
            if (pow_64(N % i, i >> 1, i) == 1)
                append(i);
    for (i = 1; i <= pcnt; ++i)
        for (j = N % prime[i]; root[i] * root[i] % prime[i] != j; ++root[i])
            ;
}
void main() {
    read(N);
    mont = Mont(N);
    init();
    int M = pcnt * 50;
    i64 D = sqrt(sqrt(2. * N) / M);
    f64 bound = log(M * sqrt(.5 * N)) * 0.75;
    while (true) {
        do
            D = next_prime(D);
        while ((D & 3) == 1);
        u64 y0 = pow_64(u64(N % D), (D + 1) >> 2, D);
        if ((i128(y0) * y0 - N) % D)
            continue;
        u64 y1 = u64((N - y0 * y0) / D % D + D) % D;
        y1 = u128(y1) * (D / 2 + 1) % D * pow_64(y0, D - 2, D) % D;
        i128 A = i128(D) * D;
        i128 B = u128(y1) * D + y0;
        i128 C = (B * B - N) / A;
        i128 E = mul(mont.init(B), inv128(D));
        vector<f64> pos(M), neg(M);
        for (int x = 1; x <= pcnt; ++x) {
            int p = prime[x], s = A % p, a = A % p, inv_a = 1;
            if (!a)
                continue;
            while (a > 1) inv_a = (p - inv_a) * (p / a) % p, a = p % a;
            int u = (p - B % p) * inv_a % p, v = root[x] * inv_a % p;
            int r1 = (u + v) % p, r2 = (u - v + p) % p;
            for (int su = 0; su < M; su += p) {
                if (su + r1 < M)
                    pos[su + r1] += logp[x];
                if (su + r2 < M)
                    pos[su + r2] += logp[x];
                if (su > 0)
                    neg[su - r1] += logp[x], neg[su - r2] += logp[x];
            }
        }
        for (int x = 0; x < M; ++x) {
            if (pos[x] > bound)
                try_insert(E + D * x, A * x * x + 2 * B * x + C);
            if (neg[x] > bound)
                try_insert(E - D * x, A * x * x - 2 * B * x + C);
        }
    }
}

}  // namespace Solver

int main() { Solver::main(); }
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