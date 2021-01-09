// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

void up() {
    int n;
    cin >> n;
    vector<int> a(n + 10), l(n + 10, N), r(n + 10, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    int cnt = 0, now = 0, lst = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] > n) continue;
        cnt++;
        now = (now == 0) ? 1 : (l[i] > lst ? now + 1 : 1);
        lst = r[i];
        mx = max(mx, now);
    }
    int zb = cnt - mx;
    cout << zb << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}