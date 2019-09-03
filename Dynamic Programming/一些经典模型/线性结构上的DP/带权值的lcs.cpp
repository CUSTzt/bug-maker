 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-25 01:35:12
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
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
int matrix[5][5]={
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,0
};
int get (char a){
	if(a == '-')return 4;
	if(a == 'T')return 3;
	if(a == 'G')return 2;
	if(a == 'C')return 1;
	if(a == 'A')return 0;
}
char a[110],b[110];
int dp[110][110];
int main()
{
	close;
	int t;
	cin >> t;
	while(t--){
		//memset(dp,0,sizeof(dp));
		int n,m;
		cin >> n;
		/*for(int i = 1; i <= n; i++)
			cin >> a[i];
		cin >> m;
		for(int i = 1; i <= m; i++)
			cin >> b[i];*/
		cin >> a;
		cin >> m;
		cin >> b;
		//cout<<"   "<<n<<"   "<<a<<endl;
		//cout<<"   "<<m<<"   "<<b<<endl;
		//cout<<get('-')<<"  "<<get('A')<<endl;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1; i <= n;i++){
            dp[i][0] = dp[i-1][0] + matrix[get(a[i-1])][get('-')];
        }
        for(int i = 1; i <= m; i++){
            dp[0][i] = dp[0][i-1]+matrix[get('-')][get(b[i-1])];
        }
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				/*if(a[i] == b[j]){
					dp[i+1][j+1] = dp[i][j] + matrix [get(a[i])][get(b[i])];
				}
				else {
					dp[i+1][j+1] = max (dp[i][j+1] + matrix[get('-')][get(b[j])], dp[i+1][j] + matrix[get(a[i])][get('-')]);
				}*/
				int t1 = (dp[i-1][j-1] + matrix [get(a[i-1])][get(b[j-1])]);
				int t2 = (dp[i-1][j] + matrix[get(a[i-1])][get('-')]);
				int t3 = (dp[i][j-1] + matrix[get('-')][get(b[j-1])]);
 				//dp[i][j] = max((dp[i-1][j-1] + matrix [get(a[i-1])][get(b[i-1])]), max ((dp[i-1][j] + matrix[get(a[i-1])][get('-')]), (dp[i][j-1] + matrix[get('-')][get(b[j-1])])));
 				dp[i][j] = max(t1, max(t2,t3));
			}
		}
		cout<<dp[n][m]<<endl;
	}
}