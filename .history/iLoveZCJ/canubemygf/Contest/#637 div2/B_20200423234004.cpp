// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int fuck, p;
void up() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 100);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> qianzhui(n + 10);
    for (int i = 3; i <= n; i++) {
        if (a[i - 1] > a[i - 2] && a[i - 1] > a[i])
            qianzhui[i] = qianzhui[i - 1] + 1;
        else
            qianzhui[i] = qianzhui[i - 1];
    }
    int ans = -1;
    for (int i = 1; i + k - 1 < n + 1; i++) {
        int j = i + k - 1;
        if (i >= 3 && a[i - 1] > a[i] && a[i - 1] > a[i - 2])
            p = qianzhui[j] - qianzhui[i - 1] - 1;
        else if (i >= 2 && a[i] > a[i - 1] && a[i] > a[i + 1])
            p = qianzhui[j] - 1 - qianzhui[i - 1];
        else
            p = qianzhui[j] - qianzhui[i - 1];
        if (ans < p) {
            ans = p;
            fuck = i;
            ans = p;
        }
        
    }
    cout << ans + 1 << ' ' << fuck << endl;
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