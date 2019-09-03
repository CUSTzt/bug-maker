/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-28 21:11:20
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
int w[maxn], v[maxn],s[maxn];
int f[maxn];
int main(){
	int N , V;
	cin>>N>>V;
	for(int i = 1; i <= N;i++){
		cin>>v[i]>>w[i]>>s[i];
	}
	for(int i = 0; i <= N;i++){
		for(int j = 1; j <= s[i];j++){
			for(int k = V; k >=v[i];k--){
				f[k] = max(f[k],f[k-v[i]]+w[i]);
			}
		}
	}
	//int ans = 0;
	cout<<*max_element(f,f+V+1)<<endl;

}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
