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
#define int long long 
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
const int maxn = 1e6+10;
int n, b;
int u[3850],f[3850][2],ans;
void dp(){
	for(int i = 2; i <= n;i++){
		for(int j =b; j ; j--){
			f[j][0] = max(f[j][0], f[j][1]);
			f[j][1] = max(f[j-1][0], f[j-1][1]+u[i]);
		}
	}
}
main()
{
	cin>>n>>b;
	for(int i = 1; i <= n;i++){
		cin >> u[i];
	}
	memset(f,0xcf,sizeof(f));
	f[0][0] = f[1][1] = 0;
	dp();
	ans = max(ans , max(f[b][0],f[b][1]));
	memset(f,0xcf,sizeof(f));
	f[1][1] = u[1];
	dp();
	ans = max(ans , f[b][1]);
	cout << ans <<endl;
     
}


/*
//author : lyd
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 4000, M = 4000;
int n, m, f[2][M][2], w[N], ans;

int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &w[i]);
	if (m == 0)
		 { printf ("0"); exit (0); }
	memset (f, 0x80, sizeof f);
	f[1 & 1][0][0] = 0;
	f[1 & 1][1][1] = 0;
	for (int i = 2; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
		{
			f[i & 1][j][0] = max (f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
			if (j - 1 >= 0) f[i & 1][j][1] = max (f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + w[i]);
		}
	ans = max (f[n & 1][m][1], f[n & 1][m][0]);
	memset (f, 0x80, sizeof f);
	f[1 & 1][1][1] = w[1];
	for (int i = 2; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
		{
			f[i & 1][j][0] = max (f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
			if (j - 1 >= 0) f[i & 1][j][1] = max (f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + w[i]);
		}
	ans = max (ans, f[n & 1][m][1]);
	printf ("%d", ans);
	return 0;
}



 */