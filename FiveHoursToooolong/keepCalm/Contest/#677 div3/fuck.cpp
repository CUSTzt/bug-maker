#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> void chkmax(T&a, T b) { a = a > b ? a : b; }
const int MAXN = 530010;
const int mod = 998244353;
int Mod(int x) { return x >= mod ? x - mod : x; }
void Add(int &x, int y) { x += y, x -= x >= mod ? mod : 0; }
int n, m;
int fac[MAXN];
int inv[MAXN];
int ifac[MAXN];
int tN;
int N, InvN;
int p[MAXN];
int G[MAXN];
int S[MAXN];
int F[MAXN];
int A[MAXN];
int B[MAXN];
int tA[MAXN];
int tB[MAXN];
int tC[MAXN];
int tD[MAXN];
//{{{ Math And Prework
int fsp(int x, int k = mod - 2) {
	int s = 1;
	while(k) {
		if(k & 1) s = 1LL * s * x % mod;
		x = 1LL * x * x % mod, k >>= 1;
	} return s;
}
int C(int n, int m) { return n < m ? 0 : 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
void Combine_init(int n) {
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2; i <= n; i++) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
		ifac[i] = 1LL * ifac[i - 1] * inv[i] % mod;
	}
}
void Prework() {
	tN = 524288;
	int mul = (G[0] = 1, G[1] = fsp(3, (mod - 1) / tN));
	for(int i = 2; i < tN; i++) G[i] = 1LL * G[i - 1] * mul % mod;
}
void NTT_init(int n) {
	N = 1; while(N <= (n << 1)) N <<= 1; InvN = fsp(N);
	for(int i = 1; i < N; i++) p[i] = (p[i >> 1] >> 1) | (i & 1 ? N >> 1 : 0);
}
void NTT(int a[], int k) {
	for(int i = 1; i < N; i++)
		if(i < p[i]) swap(a[i], a[p[i]]);
	for(int l = 2, delta = tN >> 1; l <= N; l <<= 1, delta >>= 1) {
		int len = l >> 1;
		for(int i = 0; i < N; i += l) {
			int *g = G;
			for(int j = i; j < i + len; j++) {
				int tmp = 1LL * (*g) * a[j + len] % mod;
				a[j + len] = Mod(a[j] + mod - tmp);
				a[j] = Mod(a[j] + tmp);
				g += delta;
			}
		}
	} if(k == 1) return ; reverse(a + 1, a + N);
	for(int i = 0; i < N; i++) a[i] = 1LL * a[i] * InvN % mod;
}
void GetInv(int A[], int B[], int n) {
	if(n == 1) return B[0] = fsp(A[0]), void();
	GetInv(A, B, (n + 1) >> 1), NTT_init(n);
	for(int i = 0; i < n; i++) tA[i] = A[i];
	for(int i = n; i < N; i++) tA[i] = 0;
	NTT(tA, 1), NTT(B, 1);
	for(int i = 0; i < N; i++)
		B[i] = 1LL * (2 + 1LL * (mod - tA[i]) * B[i]) % mod * B[i] % mod;
	NTT(B, -1); for(int i = n; i < N; i++) B[i] = 0;
}
void GetDao(int A[], int B[], int n) {
	for(int i = 1; i < n; i++) B[i - 1] = 1LL * A[i] * i % mod; B[n - 1] = 0;
}
void GetInt(int A[], int B[], int n) {
	for(int i = n - 1; i; --i) B[i] = 1LL * A[i - 1] * inv[i] % mod; B[0] = 0;
}
void GetLn(int A[], int B[], int n) {
	GetDao(A, B, n), GetInv(A, tB, n), NTT(B, 1), NTT(tB, 1);
	for(int i = 0; i < N; i++) tB[i] = 1LL * B[i] * tB[i] % mod;
	NTT(tB, -1), GetInt(tB, B, n); for(int i = n; i < N; i++) B[i] = 0;
	for(int i = 0; i < N; i++) tB[i] = 0;
}
void GetExp(int A[], int B[], int n) {
	if(n == 1) return B[0] = 1, void();
	GetExp(A, B, (n + 1) >> 1), GetLn(B, tC, n), NTT_init(n);
	for(int i = 0; i < n; i++) tD[i] = A[i];
	for(int i = n; i < N; i++) tD[i] = 0;
	NTT(B, 1), NTT(tC, 1), NTT(tD, 1);
	for(int i = 0; i < N; i++) B[i] = 1LL * B[i] * (mod + 1 + tD[i] - tC[i]) % mod;
	NTT(B, -1); for(int i = n; i < N; i++) B[i] = 0;
	for(int i = 0; i < N; i++) tC[i] = 0;
}
void init(int n, int m) {
	Prework(), Combine_init(n + m), NTT_init(max(n, m));
	for(int i = 0; i <= n; i++) {
		A[i] = i & 1 ? mod - ifac[i] : ifac[i];
		B[i] = 1LL * fsp(i, n) * ifac[i] % mod;
	} NTT(A, 1), NTT(B, 1);
	for(int i = 0; i < N; i++) A[i] = 1LL * A[i] * B[i] % mod;
	NTT(A, -1);
	for(int i = 0; i <= n; i++) S[i] = A[i];
	memset(A, 0, sizeof(A));
	for(int i = 1; i <= m; i++)
		for(int j = i; j <= n; j += i)
			Add(A[j], mod - inv[j / i]);
	memset(B, 0, sizeof(B)), GetExp(A, B, n + 1);
	memset(A, 0, sizeof(A)), GetInv(B, A, n + 1);
	for(int i = 0; i <= n; i++) F[i] = A[i];
}
//}}}
//{{{ solve01
int solve01() { return fsp(m, n); }
//}}}
//{{{ solve02
int solve02() {
	int res = 1;
	for(int i = 0; i < n; i++)
		res = 1LL * res * (m - i) % mod;
	return res;
}
//}}}
//{{{ solve03
int solve03() {
	int res = 0;
	for(int i = 0; i < m; i++)
		res = (res + 1LL * (i & 1 ? mod - C(m, i) : C(m, i)) * fsp(m - i, n)) % mod;
	return res;
}
//}}}
//{{{ solve04
int solve04() {
	int res = 0;
	for(int i = 1; i <= m; i++) Add(res, S[i]);
	return res;
}
//}}}
//{{{ solve05
int solve05() { return n <= m; }
//}}}
//{{{ solve06
int solve06() { return S[m]; }
//}}}
//{{{ solve07
int solve07() { return C(n + m - 1, m - 1); }
//}}}
//{{{ solve08
int solve08() { return C(m, n); }
//}}}
//{{{ solve09
int solve09() { return C(n - 1, m - 1); }
//}}}
//{{{ solve10
int solve10() { return F[n]; }
//}}}
//{{{ solve11
int solve11() { return n <= m; }
//}}}
//{{{ solve12
int solve12() { return n >= m ? F[n - m] : 0; }
//}}}
int main() {
	std::cin >> n >> m;
    init(n, m);
	cout << solve01() << endl;
	cout << solve02() << endl;
	cout << solve03() << endl;
	cout << solve04() << endl;
	cout << solve05() << endl;
	cout << solve06() << endl;
	cout << solve07() << endl;
	cout << solve08() << endl;
	cout << solve09() << endl;
	cout << solve10() << endl;
	cout << solve11() << endl;
	cout << solve12() << endl;
	return 0;
}