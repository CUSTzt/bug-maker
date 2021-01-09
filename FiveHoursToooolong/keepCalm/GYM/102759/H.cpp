#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int max_n = 100111, inf = 1000111222;
ll m[max_n];
int n;
ll sum = 0;
bool can_get(int res) {
    ll add0 = 0;
    for (int i = res; i < n; ++i) {
        add0 += m[i];
    }
    ll needbef = 1;
    for (int i = res - 1; i >= 1; --i) {
        if (needbef <= m[i]) {
            add0 += (m[i] - needbef);
        } else {
            needbef += (needbef - m[i]);
        }
        if (needbef > sum) {
            return false;
        }
    }
    return needbef <= m[0] + add0;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // m[i] = 1e9;
        cin >> m[i];
        sum += m[i];
    }
    if (sum == 1) {
        if (m[0] == 1) {
            cout << 1 << endl;
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            if (m[i]) {
                cout << i << endl;
                return 0;
            }
        }
    }
    int l = 1, r = n + 64;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (can_get(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
