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
    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        int n;
        string s;
        cin >> n >> s;
        int od = 0, ev = 0, fl = 0;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') & 1)
                od++;
            else
                ev++;
            sum += (s[i] - '0');
            if ((s[i] - '0' & 1) && sum % 2 == 0) {
                fl = 1;
                s.erase(i + 1, n - 1 - i);
                break;
            }
        }
        if (!fl)
            cout << -1 << endl;
        else
            cout << s << endl;
    }
}