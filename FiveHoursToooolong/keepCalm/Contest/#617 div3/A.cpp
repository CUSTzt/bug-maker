/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-04 22:33:26
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
int t , n , a[maxn];
int main()
{
	cin >> t;
	while(t--){
		cin >> n;
		int fl = 0;
		for(int i = 0; i < n;i++){
			cin >> a[i];
			if(i >= 1 && (a[i]%2!=a[i-1]%2))fl=1;
		}
		if(!fl){
			if((a[0]&1)==1 && n %2==0){puts("NO");continue;}
			if(a[0] %2==0){
				puts("NO");continue;
			}
		}puts("YES");
 
	}
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/