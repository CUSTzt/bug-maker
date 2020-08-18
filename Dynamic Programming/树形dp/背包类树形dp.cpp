//题目：CH5402    https://www.acwing.com/problem/content/288/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x) & (-x)
#define eps 1e-8
const int maxn = 3e3 + 10;
using namespace std;
int f[maxn][maxn], n, m, score[maxn];
std::vector<int> son[maxn];
void dp(int x) {
    f[x][0] = 0;
    for (int i = 0; i < son[x].size(); i++) {  //循环子节点(物品)
        int y = son[x][i];
        dp(y);
        //倒序循环当前选课总门数（当前背包体积）
        for (int t = m; t >= 0; t--) {
            //循环更深子树上的选课门数（组内物品）
            //此处使用倒序是为了正确处理组内体积为0 的物品
            for (int j = t; j >= 0; j--) {
                if (t - j >= 0) {
                    f[x][t] = max(f[x][t], f[x][t - j] + f[y][j]);
                }
            }
        }
    }
    if (x != 0)  // x不为0时， 选修x本身要占用一门课。获得相应的学分
        for (int t = m; t > 0; t--) {
            f[x][t] = f[x][t - 1] + score[x];
        }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        score[i] = yy;
        son[xx].push_back(i);
    }
    dp(0);
    cout << f[0][m] << endl;
}
