 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-11 17:50:10
 # @Description: You build it.You run it
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e4;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;

ll d[25][maxn];
void pre_work(){
	d[0][0] = 1; 
	for(ll i = 1; i <= 21; i++){
		for(ll j = 0; j <= maxn ;j++){
			d[i][j] = d[i-1][j];
			if(j - i*i*i >=0)d[i][j] += d[i][j-i*i*i];
		}
	}
} 
int main()
{
	pre_work();
	ll n ;
	while(cin >> n){
		cout << d[21][n] << endl;
	}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/