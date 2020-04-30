/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-03-14 13:26:38
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;

int main()
{
    for(int i = 1;i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(__gcd(i , j) >= 2){
                cout << "O";
            }else cout << "X";
        }
        cout << endl;
    } 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
