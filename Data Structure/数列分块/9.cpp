// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 10007;
const int N = 1e5 + 100;
map<int, int> mp;
int val[N], v[N], bl[N], blo, cnt[N], n, id;
int f[505][505];
std::vector<int> vec[N];
void pre(int x) {
    memset(cnt, 0, sizeof cnt);
    int mx = 0, ans = 0;
    for (int i = (x - 1) * blo + 1; i <= n; i++) {
        cnt[v[i]]++;
        int t = bl[i];
        if (cnt[v[i]] > mx || (cnt[v[i]] == mx && val[v[i]] < val[ans])) {
            ans = v[i], mx = cnt[v[i]];
        }
        f[x][t] = ans;
    }
}
int query(int l, int r, int x) {
    return upper_bound(vec[x].begin(), vec[x].end(), r) - lower_bound(vec[x].begin(), vec[x].end(), l);
}
int query(int a, int b) {
    int ans, mx;
    ans = f[bl[a] + 1][bl[b] - 1];
    mx = query(a, b, ans);
    for (int i = a; i <= min(bl[a] * blo, b); i++) {
        int t = query(a, b, v[i]);
        if (t > mx || (t == mx && val[v[i]] < val[ans]))
            ans = v[i], mx = t;
    }
    if (bl[a] != bl[b]) {
        for (int i = (bl[b] - 1) * blo; i <= b; i++) {
            int t = query(a, b, v[i]);
            if (t > mx || (t == mx && val[v[i]] < val[ans]))
                ans = v[i], mx = t;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // blo = sqrt(n);
    blo = 233;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (mp.count(v[i]) == 0) {
            mp[v[i]] = ++id;
            val[id] = v[i];
        }
        v[i] = mp[v[i]];
        vec[v[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        bl[i] = (i - 1) / blo + 1;
    }
    for (int i = 1; i <= bl[n]; i++) pre(i);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        cout << val[query(a, b)] << endl;
    }
    return 0;
}