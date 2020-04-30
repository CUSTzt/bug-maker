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
int n, p, zz, mn;
int cacl(int x) {
    if (x == n) return 1;
    return x + 1;
}
void up() {
    cin >> n;
    vector<int> a(n + 10), b(n + 10), c(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    p = 1, zz = 0, mn = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) {
        c[i] = min(b[i], a[cacl(i)]);
        zz += c[i];
        if (c[i] < mn) {
            mn = c[i];
            p = cacl(i);
        }
    }
    cout << sum - zz + mn << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}