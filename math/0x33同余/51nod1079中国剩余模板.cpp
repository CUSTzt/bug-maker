 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-10-05 16:44:48
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
//#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
#define int long long 
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int ext_gcd(int a, int b, int &x,int &y){
	if(b == 0){x = 1,y = 0;return a;}
	int d = ext_gcd(b, a%b, x, y);
	int z = x;x = y;y = z - y * (a/b);
	return d;
}
int M;
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
    return R > 0 ? R : R+M;
}
int m[maxn], r[maxn];
 main()
{
	int n ;
	while(cin >> n){
	for(int i = 0; i < n;i++){
		cin >> m[i] >> r[i];
	}
	int ans = CRT(m , r , n);
	if(ans == -1)cout << -1 <<endl;
	else cout << (ans+M)%M <<endl;}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/