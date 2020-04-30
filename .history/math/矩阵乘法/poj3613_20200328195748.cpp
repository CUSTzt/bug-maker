// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

const int N = 1e6 + 100;
// noi oline pj t3
const int MAXN = 1100;
const int MAXM = 1e6 + 10;
int n, t, S, E, k, u, v, w, cnt, dis[MAXN][MAXN], vis[MAXM];
std::tuple<int, int, int> e[MAXM];
struct Matrix {
    int a[MAXN][MAXN];
    Matrix() {}
    Matrix(int tmp[MAXN][MAXN]) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) a[i][j] = tmp[i][j];
    }
    Matrix operator*(Matrix const &b) {
        int tmp[MAXN][MAXN];
        memset(tmp, 0x3f, sizeof tmp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    tmp[i][j] = min(tmp[i][j], a[i][k] + b.a[k][j]);
                }
            }
        }
        return Matrix(tmp);
    }
    friend Matrix operator^(Matrix base, int n) {
        Matrix res = base;
        n--;
        for (; n; n >>= 1, base = base * base) {
            if (n & 1) {
                res = res * base;
            }
        }
        return res;
    }
} a;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t >> S >> E;
    memset(a.a, 0x3f, sizeof a.a);
    for (int i = 1; i <= t; i++) {
        cin >> w >> u >> v;
        if (!vis[u]) vis[u] = ++cnt;
        if (!vis[v]) vis[v] = ++cnt;
        a.a[vis[u]][vis[v]] = a.a[vis[v]][vis[u]] = w;
    }
    Matrix ans = Matrix((a^k).a);
    cout << ans.a[vis[s]][vis[t]];
    return 0;
}