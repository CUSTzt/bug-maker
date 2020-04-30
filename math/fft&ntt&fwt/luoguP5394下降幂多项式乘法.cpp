#include <bits/stdc++.h>
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
using LL = long long ;
using namespace std;
#define int long long 
const int MOD = 998244353;
const int mod = 998244353;
int G = 3;
const int maxn = 5e6+10;
const int N = 1e6+10;
LL wn[N << 2], rev[N << 2];
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
int NTT_init(int n_) {
    int step = 0; int n = 1;
    for ( ; n <= n_; n <<= 1) ++step;
    FOR (i, 1, n)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
    int g = bin(G, (MOD - 1) / n, MOD);
    wn[0] = 1;
    for (int i = 1; i <= n; ++i)
        wn[i] = wn[i - 1] * g % MOD;
    return n;
}

void NTT(LL a[], int n, int f) {
    FOR (i, 0, n) if (i < rev[i])
        std::swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += (k << 1)) {
            int t = n / (k << 1);
            FOR (j, 0, k) {
                LL w = f == 1 ? wn[t * j] : wn[n - t * j];
                LL x = a[i + j];
                LL y = a[i + j + k] * w % MOD;
                a[i + j] = (x + y) % MOD;
                a[i + j + k] = (x - y + MOD) % MOD;
            }
        }
    }
    if (f == -1) {
        LL ninv = get_inv(n, MOD);
        FOR (i, 0, n)
            a[i] = a[i] * ninv % MOD;
    }
}
int n , m, a[maxn], b[maxn],limit = 1, L;
int32_t main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++)cin >> a[i];
    for(int j = 0; j <= m; j++)cin >> b[j];
    while(limit <= n+m)limit++,L++;
    limit = NTT_init(m+n);
    //cout << "limit === "<<limit << endl;
    NTT(a,limit , 1);NTT(b , limit, 1);
    for(int i = 0; i < limit; i++) a[i] = (a[i] * b[i]) % MOD;
    NTT(a,limit , -1);
    for(int i = 0; i <= n+m; i++){
        cout << (a[i] + mod) % mod <<" ";
    }cout << '\n';
}