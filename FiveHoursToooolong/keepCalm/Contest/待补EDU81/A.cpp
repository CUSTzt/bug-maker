/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-29 22:30:29
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
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n & 1){
			cout << 7;
			for(int i = 0; i < (n-3)/2;i++){
				cout << 1;
			}
		}else{
			for(int i = 0; i < n/2;i++){
				cout << 1;
			}
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