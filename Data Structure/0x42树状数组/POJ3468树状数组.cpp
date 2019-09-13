 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-10 21:02:05
 # @Description: You build it.You run it
 ***********************************************/
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
#define lowbit(x) x&(-x)
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e5+50;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn], n , m;
ll c[2][maxn], sum[maxn];
ll ask(int k , int x){
	ll ans = 0;
	for(; x ;x-=lowbit(x))ans += c[k][x];
	return ans;
}
void add(int k , int x, int y){
	for(; x<= n;x+=lowbit(x))c[k][x] +=y;
}
int main()
{
	close;
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	while(m--){
		char aa;
		int l, r, d;
		cin >> aa >> l >>r;
		if(aa == 'C'){
			cin >> d;
			add(0, l , d);
			add(0, r+1,-d);
			add(1, l , l*d);
			add(1, r+1, -(r+1)*d);
		}
		else {
			ll ans = sum[r]+(r+1)*ask(0,r)-ask(1,r);
			ans -= sum[l-1]+l*ask(0 ,l-1)-ask(1, l-1);
			cout << ans<<endl;
		}
	}


}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/