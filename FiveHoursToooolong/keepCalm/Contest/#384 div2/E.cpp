//others
#include<bits/stdc++.h>
using namespace std;
function<void(void)> ____ = [](){ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);};
/*
二分枚举最少出现次数mid 则每个数的出现次数为mid或者mid+1
对于每次二分的mid 判断是否可行
通过状压DP实现
dp[i][msk]表示到第i个位置已经选了至少为mid个的数为msk的状态 其中有多少个选了mid+1个
*/
const int MAXN = 1111;
int n;
vector<int> vec[10];
int f[MAXN][1<<8];
int check(int mid){
    memset(f,255,sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int msk = 0; msk < (1<<8); msk++){
            if(f[i][msk]==-1) continue;
            for(int k = 1; k <= 8; k++){
                if(msk&(1<<(k-1))||vec[k].empty()) continue;
                int nxt = lower_bound(vec[k].begin(),vec[k].end(),i) - vec[k].begin();//找从当前点开始第一次出现k的位置
                nxt+=mid-1;
                if(nxt<vec[k].size()) f[vec[k][nxt]][msk|(1<<(k-1))] = max(f[vec[k][nxt]][msk|(1<<(k-1))],f[i][msk]);
                if(++nxt<vec[k].size()) f[vec[k][nxt]][msk|(1<<(k-1))] = max(f[vec[k][nxt]][msk|(1<<(k-1))],f[i][msk]+1);
            }
        }
    }
    int tot = -1;
    for(int i = 1; i <= n; i++) tot = max(tot,f[i][(1<<8)-1]);
    return tot!=-1 ? (mid<<3)+tot : 0;
}
int gao(){
    int l = 1, r = n/8;
    while(l<=r){
        int mid = (l+r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    return check(r);
}
int main(){
    ____();
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tp; cin >> tp;
        vec[tp].push_back(i);
    }
    cout << max(gao(),(int)(count_if(vec,vec+10,[](vector<int> &vec){ return vec.size()!=0; }))) << endl;
    return 0;
}