#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 1e6+10;
constexpr int INF = 1e8;
int n, g[205][205], dis[205][205], cnt[maxn];
ll a[maxn], A[maxn];
inline void umin(int &x , int y){if(x > y) x = y;}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n;
    int num = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]){
            A[++num] = a[i];
            for(int j = 0; j < 62; j++){
                if((a[i]>>j)&1){
                    cnt[j]++;
                }
            }
        }
    }
    if(!num){
        cout << "-1" << endl;
        return 0;
    }
    n = num;
    for(int i = 0; i < 62; i++){
        if(cnt[i] >= 3){
            cout << 3 << endl;
            return 0;
        }
    }
    auto folyd = [&](){
        int mn = INF;
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n; j++){
                g[i][j] = dis[i][j] = INF;
            }
            g[i][i] = dis[i][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(A[i] & A[j]){
                    g[i][j] = g[j][i] = dis[i][j] = dis[j][i] = 1;
                }
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i < k; i++){
                for(int j = i + 1; j < k; j++){
                    umin(mn, dis[i][j] + g[k][i]+g[j][k]);
//                    cout << "mn === " << mn << endl;
                }
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    umin(dis[i][j] , dis[i][k]+dis[k][j]);
                }
            }
        }
        if(mn == INF){
            cout << "-1" << endl;
        }else {
            cout << mn << endl;
        }
    };
    folyd();
}