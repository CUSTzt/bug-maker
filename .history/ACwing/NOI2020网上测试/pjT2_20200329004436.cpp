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
int n, mod, cnt = 0;
void pre() {
    for (ll k = 1; g[cnt] <= n; k++) {
        g[++cnt] = (3*k*k - k) / 2;
        g[++cnt] = (3*k*k + k) / 2;
        
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;

    return 0;
}