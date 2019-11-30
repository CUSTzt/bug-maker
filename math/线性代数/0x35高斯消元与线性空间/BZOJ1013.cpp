 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-17 21:18:24
 # @Description: You build it.You run it
 ***********************************************/

//思维难点：通过两个相邻方程作差，把n+1个n元二次方程变成n个n元一次方程
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
double a[20][20],b[20],c[20][20];
int main()
{
	int n;
	cin >> n ;
	for(int i = 1; i <= n+1;i++)
		for(int j = 1; j <= n;j++)
			cin >> a[i][j];
	for(int i = 1; i <= n;i++)
		for(int j = 1; j <= n;j++){
			c[i][j] = 2*(a[i][j] - a[i+1][j]);
			b[i] += a[i][j] * a[i][j] - a[i+1][j]*a[i+1][j];
		}
	//高斯消元  数据保证有唯一解
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= n;j++){
			if(fabs(c[i][j]) > 1e-8){
				for(int k = 1;k <= n;k++)swap(c[i][k],c[j][k]);
					swap(b[i],b[j]);
			}
		}
		//消去其他方程x[i] 的系数
		for(int j = 1; j <= n;j++){
			if(i == j) continue;
			double rate = c[j][i] / c[i][i];
			for(int k = i; k <= n;k++)c[j][k] -= c[i][k] * rate;
			b[j] -= b[i] *rate;
		}
	}
	for(int i = 1; i <= n;i++){
		printf("%.3f ",b[i]/c[i][i] );
	}
	cout << endl;

}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/