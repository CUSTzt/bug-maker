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

void solve() {
    int n, m;
    cin >> n >> m;
    VI res;
    while (n != 0 && m != 0) {
        int mini = min(n, m);
        for (int i = 1; i <= mini; i++) res.pb(mini);
        if (n < m)
            m -= mini;
        else
            n -= mini;
    }
    cout << sz(res) << endl;
    sort(all(res), greater<int>());
    for (int it : res) cout << it << ' ';
    cout << endl;
}
int main() {
    IOS;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}