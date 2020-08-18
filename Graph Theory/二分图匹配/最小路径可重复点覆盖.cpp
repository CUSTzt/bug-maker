// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

const int N = 205+100;

// 结论：
// 不相交:有向无环图G的最小路径点覆盖包含的路径条数等于n减去拆点二分图G2的最大匹配数
// 把每个点拆成x和x+n两个点，1~n二分图左部点， n+1~2n二分图右部点
// 点可相交，在某个点相交  x->p->y    u->p->v 可以在x->y之间连边 这样“有路径相交的点覆盖” 一定可以转化成“没有路径相交的点覆盖”
// 在求有向无环图G的最小路径可重复点覆盖时候，等价于先对有向图传递闭包，得到有向无环图G’,在G’上求一般的（路径不可相交的）最小路径点覆盖
int vis[N], succ[N], match[N], cl[N][N], n , m , hide[N]/*藏身点集合*/;
int dfs(int x){
    for(int i = 1; i <= n; i++){
        if(cl[x][i] && !vis[i]){
            vis[i] = 1;
            if(!match[i] || dfs(match[i])){
                return match[i] = x, 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x , y ; cin >> x >> y;
        cl[x][y] = 1;
    }
    for(int i = 1; i <= n+10; i++) cl[i][i] = 1;
    // Floyd 传递闭包
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cl[i][j] |= (cl[i][k] && cl[k][j]);
    for(int i = 1; i <= n+10; i++) cl[i][i] = 0;
    // 在拆点二分图上求最大匹配
    int ans = n;
    for(int i = 1; i <= n; i++) {
        memset(vis , 0 , sizeof vis);
        ans -= dfs(i);
    }
    cout << ans << endl;

    // 构造方案  先把所有路径终点（左部非匹配点）作为藏身点
    for(int i = 1; i <= n; i++) succ[match[i]] = 1;
    for(int i = 1, k = 0; i <= n; i++) {
        if(!succ[i]) hide[++k] = i;
    } 
    memset(vis , 0 , sizeof vis);
    int modify = 1;
    while(modify){
        modify = 0;
        // 求出next（hide）
        for(int i = 1; i <= ans; i++){
            for(int j = 1; j <= n; j++){
                if(cl[hide[i]][j]) vis[j] = 1;
            }
        }
        for(int i = 1; i <= ans; i++){
            if(vis[hide[i]]){
                modify = 1;
                // 不断向上移动
                while(vis[hide[i]]) hide[i] = match[hide[i]];
            }
        }
    }
    for(int i = 1; i <= ans; i++) cout << hide[i] << " ";
    cout << endl;
    return 0;
}