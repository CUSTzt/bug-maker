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

using P = pair<string, int>;
const int N = 110;

P a[N];

bool cmp(P a, P b) {
    if (a.se == b.se) return a.fi < b.fi;
    return a.se > b.se;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        int co;
        cin >> s >> co;
        a[i].fi = s, a[i].se = co;
    }
    sort(a + 1, a + 1 + n, cmp);
    ll ans = 0;
    for (int i = 1; i <= m; i++) ans += 1LL * (m - i + 1) * a[i].se;
    cout << ans << ' ';
    for (int i = 1; i <= m; i++) cout << a[i].fi << " \n"[i == m];
}

int main() {
    //    IN;
    IOS;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}