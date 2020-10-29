// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n, m, mx, mn, mid, ans, x, d;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    mid = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        mn += abs(i - mid);
    }
    mid = 1;
    for (int i = 1; i <= n; i++) {
        mx += abs(i - mid);
    }
    while (m--) {
        cin >> x >> d;
        ans += x * n;
        if (d > 0) {
            ans += mx * d;
        } else {
            ans += mn * d;
        }
    }
    cout << fixed << setprecision(10) << ans * 1.0 / n;
    return 0;
}