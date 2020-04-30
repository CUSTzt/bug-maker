// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

// #define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

const int MAXN = 1100;
const int MAXM = 2000;
int n, t, S, E, u, v, w, cnt, dis[MAXN][MAXN], vis[MAXM];
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
        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= cnt; j++) {
                for (int k = 1; k <= cnt; k++) {
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
    cout << "sss" << endl;
    cin >> n >> t >> S >> E;
    memset(dis,0x3f,sizeof dis);
    // memset(a.a, 0x3f, sizeof a.a);
    for (int i = 1; i <= t; i++) {
        cin >> w >> u >> v;
        if (!vis[u]) vis[u] = ++cnt;
        if (!vis[v]) vis[v] = ++cnt;
        a.a[vis[u]][vis[v]] = w;
        a.a[vis[v]][vis[u]] = w;
    }
    a=Matrix(dis);
    Matrix ans = Matrix((a ^ t).a);
    cout << "qq\n";
    // cout << ans.a[1][1];
    // cout << ans.a[vis[S]][vis[E]];
    // cout << 1  << endl;
    return 0;
}