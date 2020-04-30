   for (ll k = 1; g[cnt] <= n; k++) {
        g[++cnt] = (3 * k * k - k) / 2;
        g[++cnt] = (3 * k * k + k) / 2;
    }