
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m, k, i;
    cin >> n >> m >> k;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll s = 0;
    for (i = n; i >= 1; i--) {
        if (s + a[i] <= k)
            s += a[i];
        else {
            if (a[i] <= k)
                s = a[i], m--;
            else
                break;
        }
        if (!m) break;
    }
    cout << n - i << endl;
    return 0;
}