/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-04 23:06:54
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 2e5+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int sp[maxn],sz[maxn];
int main()
{
	close;
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		char c;
		map<pair<int , int > ,int >mp;
		int sp = 0, sz = 0,fl = 0;
		int ansa = -INF, ansb = INF;
		mp[{0,0}] = 1;
		for(int i = 1;i <= n;i++){
			cin >> c;
			if(c=='R')sp++;
			if(c=='L')sp--;
			if(c=='U')sz++;
			if(c=='D')sz--;
			if(mp.count({sp,sz}) && (i-mp[{sp,sz}] < ansb-ansa)){ansa=mp[{sp,sz}],ansb=i,fl=1;}
			mp[{sp,sz}]=i+1;
			
		}
		if(ansa != -INF){
			cout << ansa << ' ' << ansb <<endl;
		}else cout << -1 <<endl;
	} 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/