// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long
const int N = 1e6 + 100;
int n, p[N], x, a, y, b, k;
void up() {
    cin >> n;
    int zb = 0;
    for (int i = 1; i <= n; i++) cin >> p[i], p[i] /= 100;
    sort(p + 1, p + 1 + n, greater<int>());
    cin >> x >> a >> y >> b >> k;
    int lcm = a / gcd(a, b) * b;
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int fl = 0, zz = 0;
        vector<int> v;
        for (int i = 1; i <= mid; i++) {
            if (i % lcm == 0)
                v.pb(x + y);
            else if (i % a == 0)
                v.pb(x);
            else if (i % b == 0)
                v.pb(y);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            zz += p[i + 1] * v[i];
            if (zz >= k) {
                fl = 1;
                zb = mid;
            }
        }
        if (fl)
            r = mid - 1;
        else {
            l = mid + 1;
        }
    }
    cout << (zb == 0 ? (-1) : zb) << endl;
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