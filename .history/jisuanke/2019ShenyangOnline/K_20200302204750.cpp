/*#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
typedef long long ll;

#define int long long 
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
/*#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;*/
const int mod = 1e9+7;
typedef double LD;
const LD eps = 1E-10;
const int maxn = 70 + 10;

int n;
int a[maxn][maxn], x[maxn];
bool free_x[maxn];

inline int sgn(LD x) { return (x > eps) - (x < -eps); }

int gauss(int a[maxn][maxn], int n, int m) {
    memset(free_x, 1, sizeof free_x);
    memset(x, 0, sizeof x);
    int r = 0, c = 0;
    while (r < n && c < m) {
        int m_r = r;
        FOR (i, r + 1, n)
            if (fabs(a[i][c]) > fabs(a[m_r][c])) m_r = i;
        if (m_r != r)
            FOR (j, c, m + 1)
                 swap(a[r][j], a[m_r][j]);
        if (!sgn(a[r][c])) {
            a[r][c] = 0;
            ++c;
            continue;
        }
        FOR (i, r + 1, n)
            if (a[i][c]) {
                LD t = a[i][c] / a[r][c];
                FOR (j, c, m + 1) a[i][j] -= a[r][j] * t;
            }
        ++r; ++c;
    }
    FOR (i, r, n)
        if (sgn(a[i][m])) return -1;
    if (r < m) {
        FORD (i, r - 1, -1) {
            int f_cnt = 0, k = -1;
            FOR (j, 0, m)
                if (sgn(a[i][j]) && free_x[j]) {
                    ++f_cnt;
                    k = j;
                }
            if(f_cnt > 0) continue;
            LD s = a[i][m];
            FOR (j, 0, m)
                if (j != k) s -= a[i][j] * x[j];
            x[k] = s / a[i][k];
            free_x[k] = 0;
        }
        return m - r;
    }
    FORD (i, m - 1, -1) {
        LD s = a[i][m];
        FOR (j, i + 1, m)
            s -= a[i][j] * x[j];
        x[i] = s / a[i][i];
    }
    return 0;
}

const int MAXN = 80; //几维就写几   不要多1的
ll m[MAXN][MAXN]={
};
struct Matrix
{
    ll mat[MAXN][MAXN];
    Matrix() {}
    /*Matrix operator*(Matrix const &b)const
    {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.mat[i][j] = (res.mat[i][j]+this->mat[i][k] * b.mat[k][j])%mod;
        return res;
    }*/
};
Matrix mul(Matrix a,Matrix b,int n){
    Matrix c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c.mat[i][j]=(c.mat[i][j]+1LL*a.mat[i][k]*b.mat[k][j]%mod)%mod;
            }
        }
    }
    return c;
}
Matrix pow_mod(Matrix base, ll n,int k)
{
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for (int i = 0; i < MAXN; i++)
        res.mat[i][i] = 1;
    while (n > 0){
        if (n & 1) res=mul(res,base,k);//res = res*base;
        //base = base*base;
        base=mul(base,base,k);
        n >>= 1;
    }
    return res;
}
int t[maxn];
int32_t main()
{
    CASET{
        for(int i = 0;i<maxn;i++)
        for(int j = 0;j<maxn;j++)a[i][j] = 0;
        int n , k;
        cin >> k >>n;
        for(int i = 1;i <= 2*k;i++){
            cin >> t[i];
        }
        if(n <= 2ll*k){
            ll anss = 0;
            for(int i = 0; i <n;i++)anss=(anss+t[i])%mod;
            cout << anss << endl;continue;
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                a[i][j]=t[k+i-j];
            }
        }
        for(int i=0;i<k;i++) a[i][k]=t[i+1+k];
        gauss(a, k , k);
        Matrix A;
        for(int i=0;i <k;i++)A.mat[0][i]=x[i];
        for(int i=1;i<k;i++) A.mat[i][i-1]=1;
        A.mat[k][0]=1;A.mat[k][k]=1;
        A=pow_mod(A,n-k,k+1);
         for(int i = 0; i<2*k;i++){
            for(int j = 0; j <2*k;j++){
                cout << A.mat[i][j] << ' ';
            }puts("");
        }
        Matrix B;
        memse
        for(int i=0;i<k;i++){
            B.mat[i][0]=t[k-i];
            B.mat[k][0]+=t[i+1];
        }
        A=mul(A,B,k+1);
        for(int i = 0; i<2*k;i++){
            for(int j = 0; j <2*k;j++){
                cout << A.mat[i][j] << ' ';
            }puts("");
        }
        printf("%lld\n",A.mat[k][0]);
    }
    
}