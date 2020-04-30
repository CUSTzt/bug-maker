//奇数层阶梯上异或和，SG=0必败
/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-28 16:10:10
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
//#include<bits/stdc++.h>
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
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn];
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int fl = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int bi = 1;
        if(n & 1)bi = 0;
        for(int i = n; i >= 1; i--){
            if((bi+i) & 1)fl ^= (a[i] - a[i-1]);
        }
        puts(fl?"TAK":"NIE"); 
    }
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/