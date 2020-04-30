#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
constexpr int mod = 998244343;
constexpr int maxn = 1100;
ll inv[maxn], a[maxn],n;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}

int main(){

}