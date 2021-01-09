#include <bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < c) {
        swap(a, c), swap(b, d);
    }
    cout << (a + 2) * (b + 2) + (c + 2) * d - a * b - c * d << endl;
    return 0;
}