 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月09日 星期三 20时06分05秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int  n , k , a[maxn], b[maxn];
double p[maxn];
bool isok(double x){
    for(int i = 0; i < n;i++)
        p[i] = a[i] - x*b[i];
    sort(p,p+n);
    double ans = 0;
    for(int i = n-1;i >= k; i--)ans += p[i];
    return ans >= 0;
}
int main(){
    while(cin >> n >> k && n+k){
        for(int i = 0; i < n;i++){
           scanf("%d", &a[i]); 
        }
        for(int i = 0; i < n;i++){
           scanf("%d", &b[i]); 
        }
        double l = 0, r = 1;
        while(r - l > eps){
            double mid = (l+r) / 2;
            if(isok(mid))l = mid ;
            else r = mid;
        }
        int ans = (0.005+l)*100;
        cout << ans << endl;
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
