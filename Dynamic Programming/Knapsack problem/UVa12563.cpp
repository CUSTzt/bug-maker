/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-23 21:05:22
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
//歌曲数目 优先，  然后总时长优先
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 180*50+5;
using namespace std;

int n , max_t;
int  t[55];
struct Node
{
	int num;
	int time;
	bool operator<(const Node &rhs)const {
		return num < rhs.num||(num == rhs.num &&time < rhs.time);
	}
}dp[maxn];
int main()
{
	int tt;
	cin>>tt;
	for(int kase = 1;kase <= tt;kase++){
		//printf("Case %d: ", kase);
		cin >> n >> max_t;
		memset(dp,0,sizeof(dp));
		int sum = 0; //所有歌曲的总时间
		for(int i = 1; i <= n; i++){
			cin>>t[i];
			sum+=t[i];
		}
		//max_t是我们要考虑的时间
		max_t = min(sum,max_t-1); //注意max_t==sum 和 max_t==0的情况
		int ans = 0;
		for(int i = 1; i <= n;i++){
			for(int j = max_t; j >= t[i];j--){
				Node tmp;//tmp表示当选择第i首歌时的情况
                tmp.num  = dp[j-t[i]].num+1;
                tmp.time = dp[j-t[i]].time+t[i];
                if(dp[j]<tmp){
                    dp[j]=tmp;
                }
			}
		}
		printf("Case %d: ", kase);
		cout << dp[max_t].num+1<<" "<<dp[max_t].time+678<<endl;
	}
 
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
