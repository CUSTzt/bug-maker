/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 00:18:23
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
int a[maxn];
int main()
{
	int n;string s;
	cin >> n >>s;
	char s1,s2;
	s1 = s[0];
	int fl = 0,kk = 0;
	for(int i = 1; i < n;i++){
		if(!fl){
			if(s1 > s[i]){
				s2 = s[i];fl=1;a[i] = 1;
			}
		}
		if(s1 <= s[i]){s1 = s[i];continue;}
		if(s2 <= s[i]){s2 = s[i];a[i] = 1;continue;}
		if(s1 > s[i] && s2 > s[i] && fl){
			kk = 1;
			//cout << "s1 == "<< s1 << "  s2 == " << s2<<endl;
			//cout << "i === " << i <<"   si == " <<s[i] <<endl;
		}
	}if(kk == 1){
		cout << "NO\n";
	}else{
		cout <<"YES\n";
		for(int i = 0; i < n;i++)cout << a[i];
	}
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/