// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int a[N];
void up() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pre(n + 10);
    int id, p;
    for (int i = 3; i <= n; i++) {
        if (a[i - 1] > a[i - 2] && a[i - 1] > a[i])
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1];
    }
    int ans = -1;
    for (int i = 1; i + k - 1 <= n; i++) {
        int j = i + k - 1;
        if (i >= 3 && a[i - 1] > a[i] && a[i - 1] > a[i - 2])
            p = pre[j] - pre[i - 1] - 1;
        else if (i >= 2 && a[i] > a[i - 1] && a[i] > a[i + 1])
            p = pre[j] - pre[i - 1] - 1;
        else
            p = pre[j] - pre[i - 1];
        if (ans < p) {
            ans = p;
            id = i;
        }
    }
    cout << ans + 1 << ' ' << id << endl;
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