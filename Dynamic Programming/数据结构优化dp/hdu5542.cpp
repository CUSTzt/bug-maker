/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-09-04 15:24:17
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e3+10;
const int mod = 1e9+7;

int pp;
int t ;
int n , m ;
int c[maxn], a[maxn], b[maxn];
int f[maxn][maxn];
void add(int x, int y) {
	while (x <= n + 1) {
		c[x] = (c[x] + y) % mod;
		x += x & -x;
	}
}

int ask(int x) {
	int ans = 0;
	while (x) {
		ans = (ans + c[x]) % mod;
		x -= x & -x;
	}
	return ans;
}
void solve(){
	//memset(f , 0 , sizeof (f));
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	memcpy(b, a, sizeof(b));
	sort(b+1, b+n+1);
	for(int i = 1 ; i <= n;i++)
		a[i] = lower_bound(b+1, b+n+1,a[i]) - b + 1;
	a[0] = f[0][0] = 1;
		for(int i = 1; i <= m;i++){
			memset(c, 0 , sizeof(c));
			add(1 , f[i-1][0]);
			for(int j = 1; j <= n;j++){
				f[i][j] = ask((a[j])-1);
				add((a[j]),f[i-1][j]);
            }
        }
    pp = 0;
	for(int i = 1; i <= n;i++){
		pp = (pp + f[m][i])%mod;
	}

}
 main()
{
	cin >> t ;
	for(int kase = 1; kase <= t;kase++){
		solve();
		printf("Case #%I64d: %I64d\n", kase , pp%mod );
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
