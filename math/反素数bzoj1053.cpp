/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-16 15:43:10
 * @Description: You build it, You run it.  
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e6+10;
#define eps 1e-8
using namespace std;
#define INF 2e9
ll zs[11] = {0,2,3,5,7,11,13,17,19,23,29},c[11],ans = INF,cnt_ans = 1,n;
void dfs(ll now , ll num , ll cnt){
	if(now == 11){
		if(cnt > cnt_ans || (cnt == cnt_ans && ans > num)){
			cnt_ans = cnt;
			ans = num;
		}
		return ;
	}
	ll num_cnt = num;
	for(int i = 0; i <= c[now - 1] ; i++){
		if(num_cnt > n)return ;
		c[now] = i;
		dfs(now + 1 , num_cnt,cnt * (i+1));
		num_cnt *=zs[now];
	}
}
int main()
{
	//int n;
	cin>>n;
	c[0] = INF;
	dfs (1,1,1);
	cout << ans << endl; 
	return 0;
 
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
