/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 20:39:58
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
int exgcd(int a, int b ,int & x, int &y){  //求出6模19940417下的逆元3323403
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a%b , x , y);
	int z = x;x = y;y = z - y *(a / b);
	return d;
}
int inv6 = , mod = 
int32_t main()
{
    
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/