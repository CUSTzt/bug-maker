/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-21 16:36:34
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
int m, a[maxn];
int main()
{
	close;
	map<int , int >mp;
	cin >> m;
	for(int i = 0; i < m; i ++){
		int x;
		cin >> x;
		a[i] = x;
		if(mp[x] <= 1)mp[x]++;
	}
	int mx = *max_element(a, a+m);
	std::vector<int> ans;
	for(int i = 1; i <= mx; i++){
		if(mp[i] >= 1){
			mp[i]--;
			ans.push_back(i);
		}
	}
	for(int i = mx - 1; i > 0; i--){
		if(mp[i] ){
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for(auto x : ans)cout << x << " ";
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
