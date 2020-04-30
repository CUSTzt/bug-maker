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
int inv6 = 3323403, mod = 19940417;
int n , m;
int fenkuai(int x){
    int ans = x * x % mod;
    for(int l = 1, r; l <= x; l = r+1){
        r = x / (x / l);
        ans = (ans + mod - (l+r) * (r - l + 1) / 2 % mod *(x / l) % mod) % mod;
    }return ans;
}
int i2(int x){
    return x * (x+1) % mod * inv6 % mod * (2*x+1) % mod;
}
int work(int n , int m){
    if(n > m)swap(n , m);//n < m
    int ans = fenkuai(n) * fenkuai(m) % mod;
    for(int l = 1, r ; l <= n ; l = r + 1){
        r = min(n / (n / l), m / (m / l));
        int sum1 , sum2 , sum3;
        sum1 = (n * m % mod * (r-l+1) % mod);
        sum2 = (n / l ) * (m / l) % mod * (i2(r) - i2(l-1) + mod) % mod;
        sum3 = (r - l + 1) * (l + r) / 2 % mod * (n / l * m % mod + m / l * n % mod) % mod;
        int qianqu = (sum1 + sum2 - sum3) % mod;
        ans = (ans + mod - qianqu) % mod;
        //printf("sum1 === %lld,  sum2 === %lld , sum3 === %lld , ans=== % lld \n",sum1 , sum2 , sum3 , ans);
        //cout << "l === " << l << endl;
    } return (ans + mod) % mod;
}
int32_t main()
{
    cin >> n >> m;
    cout << work(n , m) << endl;
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/