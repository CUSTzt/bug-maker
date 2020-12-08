#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e6+10;
struct node {
    ll w, tp;
    node() {}
    node(ll w, ll tp) : w(w), tp(tp) {}
    friend int operator <(node a , node b){
        return a.tp * b.w > b.tp * a.w;
    }
};
ll n, m;
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
    while (cin >> n >> m) {
        vector<ll> dp(m * 2 + 1);
        vector<node> tp;
        for (int i = 1; i <= n; i++) {
            int w, vv;
            cin >> w >> vv;
            tp.push_back(node(w, vv));
        }
        sort(tp.begin(),tp.end());
        int sz = tp.size();
        ll ans;
        ll sum = 0;
        for (int i = 0; i < sz; i++) {
            sum = (sum + tp[i].w < m) ? (sum + tp[i].w) : m;
            for (int j = sum; j >= max(tp[i].w, sum - 200); j--) {
                dp[j] = max(dp[j], dp[j - tp[i].w] + tp[i].tp);
            }
        }
        for (int i = 1; i <= m; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
