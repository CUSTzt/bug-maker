/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-17 21:49:06
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 5e5+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int x[maxn ], y[maxn];
int main()
{
	close;
	int t;
	cin >> t;
	while(t--){
		int cnt = 0;
		int n , m ;
		cin>> n >> m;
		set<int >S[maxn], now[maxn];
		for(int i = 0; i < m;i++){
			int aa, bb ;
			cin >> aa >> bb;
			S[aa].insert(bb);if(aa!=bb)S[bb].insert(aa);
		}
		for(int i = 1; i <  n;i++){
			for(int j = i+1; j <= n;j++){
				if(!S[i].empty() && !S[j].empty() && S[i].size() == S[j].size()){
					int fl1 = 0, fl2 = 0;
					if(S[i].count(i)){
						S[i].erase(i);fl1 = 1;
					}if(S[j].count(j)){
						S[j].erase(j);fl2 = 1;
					}
					if(S[i] == S[j] && (fl1 ^ fl2)){
						cnt++;
					}
					if(fl1){
						S[i].insert(i);
					}
					if(fl2){
						S[j].insert(j);
					}
				}
			}
		}
		cout << cnt << endl;
	}
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
