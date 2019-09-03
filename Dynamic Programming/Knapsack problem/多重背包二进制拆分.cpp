/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-28 21:19:58
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
struct Node{
	int v, w;
}a[maxn];
int n , V;
int f[maxn];
int v, w, s;
int main()
{
	cin>>n>>V;
	f[0] = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin>>v>>w>>s;
		for(int j = 1; j <= s;j*=2){
			a[++cnt].v = j * v;
			a[cnt].w = j * w;
			s -= j;
		}
		if(s){
			a[++cnt].v = s*v;
			a[cnt].w = s*w;
		}
	}
	for(int i = 1; i <= cnt ;i++){
		for(int j = V; j >= a[i].v;j--){
			f[j] = max(f[j], f[j-a[i].v]+a[i].w);
		}
	}
	cout << f[V]<<endl;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
