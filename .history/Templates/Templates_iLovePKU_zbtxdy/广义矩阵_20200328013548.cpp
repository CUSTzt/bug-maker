// noi online pjT3
const int MAXN = 110;
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