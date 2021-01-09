#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 5e5 + 10, MOD = 1e9;
int a[N], b[N];
ll pre[N][31];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 30; j++) pre[i][j] = a[i] / j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 30; j++)
            pre[i][j] = (pre[i][j] + pre[i - 1][j]) % MOD;
    for (int i = 1; i <= m; i++) cin >> b[i];
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ll p = 1;
        ll las = 1;
        for (int j = 1; j <= 30; j++) {
            p *= b[i];
            if (las == 1 + n) break;
            int now = upper_bound(a + 1, a + 1 + n, p) - a;
            ans = (ans + 1LL * i *
                             ((pre[now - 1][j] - pre[las - 1][j] + MOD) % MOD) %
                             MOD) %
                  MOD;
            las = now;
        }
    }
    cout << ans << endl;
}
int main() {
    //    IN;
    IOS;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}
