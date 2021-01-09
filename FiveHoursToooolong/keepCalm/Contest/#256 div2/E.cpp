#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem memset(a, b, sizeof(a))

const int N = 1e6 + 5;
vector<int> son[N];
vector<ll> t;
ll x;
int cnt = 0;
void dfs(ll k, ll n) {
    if (cnt == 1e5) return;
    if (n == 0) {
        cout << 1 << ' ';
        cnt++;
        return;
    }
    if (k == 0) {
        cout << t[n] << ' ';
        cnt++;
        return;
    } else {
        for (int i = 0; i < son[n].size(); i++) {
            dfs(k - 1, son[n][i]);
            if (cnt == 1e5) return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> x >> k;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i == x)
                t.pb(i);
            else
                t.pb(i), t.pb(x / i);
        }
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j <= i; j++)
            if (t[i] % t[j] == 0) son[i].pb(j);
    }
    dfs(k, t.size() - 1);
    return 0;
}