/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-17 13:52:04
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
int t , n , a, b , c , d , aa , bb ,cc, dd, cfmin , cfmax;
string s;
int main()
{
	cin >> t;
	while(t--){
		cin >> n >> a >> b >> c >> d;
		aa = a , bb = b ,cc = c ,dd = d,cfmax = c+d, cfmin = c+d;
		cin >>s;
		int mx = 0 , mn = 0;
		for(int i = 0; i < n; i++){ //mn
			if(!aa && !bb && !cc && !dd)break;
			if(s[i] == '0'){
				if(cfmin && !cc){
					dd--,cc++;
					continue;
				}
				if(!cfmin && bb && aa == 0){
					bb--, aa++;
					continue;
				}
			}else {
				if(cfmin){
					if(dd){
						dd--,cc++;continue;
					}else {
						cc--,cfmin--,mn++;continue;
					}
				}
				else{
					if(bb){
						bb--,aa++;continue;
					}else if(aa>0){
						aa--,mn++;continue;
					}
				}
			}
		}
		for(int i = 0; i < n; i++){ //mx
			if(!a && !b && !c && !d)break;
			if(s[i] == '1'){
				if(cfmax){
					if(c){
						c--,mx++,cfmax--;continue;
					}
					else {
						d--,c++;continue;
					}
				}else {
					if(a){
						a--,mx++;continue;
					}else if(b>0){
						a++,b--;continue;
					}
				}
			}else {
				if(d && cfmax){
					d--,c++;continue;
				}
				if(!cfmax && b){
					b--,a++;continue;
				}
			}
		}		
		cout << mx << ' ' << mn << endl;
	}
}
/***************************************************************************
 *stuff you should l
 ook for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
