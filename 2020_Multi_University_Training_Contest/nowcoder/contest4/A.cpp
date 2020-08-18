// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
vector<int> vec[N];
int dep[N], tmp[N], fa[N], pos[N], tim;
void dfs(int x) {
    pos[++tim] = x;
    for (auto i : vec[x]) {
        dep[i] = dep[x] + 1;
        dfs(i);
    }
}
ll ans[N];
int n;
void build(int lenl, int lenr, int kl, int kr) {
    if (lenl > lenr || kl > kr) return;
    if (kl == kr) {
        for (int i = lenl; i <= lenr; i++) ans[i] = kl;
        return;
    }
    int mid = lenl + lenr >> 1;
    ans[mid] = 0;
    for (int i = 1; i <= n; i++) tmp[i] = dep[i];
    for (int i = n; i; i--) {
        int x = pos[i];
        if (tmp[x] == dep[x] + mid || x == 1) ans[mid]++, tmp[x] = -1;
        tmp[fa[x]] = max(tmp[fa[x]], tmp[x]);
    }
    build(lenl, mid - 1, ans[mid], kr);
    build(mid + 1, lenr, kl, ans[mid]);
}
int main() {
    while (~scanf("%d", &n)) {
        tim = 0;dep[1] = 0;
        for (int i = 1; i <= n; i++) vec[i].clear();
        for (int i = 2; i <= n; i++)
            scanf("%d", &fa[i]), vec[fa[i]].push_back(i);
        dfs(1);int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, dep[i]);
        build(0, mx, 1, n);
        ll sum = 0;
        for (ll i = 1; i <= mx; i++) sum += i * (ans[i - 1] - ans[i]);
        printf("%lld\n", sum);
    }
    return 0;
}