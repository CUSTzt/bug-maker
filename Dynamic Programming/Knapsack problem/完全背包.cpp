/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-28 20:55:28
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
int v[maxn],w[maxn];
int f[maxn];
int main()
{
	int N , V;
	cin>>N>>V;
	for(int i = 1; i <= N;i++){
		cin>>v[i]>>w[i];
	}
	memset(f,0xcf,sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= N;i++){
		for(int j = v[i]; j <= V;j++){
			f[j] = max(f[j], f[j - v[i]]+w[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= V ; ++i){
		ans = max(ans, f[i]);
	}
	cout <<ans <<endl;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
