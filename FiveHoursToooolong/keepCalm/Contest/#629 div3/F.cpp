// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i <= n - k; i++) {
        if (a[i] == a[i + k - 1]) {
            return cout << 0 << endl, 0;
        }
    }
    ll ans = 0, L = 0, R = 0;
    for (int i = 0; i < k - 1; i++) {
        L += a[k - 1] - a[i];
    }
    for (int i = n - 1; i > n - k; i--) {
        R += a[i] - a[n - k];
    }
    for (int i = k; i < n; i++) {
        if (a[i] == a[k - 1]) L--;
        if (a[n - 1 - i] == a[n - k]) R--;
    }
    for (int i = 0; i <= (n - 1) / 2; i++) {
        ans += a[n - 1 - i] - a[i];
    }
    ans -= n - k;
    ll zz = min(L, min(R, ans));
    cout << zz << endl;
    return 0;
}