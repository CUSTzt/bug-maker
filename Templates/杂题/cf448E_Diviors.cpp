// https://codeforces.com/contest/448/problem/E
constexpr int MAXN = 1e5;
vi d, f[maxn];
vi cal(int k) {
    if (k == 0) return vi(1, SZ(d) - 1);
    if (k == 1) return f[SZ(d) - 1];
    vi now;
    if (k & 1)
        now = cal(k - 1);
    else {
        now = cal(k / 2);
        vi vis(d.size(), SZ(now) - 1);
        for (auto i = 0; i < SZ(now); i++) umin(vis[now[i]], i * 1ll);
        vi tmp;
        for (int i = 0; i < SZ(now); i++) {
            int l = (now[i] ? vis[now[i] - 1] + 1 : 0);
            int r = vis[now[i]];
            for (int j = l; j <= r && SZ(tmp) < MAXN; j++) {
                tmp.eb(now[j]);
            }
        }
        now = tmp;
    }
    vi res;
    for (int i = 0; i < SZ(now); i++) {
        for (int j = 0; j < SZ(f[now[i]]) && SZ(res) < MAXN; j++) {
            res.eb(f[now[i]][j]);
        }
    }
    return res;
}
int32_t main() {
    close;
    int x, k;
    cin >> x >> k;
    for (ll i = 1ll; i * i <= x; i++) {
        if (x % i == 0) {
            d.eb(i);
            if (i != x / i) d.eb(x / i);
        }
    }
    sort(ALL(d));
    for (int i = 0; i < SZ(d); i++) {
        for (int j = 0; j <= i; j++) {
            if (d[i] % d[j] == 0) {
                f[i].eb(j);
            }
        }
    }
    vi ans = cal(k);
    for (int i = 0; i < SZ(ans); i++) {
        cout << d[ans[i]] << " ";
    }
    return 0;
}