#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
using LL = long long ;
constexpr int mod = 998244343;
constexpr int maxn = 1100;
ll inv[maxn], a[maxn],n,ans;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline void dfs(int x, int y){
    if(!x){
        ll res = 1;
        for(int i = 1; i <= n; ++i){
            res = res * i % mod;
        }
        for(int i = 1; i <y ; ++i){
            for(int j = 1; j <= a[i]; j++){
                int ct = a[i] - j;
                for(int k = i; k < y ; k++){
                    if(a[k] >= j)++ct;
                }
                res = res * inv[ct] % mod;
            }
            ans = (ans + res * res %mod *a[1] % mod) % mod;
        }
    }
    for(int i = 1; i <= x; i++){
            
    }
}
int main(){

}