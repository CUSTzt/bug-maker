/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-30 09:59:17
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int phi(int n){
	int ans = n;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			ans = ans / i *(i-1);
			while(n%i == 0)n/=i;
		}
	}
	if(n > 1) ans =ans / n * (n-1);  //质数
	return ans;
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--){
        int a, m ;
        cout << phi(m / __gcd(a, m))<<endl;;
    }
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/