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
                        (res.mat[i][j] + this->mat[i][k] * b.mat[k][j]) % mod;
        return res;
    }
}a;
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
int n , m , k, dis[MAXN][MAXN], u , v , w;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(a.mat, 0 , sizeof a.mat);

    return 0;
}