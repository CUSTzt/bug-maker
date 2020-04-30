// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
ll f[N], g[N];
ll n, mod, cnt = 0;
void pre() {
    for (ll k = 1; g[cnt] <= n; k++) {
        g[++cnt] = (3 * k * k - k) / 2;
        g[++cnt] = (3 * k * k + k) / 2;
    }
    f[0] = 1;
    int op = 1;
    for (ll i = 1; i <= n; i++) {
        for (int j = 1; g[j] <= i; j++) {
            // f[i] = (f[i] + f[i - g[j]] * op) % mod;
            // if (!(j & 1)) op = -op;
            f[i] = (f[i] + f[i - g[j]] * op) % mod;
            if (!(j & 1)) op = -op;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;
    pre();
    cout << (f[n] + mod) % mod;
    return 0;
}