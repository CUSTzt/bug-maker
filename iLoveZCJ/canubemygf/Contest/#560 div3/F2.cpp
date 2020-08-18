#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int, int>
#define PB push_back
#define POP pop_back
#define FI first
#define SE second
#define endl '\n'
#define ls x << 1
#define rs x << 1 | 1
const LL N = 4e5 + 7, mod = 998244353, INF = 1e9;
int n, m;
int a[N], b[N];
vector<int> v[N];
int check(int x, int y) {
    int re = x, cnt = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = x; i >= 1; i--) {
        // cout<<i<<' '<<re<<endl;
        for (int j = 0; j < v[i].size(); j++) {
            while (b[v[i][j]] && re) {
                re--;
                y--;
                b[v[i][j]]--;
            }
        }
        if (re >= i) re--, flag++;
    }
    return flag / 2 >= y;
}
// others
int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt += a[i];
    }
    int x, y;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        v[x].PB(y);
    }
    int ans = INF;
    int l = cnt, r = 2 * cnt;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid, cnt)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}