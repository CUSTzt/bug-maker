typedef long long ll;
ll mod_pow(ll x, ll n ,ll mod){
	ll res = 1;
	while(n > 0){
		if(n & 1)res = res *x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}




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



struct Matrix {
    int v[M][M];
    Matrix() { memset(v, 0, sizeof v); }
    Matrix operator+(const Matrix& rhs) {
        static Matrix res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j) res.v[i][j] = pls(v[i][j], rhs.v[i][j]);
        return res;
    }
    Matrix operator*(const Matrix& rhs) {
        Matrix res;
        for (int i = 0; i < m; ++i)
            for (int k = 0; k < m; ++k)
                for (int j = 0; j < m; ++j) inc(res.v[i][j], 1LL * v[i][k] * rhs.v[k][j] % mod);
        return res;
    }
    void init(void) {
        memset(v, 0, sizeof v);
        for (int i = 0; i < m; ++i) v[i][i] = 1;
    }
    Matrix operator^(int k) {
        Matrix res, base;
        base = *this, res.init();
        while (k) {
            if (k & 1)
                res = res * base;
            base = base * base;
            k >>= 1;
        }
        return res;
    }
};