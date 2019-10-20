 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月18日 星期五 15时53分11秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
/*
给你N个DNA序列，两个DNA序列最长公共子串在DNA序列都大于给你的占总长度的百分比P，就属于同一个物种，问有多少个不同类物种
*/
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 116;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
double p;
int dp[maxn][maxn], pa[maxn],len[maxn],n;
char DNA[maxn][maxn];
/*void init(int n ){
    for(int i = 0; i <= n;i++){
        pa[i] = i;
    }
}*/
int Find(int x){
    return pa[x] == x ? x : pa[x] = Find(pa[x]);
}
void Union(int x , int y){
    int fa = Find(x), fb = Find(y);
    if(fa != fb)pa[fb] = fa;
}
int LCS(int a, int b){
    int ans = 0;
    memset(dp, 0 , sizeof dp);
    for(int i = 1; i <= len[a];i++){
        for(int j = 1; j <= len[b];j++){
            if(DNA[a][i-1] == DNA[b][j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            if(dp[i][j] > ans )
                ans = dp[i][j];
        }
    }
    return ans;
}
int main(){
    int kase = 0;
    while(~scanf("%d %lf", &n , &p)){
        for(int i = 0; i < n;i++){
            scanf("%s", DNA[i]);
            pa[i] = i;
            len[i] = strlen(DNA[i]);
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < i;j++){
                int pi = Find(i), pj = Find(j);
                if(pi == pj)  continue;
                double x = LCS(i , j )*100.0;
                if(x/len[i] > p && x/len[j]>p)
                    pa[pi] = pj;
            }
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(pa[i] == i)
                ans++;
        }
        printf("Case %d:\n%d\n" ,++kase , ans);
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
