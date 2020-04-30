/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-14 13:31:15
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
#define int long long 
const int maxn = 1106;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn][maxn], b[maxn],ans[maxn];
int32_t main()
{
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			cin >> a[i][j];
			sum += a[i][j];
			b[i] += a[i][j];
		}
	}
	if(n == 2){
		//cout << a[0][1] << " " << a[1][0] << endl;
		cout << 1 << " " <<  1 << endl;
		return 0;
	}
	sum /= (2*(n-1));
	for(int i = 0; i < n;i++){
		ans[i] = ( b[i] - sum)/(n-2);
	}
	for(int i = 0; i < n-1 ;i++){
		cout << ans[i] << " ";
	}
	cout << ans[n-1] << endl;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
