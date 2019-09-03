/*************************************
 * Author : miniLCT
 * More : You build it. You run it
 ************************************/
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#define ll long long
#define INF 0x3f3f3f3f 
#define lowbit(x) (x)&(-x)
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;++i) 
#define MT(x,i) memset(x,i,sizeof(x))
#define close std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000000009;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double E = exp(1);
const double EPS=1e-8;
const int maxn = 1e3+10;
//做法：拆成两倍的链
int n ;
int dp_max[maxn][maxn],dp_min[maxn][maxn];
int a[maxn];
char c[maxn];
int main()
{
	cin>>n;
	for(int i = 1 ; i <= n;i++){
		cin >> c[i] >>a[i];
		a[i+n] = a[i];
		c[i+n] = c[i];
	}
	for(int i = 1; i <= 2*n;i++){
		for(int j = 1; j <= 2*n;j++){
			dp_max[i][j] = -0x3f3f3f3f;
			dp_min[i][j] = 0x3f3f3f3f;
			if(i == j) dp_min[i][j] = dp_max[i][j] = a[i];
		}
	}
	for(int len = 2; len <= 2*n; len++){
		for(int l = 1; l <= 2*n - len + 1; l++){
			int r = l + len - 1;
			for(int k = l; k < r;k++){
				if(c[k+1]=='x'){
					dp_max[l][r] = max(dp_max[l][r], max(dp_min[l][k]*dp_min[k+1][r], dp_max[l][k]*dp_max[k+1][r]));
					dp_min[l][r] = min(dp_min[l][r], min(dp_min[l][k]*dp_max[k+1][r], min(dp_max[l][k]*dp_min[k+1][r],dp_min[l][k]*dp_min[k+1][r])));
				}
				else {
					dp_max[l][r] = max(dp_max[l][r], dp_max[l][k]+dp_max[k+1][r]);
					dp_min[l][r] = min(dp_min[l][r], dp_min[l][k]+dp_min[k+1][r]);
				}
			}
		}
	}
	int ans = -0x3f3f3f3f;
	for(int i = 1; i <= n;i++){
		ans = max(ans, dp_max[i][i+n-1]);
	}
	cout << ans <<endl;
	for(int i = 1; i <= n ;i++){
		for(int j = 1; j <= n;j++){
			if(dp_max [i][i+n-1] == ans){
				cout << i <<' ';
				break;
			}
		}
	}
}