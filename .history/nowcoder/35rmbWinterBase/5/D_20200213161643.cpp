/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 15:20:35
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int main()
{
    int t ;
    double a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a <= b){
            cout << b-a << endl;continue;
        }
        double ans = 0.0;
        while(a > b){
            double gx = pow(a , 1.0/3);
            /*if(gx >= b && (gx >= 1 && a>=1)&& (a-gx-1.0) >= eps){
                a = gx;ans+=1;
                continue;
            }else {
                ans += (gx-b);
            }*/
        }printf("%.9f\n",ans);
    }
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/