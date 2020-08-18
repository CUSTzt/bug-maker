
const int N = 4e5 + 10;
const int M = 2e6 + 10;

int g[N], nxt[M], v[M], w[M], ed;
ll d[N];
void add(int x, int y, int z) {
    v[++ed] = y, nxt[ed] = g[x], g[x] = ed, w[ed] = z;
    v[++ed] = x, nxt[ed] = g[y], g[y] = ed, w[ed] = z;
}
priority_queue<pii, vector<pii>, greater<pii> > q;
void dj(int s, int n, ll *d) {
    int x;
    for (int i = 1; i <= n; i++) d[i] = inf;
    q.push({d[s] = 0, s});
    while (!q.empty()) {
        pii t = q.top();
        q.pop();
        if (d[x = t.se] < t.fi) continue;
        for (int i = g[x]; i; i = nxt[i])
            if (d[x] + w[i] < d[v[i]]) {
                q.push({d[v[i]] = d[x] + w[i], v[i]});
            }
    }
}

void init(int n) {
    ed = 0;
    for (int i = 1; i <= n; i++) g[i] = 0;
}

char a[N];

void build(int x, int y, int z, int n, int X) {
    int x1 = x, x2 = x + n;
    if (a[y] == 'M') {
        int y1 = y, y2 = y + n;
        add(x1, y1, z);
        add(x1, y2, z + X);
        add(x2, y1, z + X);
        add(x2, y2, z);
        return;
    }
    if (a[y] == 'L') {
        add(x1, y, z);
        add(x2, y, z + X);
    } else {
        add(x2, y, z);
        add(x1, y, z + X);
    }
}

void solve() {
    int n, m, s, t, X;
    cin >> n >> m >> s >> t >> X;
    init(2 * n + 10);
    cin >> (a + 1);
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        if (a[x] != 'M' && a[y] != 'M') {
            if (a[x] != a[y])
                add(x, y, z + X);
            else
                add(x, y, z);
            continue;
        }
        if (a[x] == 'M')
            build(x, y, z, n, X);
        else
            build(y, x, z, n, X);
    }
    int st = n * 2 + 1, end = n * 2 + 2;
    add(st, s, 0);
    if (a[s] == 'M') add(st, s + n, 0);
    add(t, end, 0);
    if (a[t] == 'M') add(t + n, end, 0);
    dj(st, end, d);
    cout << d[end] << endl;
}