/**
* Think twice, code once.
* 1.integer overflow(maybe even long long overflow : (a+b >= c) -> (a >= c-b)
* 2.runtime error
* 3.boundary condition
* ---------------------------------------------------------------------------------------
* Author : zzy
* Date : 2020-03-23-03.25.36 Sunday
*/
#include <bits/stdc++.h>

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)b; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define ms(x, y) memset(x, y, sizeof(x))
#define SZ(x) ((int)(x).size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 maxn = 3100;
const i64 mod = 998244353;
i64 dp[maxn], n, s, a[maxn], ans=0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> s;
    for1(i, n) cin >> a[i];
    ms(dp, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = s; j >= a[i]; --j) dp[j] = (dp[j]+dp[j-a[i]])%mod;
        dp[a[i]] = (dp[a[i]]+i)%mod;
        ans = (ans+dp[s])%mod;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}

