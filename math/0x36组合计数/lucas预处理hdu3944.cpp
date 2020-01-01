/****************************************************************
# @Author:      miniLCT
# @DateTime: 2019年12月04日 星期三 16时53分21秒
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include <bits/stdc++.h>

#define  int long long
using namespace std;
using ll = long long;
const int maxn = 1e4 + 100;
int n, k, p, mm, v[maxn], prime[maxn], pth[maxn];

void primes() {
    mm = 0;
    for (int i = 2; i <= maxn; i++) {
        if (v[i] == 0) {
            v[i] = i;
            prime[++mm] = i;
            pth[i] = mm;
        }
        for (int j = 1; j <= mm; j++) {
            if (prime[j] > v[i] || prime[j] > maxn / i)break;
            v[i * prime[j]] = prime[j];
        }
    }
}

ll ksm(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return ret;
}

int fac[maxn][maxn], invf[maxn][maxn];

int init() {
    for (int i = 1; i <= mm; i++) {
        fac[i][0] = invf[i][0] = 1;
        for (int j = 1; j < prime[i]; j++) {
            fac[i][j] = (fac[i][j - 1] * j) % prime[i];
            invf[i][j] = ksm(fac[i][j], prime[i] - 2, prime[i]);
        }
    }
}

int C(int n, int m, int P) { // m >= n >= 0
    if(m > n)return 0;
    if(m == n) return 1;
    //int t = prime[P];
    int t = pth[P];
    return fac[t][n] * (invf[t][n - m] * invf[t][m] % P) % P;
}

int lucas(int n, int m, int P) {
    return m ? C(n % P, m % P, P) * lucas(n / P, m / P, P) % P : 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    primes();
    init();
    int kase = 0;
    while (cin >> n >> k >> p) {
        if (k <= n / 2)k = n - k;
        n++;
        cout << "Case #" << ++kase << ": " << ((k % p + lucas(n, k + 1, p)) % p) << endl;
    }
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/

