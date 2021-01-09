
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 200010;

struct Node {
    int u, v, w;
} e[maxn];

int n, m, ans;
int p[maxn];

int Find(int x) {
    return x == p[x] ? x : p[x] = Find(p[x]);
}

bool cmp(const Node &A, const Node &B) { return A.w < B.w; }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1, j = 1; i <= m; i = j) {
        while (j <= m && e[j].w == e[i].w) j++;
        int cnt = j - i;
        for (int t = i; t < j; t++) {
            int fx = Find(e[t].u), fy = Find(e[t].v);
            if (fx == fy) cnt--;
        }
        for (int t = i; t < j; t++) {
            int fx = Find(e[t].u), fy = Find(e[t].v);
            if (fx == fy) continue;
            cnt--;
            p[fx] = fy;
        }
        ans += cnt;
    }
    printf("%d", ans);
    return 0;
}