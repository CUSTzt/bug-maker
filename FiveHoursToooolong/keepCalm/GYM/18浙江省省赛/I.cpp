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
    int n;
    cin >> n;
    if (n == 2) {
        cout << "0 2 1 3" << endl;
        return;
    }
    int l = 0, r = n;
    for (int i = 1; i < n; i++) cout << l++ << ' ' << r++ << ' ';
    cout << n - 1 << ' ' << 3 * (n - 1) - 1 << endl;
}

int main() {
    IOS;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}