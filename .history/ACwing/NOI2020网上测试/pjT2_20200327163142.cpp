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

const int MAXN = 105;
const int MAXM = 2550;
// ll m[MAXN][MAXN] = {};
struct Matrix {
    ll mat[MAXN][MAXN];
    Matrix() {}
    Matrix operator*(Matrix const &b) const {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.mat[i][j] =
                        min(res.mat[i][j], this->mat[i][k] + b.mat[k][j]);
        return res;
    }
} a;
Matrix pow_mod(Matrix base, ll n) {
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for (int i = 0; i < MAXN; i++) res.mat[i][i] = 1;
    while (n > 0) {
        if (n & 1) res = res * base;
        base = base * base;
        n >>= 1;
    }
    return res;
}
int n, m, k, dis[MAXN][MAXN], u, v, w;
std::tuple<int, int, int> e[MAXM];
void Floyd(int n) {
    for (ll k = 1; k <= n; ++k)
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(a.mat, 0, sizeof a.mat);
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a.mat[i][j] = dis[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        dis[u][v] = w;
    }
    Floyd(n);
    if (k == 0) {
        return cout << dis[1][n], 0;
    }
    for (ll i = 1; i <= m; ++i) {
        auto [u, v, w] = e[i];
        for (ll s = 1; s <= n; ++s)
            for (ll t = 1; t <= n; ++t)
                a.mat[s][t] = min(a.mat[s][t], dis[s][u] - w + dis[v][t]);
    }

    Matrix ans = pow_mod(a, k);
    cout << ans.mat[0][k];
    return 0;
}