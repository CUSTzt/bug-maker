/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-18 17:58:35
# @Description: You build it. You run it 
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
int n , L;
int main()
{
	close;
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >> L;
		if(L == 1){
			cout << "1\n1 1 1 1\n";continue;
		} 
		if(n == 2){
			cout << "1\n1 1 2 2\n";continue;
		}
		if(n == L){
			cout << L/2 << endl;
			cout << "1 1 ";
			for(int i = 1; i <= n;i++){
				cout << i << " ";
			}cout << n<<" " << n << endl;
			continue;
		}
		int ans = L / 2;
		cout << ans << endl;
		int tot = 3 * ans + 1;
		cout << "2 2 ";
		for(int i = 2; i <= 2 + ans ; i++){
			cout << i << " ";
		}
		tot = tot - 2 - ans - 1;
		for(int i = 3; i <= tot+2; i++){
			cout << i << " ";
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
