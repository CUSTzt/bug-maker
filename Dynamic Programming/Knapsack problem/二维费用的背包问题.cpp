#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int N , M , V, dp[maxn][maxn];
int v , m , w;
int main()
{
	cin >> N >> V >> M;
	for(int i = 0; i < N ;i++){
		cin >> v >> m >> w;
		for(int i = V; i >= v; --i){
			for(int j = M; j >= m; --j){
				dp[i][j] = max(dp[i][j] , dp[i-v][j-m]+w);
			}
		}
	}
	cout << dp[V][M]<<endl;
}