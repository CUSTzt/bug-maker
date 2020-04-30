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
int n, c, h[N], dp[N], r, l, path[N];
int sq(int x) { return x * x; }
double calc(int i, int j) {
    return (dp[i] - dp[j] + sq(h[i]) - sq(h[j])) / 2.0 / (h[i] - h[j]);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    path[0] = 0, path[1] = 1;
    l = r = 1;
    for(int i = 2; i <= n; i++){
        while(l < r && calc)
    }
    return 0;
}