#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 500010;
char s[N];
int n, sa[N], rk[N << 1], oldrk[N << 1], id[N], px[N], cnt[N], ht[N], sta[N],
    top, l[N];
long long ans;
bool cmp(int x, int y, int w) {
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
int main() {
    int i, k, w, p, m = 300;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    ans = 1ll * n * (n - 1) * (n + 1) / 2;
    for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
    for (w = 1; w < n; w <<= 1, m = p) {
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;
        for (i = 1; i <= n; ++i)
            if (sa[i] > w) id[++p] = sa[i] - w;
        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[px[i]]--] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        for (p = 0, i = 1; i <= n; ++i)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    for (i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        ht[rk[i]] = k;
    }
    for (i = 1; i <= n; ++i) {
        while (ht[sta[top]] > ht[i]) --top;
        l[i] = i - sta[top];
        sta[++top] = i;
    }
    sta[++top] = n + 1;
    ht[n + 1] = -1;
    for (i = n; i >= 1; --i) {
        while (ht[sta[top]] >= ht[i]) --top;
        ans -= 2ll * ht[i] * l[i] * (sta[top] - i);
        sta[++top] = i;
    }
    cout << ans;
    return 0;
}