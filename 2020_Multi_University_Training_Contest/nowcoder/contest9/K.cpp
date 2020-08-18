#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 1e5 + 10;

int f[N];
int g[N], nxt[N << 1], v[N << 1], ed;
void add(int x, int y) { v[++ed] = y, nxt[ed] = g[x], g[x] = ed; }

void dfs(int x, int fa) {
    f[x] = fa;
    for (int i = g[x]; i; i = nxt[i]) {
        int to = v[i];
        if (to == fa) continue;
        dfs(to, x);
    }
}

int vis[N], d[N], d2[N];
int st, n;
void bfs() {
    queue<int> q;
    q.push(n);
    vis[n]++;
    d[n] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = g[x]; i; i = nxt[i]) {
            int to = v[i];
            if (!vis[to]) {
                vis[to]++;
                d[to] = d[x] + 1;
                q.push(to);
            }
        }
    }
}

int ans = 0;

void bfs2() {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(st);
    d2[st] = 0;
    vis[st]++;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = g[x]; i; i = nxt[i]) {
            int to = v[i];
            if (!vis[to]) {
                vis[to]++;
                d2[to] = d2[x] + 1;
                if (d2[to] >= (d[to] + 1) / 2) {
                    ans = max(ans, (d[to] + 1) / 2);
                } else {
                    vis[to]++;
                    ans = max(ans, (d[to] + 1) / 2);
                    q.push(to);
                }
            }
        }
    }
}
int main() {
    //    IN;
    IOS;
    int t;
    cin >> n >> t;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    VI path;
    int now = n;
    path.pb(n);
    while (f[now]) {
        path.pb(f[now]);
        now = f[now];
    }
    reverse(all(path));
    if (t >= sz(path) - 1) {
        cout << 0 << endl;
        return 0;
    }
    st = path[t];
    bfs();
    bfs2();
    cout << ans << endl;
    return 0;
}