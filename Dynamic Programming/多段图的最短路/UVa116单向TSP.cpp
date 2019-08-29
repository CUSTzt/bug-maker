/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-23 19:05:02
 * @Description: You build it, You run it.
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
// 法一  : 紫书 上  的写法
// 要求字典序最小, 这就需要在计算d(i , j )的时候同时记录"下一列行号"的最小值(当然是在满足最优解的情况之下)
// 有一个细节就是上下是连着的 , 所以处理的时候不要出错了

#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
#define inf 0x3f3f3f3f
const int maxn = 1e6+10;
using namespace std;
int a[55][105],dp[55][105];
int nxt[55][105];
int n , m;
int main()
{
	while(cin >> m >> n){
        //memset(nxt, 0 , sizeof(nxt));
		for(int i = 0; i < m ;i++){
			for(int j = 0; j < n;j++){
				cin>>a[i][j];
			}
		}
		int ans = inf , first = 0;
		for(int j = n-1 ; j >= 0;j--){  //逆推
			for(int i = 0; i < m; i++){
				if(j == n-1 )dp[i][j] = a[i][j];  //边界
				else{
					int rows[3] = {i, i-1, i+1};  //这是一般情况下的  右,右上,右下
					if(i == 0)rows[1] = m-1; //第0 行上面是m-1行
					if(i == m-1)rows[2] = 0; //第m-1行下面是第零行
					sort(rows,rows+3);  // 重新排序, 使得字典序最小
					dp[i][j] = inf;
					for(int k =0; k < 3;k++){
						int v = dp[rows[k]][j+1] + a[i][j];
						if(v < dp[i][j]){dp[i][j] =v; nxt[i][j] = rows[k];}
					}
				}
				if(j == 0 && dp[i][j] < ans){ans = dp[i][j];first =i;}
			}
		}
		printf("%d", first+1);  //输出第1列
		for(int i = nxt[first][0], j =1; j < n;i=nxt[i][j],j++)
			printf(" %d", i+1);
		printf("\n%d\n", ans);
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
