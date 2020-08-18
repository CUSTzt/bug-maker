
ll ans[MAXN << 2];
void cover(int l, int n) {
    for (int i = 0; i < n; ++i) {
        ans[l + i] += (i + 2) / 2;
        if (i != 2 * n - 2 - i) ans[l + 2 * n - 2 - i] += (i + 2) / 2;
    }
}
void init() {
    for (int i = 1; i <= MAXN / 3; ++i) {
        int begin = i * 3 + 3, cur = 1;
        while (begin < MAXN) {
            cover(begin, cur);
            cur++;
            begin += i;
        }
    }
}

void solve() {
    init();
    for (int i = 1; i < MAXN; ++i) {
        // cout << ans[i] << ",";
        ans[i]+=ans[i-1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("fuck.txt", "w", stdout);
    solve();
    return 0;
}
