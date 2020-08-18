
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long

ll tree[2000020];
ll lazy[2000020];
ll a[505050];
ll b[505050];
ll c[2000020];
int n, m;
ll ask(int x) {
    ll ans = 0;
    while (x) {
        ans += c[x];
        x -= x & -x;
    }
    return ans;
}

void add(int x, ll y) {
    while (x <= n) {
        c[x] += y;
        x += x & -x;
    }
}

void build(int l, int r, int root) {
    if (l == r) {
        tree[root] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    tree[root] = __gcd(tree[root << 1], tree[root << 1 | 1]);
}

ll searcharea(int l, int r, int root, int L, int R) {
    if (L <= l && R >= r) {
        return tree[root];
    }
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid) ans = __gcd(searcharea(l, mid, root << 1, L, R), ans);
    if (R > mid) ans = __gcd(searcharea(mid + 1, r, root << 1 | 1, L, R), ans);
    return abs(ans);
    // return __gcd(searcharea(l, mid, root<<1, L, mid), searcharea(mid+1, r,
    // root<<1|1, mid+1, R));
}

void changepoint(int l, int r, int root, int point, ll val) {
    if (l == r) {
        tree[root] = tree[root] + val;
        return;
    }
    int mid = (l + r) >> 1;
    if (point <= mid)
        changepoint(l, mid, root << 1, point, val);
    else
        changepoint(mid + 1, r, root << 1 | 1, point, val);
    tree[root] = __gcd(tree[root << 1], tree[root << 1 | 1]);
}

const int MAXN = 1e8 + 100;
int prime[MAXN], phi[MAXN], miu[MAXN], pre[MAXN];
bool is_prime[MAXN];
int INIT(int n) {
    int p = 0;
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) prime[p++] = i, pre[i] = i;
        for (int j = 0; j < p; j++) {
            if (prime[j] * i > n) break;
            is_prime[prime[j] * i] = false;
            pre[prime[j] * i] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    return p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    INIT(MAXN - 10);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
        //      add(i, a[i] - a[i-1]);
    }
    build(1, n, 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int ta, tb;
        cin >> ta >> tb;
        cout << pre[a[ta] + ask(ta)] << endl;
    }
    return 0;
}