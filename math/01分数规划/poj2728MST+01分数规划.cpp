 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月09日 星期三 20时23分11秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long 
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-6
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
struct node{
    int x, y , z;
}a[maxn];
double cost[maxn][maxn],G[maxn][maxn], len[maxn][maxn], dis[maxn];
int vis[maxn], n;
double getdis(int i , int j ){
    return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y));
}
double prim(){
    for(int i = 0; i < n;i++)dis[i] = G[0][i];
    memset(vis,0,sizeof(vis));
    dis[0] = 0;
    vis[0] = 1;
    double ans  = 0;
    for(int i = 0;i < n-1;i++){
        double minn = INF;
        int pos;
        for(int j = 0; j < n;j++)
            if(!vis[j] && dis[j] < minn)minn = dis[pos=j];
        vis[pos] = 1;
        ans += dis[pos];
        for(int j = 0; j < n;j++){
            if(!vis[j] && G[pos][j] < dis[j])dis[j] = G[pos][j];
        } 
    }
    return ans;
}
bool isok(double x){
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            G[i][j] = cost[i][j] - x*len[i][j];
        }
    }
    return (prim() >= 0);
}
//题意:求有n个村庄，输入每个村庄的位置和高度，这n个村庄要连在一起，村与村之间的长度为他们之间的欧几里得距离，花费是两村之间的高度差，要求连在一起的花费和与距离和之比的最小值。
//len[][] 欧几里得距离    cost 海拔差距
//思路：明显的最优比率生成树。二分答案λ，每条边重新赋权c[i] - λd[i] ，因为要求比值最小，那么对于所有的生成树，它们的f[λ]必须>=0，所以只需求得基于最小生成树的f'[λ]，当f'[λ] = 0时即找到了正解λ*。
main(){
    while(cin >> n && n){
        for(int i = 0; i < n;i++){
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cost[i][j] = fabs(a[i].z - a[j].z);
                len[i][j] = getdis(i, j);
            }
        }
        double l = 0, r = 200;
        while(r - l > eps){
            double mid = (l+r) / 2;
            if(isok(mid))l = mid;
            else r = mid;
        }
        printf("%.3f\n",r);
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
