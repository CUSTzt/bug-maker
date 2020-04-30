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
int n, t, S, E, u, v, w, dis[MAXN][MAXN];
std::tuple<int, int, int> e[MAXM];
int cnt;
struct Matrix {
    int a[MAXN][MAXN];
    Matrix() {}
    Matrix(int tmp[MAXN][MAXN]) {
        for (int i = 1; i <= cnt; i++)
            for (int j = 1; j <= cnt; j++) a[i][j] = tmp[i][j];
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
    cin >> t >> n >> S >> E;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) {
        cin >> w >> u >> v;
        e[i] = {u, v, w};
        dis[u][v] = dis[v][u] = min(w, dis[u][v]);
    }
    floyd(n);
    a = Matrix(dis);
    Matrix ans = Matrix((a ^ t).a);
    for (int i = 1; i <=) cout << ans.a[S][E];
    return 0;
}