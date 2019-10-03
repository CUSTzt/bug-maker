 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-30 21:33:13
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
//#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[105],n ,t ,ans;
int main()
{
    close;
	cin >> t;
	while(t--){
        cin >> n;
        for(int i =1; i <= n;i++)cin >> a[i];
        for(int i = 1,j; i <= n;i++){
            cin >> j;
            a[i] ^= j;
            //a[i][i] = 1; 
            a[i] |= 1 << i;
        }
        int x, y;
        while(cin >> x >> y && x && y){
            a[y] |= 1 << x;//a[y][x] = 1;
        }        
        ans =1;
        for(int i =1; i <= n;i++){
            //找到最大的一个a[i]  即主元位数最高的a[i]
            for(int j = i+1; j <= n;j++)
                if(a[j] > a[i]) swap(a[i] , a[j]);
            //消元完毕，有i-1个主元，n-i+1个自由元
            if(a[i] == 0){
                ans = 1 << (n-i+1);
                //cout << 'A' << ans << endl;
                break;
            }
            //出现 0 = 1 的情况 无解
            if(a[i] == 1){
                ans = 0;
               // cout << 'B' << endl;
                break;
            }
            //a[i] 最高位的1作为主元，消去其他方程该位的系数
            for(int k = n;k ;k--){
                if(a[i] >> k & 1){
                    for(int j = 1; j <= n;j++)
                        if(i != j && (a[j] >> k & 1))a[j] ^= a[i];
                    break;
                }
            }
        }
            if(ans == 0)cout << "Oh,it's impossible~!!" <<endl;
            else cout << ans << endl;
    }
}


/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/
