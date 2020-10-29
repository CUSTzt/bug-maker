/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-27 10:30:59
# @Description: You build it. You run it
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
    int a[3];
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }sort(a, a+3);
    if(a[0] == 5 && a[1] == 5 && a[2] == 7)puts("YES");
    else puts("NO");
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/