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
const int maxn = 1e6+10;
int a[maxn],c[maxn];
int n,V;
int used[maxn];
int dp[maxn];
int book[maxn];

int main()
{
	close;
	while(cin>>n>>V&&(n+V)){
		memset(book , 0 , sizeof (book));
		for(int i = 1; i <= n;i++)
		    cin>>a[i];
		for(int i = 1; i <= n;i++)
			cin>>c[i];
		book[0] = 1;
		for(int i = 1; i <= n;i++){
			for(int k = 0; k <= V;k++){
				dp[k] = 0;
			}
			for(int j =a[i]; j <= V;j++){
				if(!book[j]&&book[j-a[i]]&&(dp[j-a[i]]<c[i])){
					dp[j] = dp[j-a[i]]+1;
					book[j] = 1;
					//cout <<"dasd"<<endl;
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= V;i++){
			if(book[i])ans++;
		}
		cout << ans <<endl;
	}     
}
