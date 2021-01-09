// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long
const int N = 1e6 + 100;
int n, a[N], x;
void up() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    // cout << a[1] <<endl;
    if (a[1] < x) {
        cout << 0 << endl;
        return;
    }
    int pos = n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum >= x * i) {
            continue;
        } else {
            pos = i - 1;
            break;
        }
    }
    cout << pos << endl;
    // cout << n-pos+1 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}