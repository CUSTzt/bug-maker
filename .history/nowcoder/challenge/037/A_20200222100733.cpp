#include <stack>
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
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
#define int long long 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
const int MAXN = 16; //几维就写几   不要多1的
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
int chk(int x){
    int ret = 0;
    while (x){
        ret += x & 1;
        x >>= 1;
    }return ret;
}
int32_t main()
{
    int n;cin >> n;
    Matrix xx;
    memset(xx.mat, 0 ,sizeof xx.mat);
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            if(chk(i^j) == 1)xx.mat[i][j] = 1;
            else xx.mat[i][j] = 0;
        }
    }
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16;j++){
            cout << xx.mat[i][j] <<' ';
        }puts("");
    }
    xx = pow_mod(xx , n);
    cout << xx.mat[0][3] <<endl;
}