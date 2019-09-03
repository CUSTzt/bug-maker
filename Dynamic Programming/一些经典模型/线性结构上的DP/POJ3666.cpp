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
#define abbs(a) ((a)>0?(a):-(a))
#define lowbit(x) (x)&(-x)
#define int long long
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;++i) 
#define MT(x,i) memset(x,i,sizeof(x))
#define close std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000000009;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double E = exp(1);
const double EPS=1e-8;
const int maxn = 2010;
int a[maxn];
int b[maxn];
int dp[maxn][maxn];
main()
{
	int n ;
	cin>> n;
	for(int i = 1 ; i <= n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b+1 , b+1+n );
	for(int i = 1; i <= n; i++){
		int res = dp[i-1][1];
		for(int j = 1; j <= n;j++){
			res = min(res , dp[i-1][j]);
			dp[i][j] = abbs(a[i]-b[j])+res;
			//cout << "skjdh==="<<abbs(a[i]-b[j])<<endl;
		}
	}
	int ans = dp[n][1];
	for(int i = 1; i <= n ; i++){
		ans = min(ans , dp[n][i]);
		//cout <<'a'<<"    "<<ans<<endl;
	}
    cout << ans <<endl;
}