/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-06 21:56:29
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
int x , n , a[maxn];
int main()
{
    cin >> n >> x;
    ll sum = 0;
    for(int i = 1; i < n;i++){
        if(a[i-1] + a[i] >= x){
            if(x <= a[i]){
                //a[i-1] = 0,a[i] = x;
                sum += a[i-1];
                sum += a[i]-x;
                a[i-1] = 0,a[i] = x;
            }
        }
    }
    
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/