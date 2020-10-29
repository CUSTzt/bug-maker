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
const ll inf = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 10;

ll a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool f = 0, F = 0;
    ll Max = 0, Min = inf;
    for (int i = 1; i <= n; i++) {
        if (!f) {
            if (a[i] == Max) {
                cout << "No" << endl;
                return;
            }
            if (a[i] < Max) {
                if (i == 2) F = 1;
                f = 1;
                Min = a[i];
                continue;
            }
            Max = a[i];
        } else {
            if (a[i] >= Min) {
                cout << "No" << endl;
                return;
            }
            Min = a[i];
        }
    }
    cout << ((f && !F) ? "Yes" : "No") << endl;
}
int main() {
    //    IN;
    IOS;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}