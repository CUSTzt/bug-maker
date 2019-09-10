 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-09 09:38:51
 # @Description: You build it.You run it
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define lowbit(x) x&(-x)
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn], b[maxn], c[maxn], n , m;
int ask(int x){
	int ans = a[x]; 
	for( ; x; x -= lowbit(x))ans += c[x];
		return ans;
}
void add(int x,int y){
	for(; x <= n; x += lowbit(x))c[x] += y ;
}
int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m;i++){
		char aa ;
		cin >> aa;
		if(aa == 'C'){
			int x;
			int l , r , d;
			cin >> l >> r >> d;
			add(l , d);
			add(r+1 , -d);
		}
		if(aa == 'Q'){
			int x;
			cin >> x;
			cout << ask(x) << endl;
		}
	}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/