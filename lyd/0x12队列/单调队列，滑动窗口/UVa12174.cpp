 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-10-04 16:50:15
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e5+100;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int t, s, n,p[maxn],flag[maxn],c[maxn],tmp;
bool judge(int x){
	for(int i = x;i < n;i+=s)
		if(!flag[i])return false;
	return true;
}
int main()
{
	cin >> t;
	while(t--){
		cin >> s >> n;
		tmp = 0;
		memset(flag,0,sizeof(flag));
		memset(c,0,sizeof(c));
		for(int i = 0; i < n; i++){
			scanf("%d",&p[i]);
			if(i < s){
				if(c[p[i]])tmp++;
				c[p[i]]++;
			}
		}
		for(int i = 0; i < n;i++){
			if(tmp == 0)flag[i] = 1;
			if(c[p[i]] == 2)tmp--;
			c[p[i]] --;
			int k = i+s;
			if(k >= n)continue;
			if(c[p[k]])tmp++;
			c[p[k]]++;
		}
		memset(c,0,sizeof(c));
		int ans = 0;
		for(int i = 0; i < s;i++){
			if(judge(i))ans++;
			if(i >= n)continue;
			if(c[p[i]])break;
			c[p[i]]++;
		}
		cout << ans << endl;
	}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/