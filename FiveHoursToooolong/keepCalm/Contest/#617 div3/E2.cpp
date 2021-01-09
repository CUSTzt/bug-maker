/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 00:30:39
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
int ch[30];
int main()
{
	int n,cl=1;string s;
	cin >> n >>s;
	ch[1] = s[0] - 'a';a[0] = 1;
	//printf("ch[1] === %d\n",ch[1] );
	for(int j = 1;j < n;j++){
		int fl = 0;
		for(int i = 1; i <= cl;i++){
			if(ch[i] <= s[j] - 'a'){
				//printf("ch[%d]==%d   %d\n",i,ch[i],s[j]-'0' );
				ch[i] = s[j]-'a';
				a[j] = i;
				fl = 1;
				break;
			}
		}
		if(!fl){
			ch[++cl] = s[j]-'a';
			a[j] = cl;
		}
	}
	cout << cl << endl;
	for(int i = 0; i < n;i++){
		cout << a[i] << ' ';
	}
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/