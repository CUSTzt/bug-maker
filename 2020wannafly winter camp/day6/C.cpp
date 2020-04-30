/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-17 13:25:09
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
int t, n , a, b , c ,d;
string s;
int main()
{
	cin >> t;
	while(t--){
		cin >> n >> a >> b >> c >> d ;
		cin >> s;
		int cnt = 0, maxx  = 0 , minn = 0;
		int aa = a, bb = b , cc = c, dd = d ,cff = d+c, cf = d+c;
		for(int i = 0; i < n; i++){ //min
			if(s[i] == '1'){
				if(dd){
					dd--;cc++;
					continue;
				}
				if(cf == 0){
					if(bb){
						bb--;aa++;
						continue;
					}else {
						aa--;minn++;
						continue;
					}
				}
				if(cf){
					cc--;cf--;minn++;
				}
			}else {
				if(cc == 0 && dd){
					dd--,cc++;
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				if(cff){
					if(d){
						d--,c++;continue;
					}
				}else {
					if(b){
						b--,a++;
					}
				}
			}
			else {
				if(cff){
					if(c){
						c--,maxx++,cff--;
						continue;
					}else{
						d--,c++;
					}
				}else {
					if(a){
						maxx++;a--;
						continue;
					}else{
						b--,a++;
					}
				}
			}
		}
		cout << maxx << " " << minn << endl;
	}
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
