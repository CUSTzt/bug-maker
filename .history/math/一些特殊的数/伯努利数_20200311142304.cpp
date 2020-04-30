#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using LL = long long;
const int maxn = 1110;
const int P = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
ll inv[maxn],C[maxn][maxn],B[maxn];
ll Bernoulli(int  n , int m){
    ll ret = inv[m+1];
    ll ans = 0;
    for(int i = 0; i <= m; i++){
        ans = (ans+C[m+1][i]*B[i]%P*bin(n , m+1-i,P)%P)%P;
    }
    return ans * ret % P;
}
