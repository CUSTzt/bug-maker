/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-12 23:21:30
# @Description: Think twice. Code once.
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
ll t, n, m, a[maxn], c[maxn], cnt;

int main() {
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i = 0; i <= 120; i++)c[i] = 0;
        ll s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
            cnt = 0;
            while (a[i] > 1)cnt++, a[i] >>= 1;
            c[cnt]++;
        }
        if (s < m) {
            cout << "-1\n";
            continue;
        }
        ll ans = 0, lef = 0;
        for (int i = 0; i < 61; i++) {
            if ((m >> i) & 1) {
                if (lef >= (1ll << i))
                    lef -= (1ll << i);
                else {
                    for (int j = i; j < 61; j++) {
                        if (c[j]) {
                            c[j] -= 1;
                            for (int kp = i; kp < j; kp++)c[kp]++;
                            ans += j - i;
                            break;
                        }
                    }
                }
            }
            lef += c[i] * (1ll << i);
        }
        cout << ans << endl;
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/