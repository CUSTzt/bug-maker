// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
const int MAXN = 110;
const int MAXM = 2505;
int n, m, k, u, v, w, dis[MAXN][MAXN];
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
    /*Matrix Qpow(ll p)  //矩阵快速幂,求a^p
    {
        --p;
        Matrix res = *this, cur = *this;
        while (p) {
            if (p & 1) res = res * cur;
            cur = cur * cur;
            p >>= 1;
        }
        return res;
    }*/
} a;
void floyd(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    // a=Matrix(dis);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        dis[u][v] = min(dis[u][v], w);
    }
    floyd(n);
    a = Matrix(dis);
    if (k == 0) {
        return cout << dis[1][n], 0;
    }
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = e[i];
        for (int s = 1; s <= n; s++) {
            for (int t = 1; t <= n; t++) {
                a.a[s][t] = min(a.a[s][t], dis[s][u] + dis[v][t] - w);
            }
        }
    }
    Matrix ans = Matrix((a ^ k).a);
    cout << ans.a[1][n];
    // cout << a.Qpow(k).a[1][n];
    return 0;
}