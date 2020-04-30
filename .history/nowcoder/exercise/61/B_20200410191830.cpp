// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int n, m, ans;
void dfs(int n, int m) {
    if (n == m) {
        ans += n;
        return;
    }
    if (n < m) swap(n, m);  // n > m
    if (m * 2 <= n) {
        ans += 1;
        dfs(n, m * 2);
    }
    else {
        int tmp=(2*m-n);
        ans+=tmp;
        dfs(n-tmp,m-tmp);
    }
}
void up() {
    cin >> n >> m;
    ans = 0;
    dfs(n, m);
    cout << ans << endl;
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