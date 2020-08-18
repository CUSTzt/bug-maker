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
int a[maxn];
int main() {
    // close;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = 0, r = n - 1;
        int fl = 1;
        for (int i = 0; l <= r; i++) {
            // printf("a[%d]==%d,a[%d]==%d,i==%d\n",l,a[l],r,a[r],i );
            if (a[l] < i || a[r] < i) {
                fl = 0;
                // cout << "kk" <<endl;
                break;
            }
            if (l == r - 1) {
                if (a[l] == a[r] && a[l] == i) fl = 0;
                // cout << "pp" << endl;
            }
            l++, r--;
        }
        if (fl)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}