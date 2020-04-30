
const int MAXN = ; //几维就写几   不要多1的
ll m[MAXN][MAXN]={
};
struct Matrix
{
    ll mat[MAXN][MAXN];
    Matrix() {}
    Matrix operator*(Matrix const &b)const
    {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.mat[i][j] = (res.mat[i][j]+this->mat[i][k] * b.mat[k][j])%mod;
        return res;
    }
};
Matrix pow_mod(Matrix base, ll n)
{
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for (int i = 0; i < MAXN; i++)
        res.mat[i][i] = 1;
    while (n > 0){
        if (n & 1) res = res*base;
        base = base*base;
        n >>= 1;
    }
    return res;
}