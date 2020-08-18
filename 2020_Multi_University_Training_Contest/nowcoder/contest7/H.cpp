#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef unsigned long long ull;
#define lsiz(x) int(x.size())
#define lch rt << 1
#define rch rt << 1 | 1
const ll Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
const ll P = 1e9 + 7;
ll f(ll n, ll K) {
    ll ans = 0;
    for (ll l = 1, r = 0; l <= min(K, n); l = r + 1) {
        r = min(K, n / (n / l));
        ll temp = ((r - l + 1) % P * (n / l) % P) % P;
        ans = (ans + temp) % P;
    }
    return ans % P;
}
ll cal(ll n, ll k) {
    return (((k % P + f(n, k) % P) % P + f(n - 1, k) % P) % P - (n % P) + P) %
           P;
}
int main() {
    ll n, k;
    cin >> n >> k;
    cout << cal(n, k);
    return 0;
}