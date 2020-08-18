// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 500;

int S, T, n, m, off[N], t[N][2], r[N];
struct edge {
    int v, w;
    /* data */
};
vector<edge> E[N];
struct node {
    int x, d;
    bool operator<(const node& a) const { return d < a.d; }
    /* data */
};
priority_queue<node> q;
int dis[N], f[N];
void dijstra() {
    memset(dis, 0x3f, sizeof dis);
    dis[S] = 0;
    q.push({S, 0});
    while (q.size()) {
        node fro = q.top();
        q.pop();
        int x = fro.x, d = fro.d;
        if (d != dis[x]) {
            continue;
        }
        for (auto v : E[x]) {
            int ks = 0;
            while (ks < 400) {
                int zz = ks + d;
                if (((zz + off[x]) % (t[x][0] + t[x][1]) < t[x][0]) ==
                    ((zz + off[v.v]) % (t[v.v][0] + t[v.v][1]) < t[v.v][0])) {
                    break;
                }
                ks++;
            }
            if (ks < 400 && dis[v.v] > dis[x] + v.w + ks) {
                dis[v.v] = dis[x] + v.w + ks;
                f[v.v] = x;
                q.push({v.v, dis[v.v]});
            }
        }
    }
}
char tmp[100];
int main() {
    cin >> S >> T >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s %d %d %d\n", tmp, r + i, t[i] + 0, t[i] + 1);
        off[i] = t[i][0] + t[i][1] - r[i] - (tmp[0] == 'B' ? t[i][1] : 0);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        E[u].push_back({v, l});
        E[v].push_back({u, l});
    }
    dijstra();
    if (dis[T] < 0x3f3f3f3f) {
        printf("%d\n", dis[T]);
        vector<int> ans;
        int x = T;
        while (x != S) {
            ans.push_back(x);
            x = f[x];
        }
        printf("%d", S);
        reverse(ans.begin(), ans.end());
        for (auto v : ans) {
            printf(" %d", v);
        }
        printf("\n");
    } else {
        puts("0");
    }
    return 0;
}