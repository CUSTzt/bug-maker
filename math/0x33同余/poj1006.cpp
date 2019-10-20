 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月05日 星期六 14时52分05秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
//#include<bits/stdc++.h>
//poj1006
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[3]= {23, 28, 33}, b[3] , d, M ;
int ext_gcd(int a, int b, int &x,int &y){
	if(b == 0){x = 1,y = 0;return a;}
	int d = ext_gcd(b, a%b, x, y);
	int z = x;x = y;y = z - y * (a/b);
	return d;
}
int CRT(int *m, int *r, int n){
    if(!n) return 0;
    M = m[0];
    int  R =r[0], x, y , d;
    for(int i = 1; i < n;i++){
        d = ext_gcd(M, m[i], x, y);
        if((r[i] - R) % d)return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M/d*m[i];
        R %= M;
    }
    return R >= 0 ? R : R+M;
}
int main(){
    int tt = 0;
    while(cin >> b[0] >> b[1] >> b[2] >> d){
        if(d == -1)break;
        int ans = CRT(a, b , 3);
        ans = ((ans - d) % M + M ) % M;
        if(ans == 0)ans = M;
        // cout << ans << endl;
        printf("Case %d: the next triple peak occurs in %d days.", ++tt , ans);
        cout << endl;
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
