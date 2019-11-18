 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-10-31 14:20:10
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
//01分数规划问题
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , k , a[maxn], b[maxn];
double y[maxn];
bool check(double v){
	for(int i = 0; i < n;i++)
		y[i] = a[i] - v*b[i];
	sort(y , y+n);
	double sum = 0;
	for(int i = k ; i < n;i++)
		sum += y[i];
	if(sum >= 0)return true;
	return false;
}
double solve(double l, double r){
	while(r - l > 1e-4){
		double mid = (r-l)/2.0+l;
		if(check(mid))
			l = mid;
		else r = mid;
	}
	return l;
}
int main()
{
	close;
	while(cin >> n >> k && (n+k)){
		for(int i = 0; i < n;i++)
			cin >> a[i];
		for(int i = 0; i < n;i++)
			cin >> b[i];
		cout << (int)(solve(0 , 1)*100 + 0.5) << endl;
	}

}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/