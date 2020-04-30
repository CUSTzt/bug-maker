// She is Pretty pretty!
// #include <bits/stdc++.h>
#include<cstring >
#include <iostream>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int MAXN = 110;
const int MAXM = 2000;
int n, t, S, E, u, v, w, cnt, dis[MAXN][MAXN], vis[MAXM];
struct Matrix {
    int a[MAXN][MAXN];
    Matrix() { memset(a, 0x3f, sizeof dis); }
    Matrix(int tmp[MAXN][MAXN]) {
        for (int i = 1; i <= cnt; i++)
            for (int j = 1; j <= cnt; j++) a[i][j] = tmp[i][j];
    }
    Matrix operator*(Matrix const &b) {
        int tmp[MAXN][MAXN];
        memset(tmp, 0x3f, sizeof tmp);
        for (int k = 1; k <= cnt; k++) {
            for (int i = 1; i <= cnt; i++) {
                for (int j = 1; j <= cnt; j++) {
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
void floyd(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                a.a[i][j] =min(a.a[i][j], a.a[i][k] + a.a[k][j]);
            }
}
int main() {
    cin >> n >> t >> S >> E;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= t; i++) {
        cin >> w >> u >> v;
        if (!vis[u]) vis[u] = ++cnt;
        if (!vis[v]) vis[v] = ++cnt;
        a.a[vis[u]][vis[v]] = w;
        a.a[vis[v]][vis[u]] = w;
    }
    Matrix ans = Matrix((a ^ n).a);
    cout << ans.a[vis[S]][vis[E]];
    return 0;
}