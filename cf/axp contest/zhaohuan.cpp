#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];
int p[N];
int l[N];
int c[N];
int v[N][N];
int id[N];
bool b[N];
int ans[N];

int n, k;
uint64_t m;

void f(int q, int x) {
    if (b[x]) return;
    b[x] = 1;
    c[x] = q;
    id[x] = l[q];
    v[q][l[q]++] = x;
    f(q, p[x]);
}

int main() {
    freopen("data.in","r",stdin);
    freopen("out.txt","w",stdout);
    int qid;
    cin >> qid;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) cin >> a[i], p[i] = i;
        int x, y;
        while (k--) {
            cin >> x >> y;
            swap(p[x], p[y]);
        }
        memset(b, 0, sizeof b);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x = p[i];
            if (!b[x]) {
                l[cnt] = 0;
                f(cnt++, x);
            }
        }
        for (int i = 1; i <= n; i++) {
            int g = c[i];
            int len = l[g];
            int be = id[i];
            ans[i] = a[v[g][(be + m % len) % len]];
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? '\n' : ' ');
    }
}
