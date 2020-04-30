#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 1110;
const int P = 1e9+7;
ll inv[maxn],C[maxn][maxn],B[maxn];
ll work(int  n , int m){
    ll ret = inv[m+1];
    ll ans = 0;
    for(int i = 0; i <= m; i++){
        ans = (ans+C[m+1][i]*B[i]%P*bin(n , m+1-i,P)%P)%P;
    }
    return ans * ret % P;
}