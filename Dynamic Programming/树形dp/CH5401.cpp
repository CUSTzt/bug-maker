/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-30 09:39:47
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e5+10;
using namespace std;
std::vector<int > son[maxn];
int f[maxn][2],v[maxn],h[maxn],n;
void dp(int x){
	f[x][0] = 0;
	f[x][1] = h[x];
	for(int i = 0 ; i < son[x].size(); i++){
		int y =  son[x][i];
		dp(y);
		f[x][0] += max(f[y][0], f[y][1]);
		f[x][1] += f[y][0];
	}
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n;i++){
		cin>>h[i];
	}
	for(int i = 1; i <= n;i++){
		int x, y;
		cin>>x>>y;
		v[x] = 1;//x不是根
		son[y].push_back(x);//x是y的儿子
	}
	int root;
	for(int i = 1; i <= n;i++){
		if(!v[i]) {
			root = i;
			break;
		}
	}
	dp(root);
	cout << max(f[root][0],f[root][1])<<endl;
 
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
