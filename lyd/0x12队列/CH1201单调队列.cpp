
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
const int N = 300006;
int n, m, s[N], q[N];
int main() {
    cin >> n >> m;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int l = 1, r = 1, ans = -INF;
    q[1] = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && q[l] < i - m) l++;
        ans = max(ans, s[i] - s[q[l]]);
        while (l <= r && s[q[r]] >= s[i]) r--;
        q[++r] = i;
    }
    cout << ans << endl;
    return 0;
}
