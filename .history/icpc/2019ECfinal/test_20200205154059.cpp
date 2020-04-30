#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
ll n;
ll a[maxn], b[maxn];
ll ans;
ll vis[maxn];
vector<ll>vc[maxn];
ll cnt;
ll use[maxn];
ll solve(const vector<ll>& vc) {
    ll N = (ll)vc.size();
    ll res = 0;
    for (ll i = 0; i < (1 << N); i++) {
        for (ll u : vc)use[u] = 0;
        ll tmp = 0;
        for (ll j = 0; j < N; j++) {
            if ((i&(1<<j))) {
                tmp += a[vc[j]];
                ll x = vc[j]*vc[j];
                while (x <= n) {
                    use[x]++;
                    x *= vc[j];
                }
            }
        }
        for (int j = 0; j < N;j++) {
            int u=vc[j];
            if (use[u]&&(i&(1<<j)))tmp -= b[u]*use[u];
        }
        res = max(res, tmp);
    }
    cout << "res === " << res << endl;

    return res;
}
int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; i++)scanf("%lld", &b[i]);
    ans += a[1];
    for (ll i = 2; i <= n; i++) {
        if (vis[i])continue;
        ll x = i;
        cnt++;
        while (x <= n) {
            vc[cnt].push_back(x);
            vis[x] = 1;
            x *= i;
        }
    }
    for (ll i = 1; i <= cnt; i++) {
        ans += solve(vc[i]);
    }
    printf("%lld\n", ans);
    return 0;
}