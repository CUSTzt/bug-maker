// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll h, m;
    cin >> h >> m;
    ll fenzi;
    if (h <= m) {
        fenzi = (2 * m - h + 1) * h / 2;
    } else {
        fenzi = m * (m+1) / 2;
    }
    ll fenmu = h * m;
    ll g = __gcd(fenzi, fenmu);
    cout << fenzi / g << "/" << fenmu / g;
    return 0;
}