#include <bits/stdc++.h>
#define rep(i, a, b) for (long long i = a; i <= b; ++i)
#define ll long long
using namespace std;
void io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n, m, k, t;

int main() {
    io();
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, (n - 1)) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, 0, (n - k)) {
        if (a[i] == a[i + k - 1]) {
            cout << 0;
            return 0;
        }
    }
    ll ans = 0, L = 0, R = 0;
    rep(i, 0, (k - 2)) L += a[k - 1] - a[i];
    for (int i = n - 1; i > n - k; --i) R += a[i] - a[n - k];
    rep(i, k, (n - 1)) {
        if (a[i] == a[k - 1]) --L;
        if (a[n - 1 - i] == a[n - k]) --R;
    }
    rep(i, 0, (n - 1) >> 1) ans += a[n - 1 - i] - a[i];
    ans -= n - k;
    cout << min(ans, min(L, R));
}