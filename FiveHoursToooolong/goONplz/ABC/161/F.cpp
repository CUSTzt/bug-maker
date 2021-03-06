#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    set<ll> s;
    ll m = sqrt(n + 0.5);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ll nn = n;
            while (nn % i == 0) {
                nn /= i;
            }
            if (nn % i == 1) s.insert(i);
        }
    }
    // cout << "ss";
    ll tp = n - 1;
    for (int i = 1; i * i <= tp; i++) {
        if (tp % i == 0) {
            s.insert(i);
            if (i != tp / i) {
                s.insert(tp / i);
            }
        }
    }
    cout << s.size();
    return 0;
}