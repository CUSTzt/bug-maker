n = read(), m = read();
for (int i = 1; i <= m; i++) f[i] = i;
for (int i = 1; i <= n; i++) {
    int len = read();
    V[i].resize(len);
    for (auto &v : V[i]) v = read();
    if (V[i].size() == 2) {
        int x = find(V[i][0]), y = find(V[i][1]);
        if (x == y || (flg[x] && flg[y]))
            continue;
        else {
            f[x] = y, flg[y] |= flg[x], ans[++cnt] = i;
        }
    } else {
        int x = find(V[i][0]);
        if (flg[x]) continue;
        flg[x] = 1, ans[++cnt] = i;
    }
}
int zz = 1;
for (int c = 1; c <= cnt; c++) zz = 2 * zz % mod;
printf("%d %d\n", zz, cnt);
for (int i = 1; i <= cnt; i++) {
    printf("%d ", ans[i]);
}
