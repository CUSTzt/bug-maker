// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
const int mod = 1e9 + 7;
const int MAXN = 55;  //几维就写几   不要多1的
// ll m[MAXN][MAXN]={};
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
};
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
int n;
ll k;
int main() {
    Matrix base;
    memset(base.mat, 0, sizeof base.mat);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> base.mat[i][j];
        }
    }
    Matrix ans = pow_mod(base, k);
    ll ANS = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ANS = (ANS + ans.mat[i][j]) % mod;
        }
    }
    cout << ANS << endl;
    return 0;
}