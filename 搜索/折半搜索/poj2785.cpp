 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月10日 星期四 21时11分14秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 4005;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n ,A[maxn],B[maxn],C[maxn],D[maxn];
int CD[maxn*maxn];
void solve(){
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            CD[i*n+j] = C[i] + D[j];
        }
    }
    sort(CD,CD+n*n);
    ll res = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            int kk = -(A[i] + B[j]);
            res += upper_bound(CD,CD+n*n,kk) - lower_bound(CD,CD+n*n,kk);
        }
    }
    cout << res << endl;
}
int main(){
    cin >> n ;
    for(int i = 0; i < n;i++){
        scanf("%d%d%d%d", &A[i], &B[i],&C[i],&D[i]);
    }
    solve();
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
