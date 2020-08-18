#include<bits/stdc++.h>
using namespace std;
constexpr int N = 550;
int visit[N];
int mark[N];
int match[N][N];
int n, m, k, p ;
int dfs(int x) {
    int i;
    for (i = 1; i <= n; i++)  //对左边的节点x与右边的节点进行逐一检查
    {
        if (!visit[i] && match[x][i]) {
            visit[i] = 1;  //标记检查过的点
            if (!mark[i] || dfs(mark[i]))  //如果右边的点没有被匹配或者匹配了但是存在交错路的
            {
                mark[i] = x;  //修改匹配关系
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int i, j, k;
    int tp;
    cin >> tp;
    while (tp--) {
        cin >> p >> n;
        memset(mark, 0, sizeof(mark));
        memset(match, 0, sizeof(match));
        for (i = 1; i <= p; i++) {
            cin >> k;
            for(int j = 1; j <= k; j++){
                int tp ; cin >> tp;
                match[i][tp] = 1;
            }
        }
        int max = 0;
        for (j = 1; j <= p; j++)  //对做部分顶点逐个进行遍历
        {
            memset(visit, 0, sizeof(visit));
            if (dfs(j)) max++;
        }
        puts((max == p) ? "YES":"NO");
    }
    return 0;
}