#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using LL = long long;
const int maxn = 1110, T = 1000;
const int P = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
ll inv[maxn],C[maxn][maxn],B[maxn];
void pre(){
    int i,j;
    for(inv[0] = i = 1; i <= T+5; i ++)inv[i] = get_inv(i , mod);
    for(C[0][0] = i = 1;i<=T+5;i++){
        for(C[i][0] = j = 1; j <= i;j++){
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    for(i = 0; i <= T; i++){
        B[i] = i+1;
        for(j=0;j<i;j++)B[i]=(B[i]-1LL*C[i+1][j]*B[j])%P;
        B[i]=(1LL*inv[i+1]*B[i]%P+P)%P;
    }
}
ll Bernoulli_number(int  n , int m){
    ll ret = inv[m+1];
    ll ans = 0;
    for(int i = 0; i <= m; i++){
        ans = (ans+C[m+1][i]*B[i]%P*bin(n , m+1-i,P)%P)%P;
    }
    return ans * ret % P;
}
int main(){
    int n , m;
    cin>> n >> m;
    count << B
}