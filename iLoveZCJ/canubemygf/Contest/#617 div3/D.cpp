/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-04 23:33:03
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
int n , a , b , k, h[maxn];
int main()
{
	close;
	cin >> n >> a >> b >> k;
	int tot = a+b;
	map<int , int >mp;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		h[i] = x % tot;
		if(h[i]==0){
			h[i] = b;
			if(h[i] <= a){
				if(k){ans++;k--;continue;}
			}
			if(h[i] % a == 0){
				mp[h[i] / a]++;
			}else mp[h[i]/a+1]++;
		}else {
			if(h[i] <= a){ans++;continue;}
			if(h[i] % a == 0){
				mp[h[i] / a-1]++;
			}else mp[h[i] / a]++;
		}
	}
	for(auto it : mp){
		int fi = it.first;
		//if(fi == 0)continue;
		int sc = it.second;
		//cout << "fi === " << fi << "    sc === " <<sc << endl; 
		if(k >= sc*fi){ans+=sc;k-=sc*fi;}
		else {
			ans+=k/fi;break;
		}
	}
	cout << ans << endl;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/