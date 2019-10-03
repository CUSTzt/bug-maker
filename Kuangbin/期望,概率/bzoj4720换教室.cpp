 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年09月26日 星期四 19时14分30秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
#include<bits/stdc++.h>
//按照题目要求别多输出小数点
//ans  注意从 0 开始
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , m , v, e;
int aa, bb , cc;
int  c[maxn], d[maxn],dis[500][500];
double k[maxn], f[2005][2005][2];
void floyd(){
    for(int k = 1; k <= v;k++){
        for(int i = 1; i <= v;i++){
            for(int j = 1; j < i;j++){
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[j][i] = dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
}

int main(){
    cin >> n >> m >> v >> e;
    for(int i = 1; i <= n;i++)scanf("%d", &c[i]);
    for(int i = 1; i <= n;i++)scanf("%d", &d[i]);
    for(int i = 1; i <= n;i++)scanf("%lf", &k[i]);
    for(int i = 1; i <= v;i++){
        for(int j = 1; j <= v;j++){
            dis[i][j] = dis[j][i] = INF;
            if(i == j )dis[i][j] = 0;
        }
    }
    for(int i = 1; i <= e;i++){
        scanf("%d%d%d",&aa, &bb ,&cc);
        dis[aa][bb] = min(min(dis[aa][bb], cc),dis[bb][aa]);
        dis[bb][aa] = dis[aa][bb];
    }
    floyd();
    for(int i = 1; i <= n;i++){
        for(int j = 0; j <= m;j++){
            f[i][j][0] = f[i][j][1] = 1.0*INF;
        }
    }
    f[1][0][0] = f[1][1][1] = 0;
    // 1有 0 没有  
    // k 有几率成功
    for(int i = 2; i <= n;i++){
        for(int j = 0; j <= m;j++){
            f[i][j][0] = min(f[i-1][j][1]+k[i-1]*dis[d[i-1]][c[i]]+(1-k[i-1])*dis[c[i-1]][c[i]],f[i-1][j][0]+dis[c[i-1]][c[i]]);
            if(j != 0)f[i][j][1] = min(f[i-1][j-1][1]+k[i-1]*k[i]*dis[d[i-1]][d[i]]+k[i-1]*(1-k[i])*dis[d[i-1]][c[i]]+(1-k[i-1])*k[i]*dis[c[i-1]][d[i]]+(1-k[i-1])*(1-k[i])*dis[c[i-1]][c[i]] ,f[i-1][j-1][0]+k[i]*dis[c[i-1]][d[i]]+(1-k[i])*dis[c[i-1]][c[i]]);
            //cout << f[i][j][0]  << "     " << f[i][j][1] <<endl;
        }
    }
    double ans = INF;
    for(int i = 0; i <= m;i++){
        for(int j = 0; j < 2;j++){
            ans = min(ans , f[n][i][j]);
        }
    }
    printf("%.2f\n", ans);
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/

