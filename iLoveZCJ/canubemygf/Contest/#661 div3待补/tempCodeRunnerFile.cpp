++cnt;
        S += w;
        weight[u] /= 2;
        h.emplace(1ll * siz[u] * (weight[u] + 1 / 2), u);