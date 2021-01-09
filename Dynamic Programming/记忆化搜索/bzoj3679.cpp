#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll l , r, dp[20][100005],a[20], len, n, cnt;
map<ll , int> mp;
int main(){
    cin >> n;
    cin >> l >> r;
    function<ll(ll , ll , ll ,ll)> dfs = [&](ll pos , ll chengji , ll pre , ll limit){
        if(chengji > n) return 0ll;
        if(!mp[chengji]) mp[chengji] = ++cnt;
        if(pos == 0){
            return (chengji > 0 && chengji <= n) * 1ll;
        }
        if(pre && !limit && dp[pos][mp[chengji]] != -1){
            return dp[pos][mp[chengji]];
        }
        int res = limit ? a[pos] : 9;
        ll ret = 0;
        for(int i = 0; i <= res; i++){
            if(!i){
                if(pre) ret += dfs(pos-1, 0 , 1, limit && i == a[pos]);
                else ret += dfs(pos-1, 0, false , limit && i == a[pos]);
            }else {
                if(pre) ret += dfs(pos-1, chengji*i , 1 , limit && i == a[pos]);
                else ret += dfs(pos-1, i ,  true , limit && i == a[pos]);
            }
        }
        if(!limit && pre == 1)
        dp[pos][mp[chengji]] = ret;
        return ret;
    };
    auto solve = [&](ll x){
        len = 0, cnt = 0;
        mp.clear();
        memset(dp , 0xff , sizeof dp);
        while(x) a[++len] = x % 10, x /= 10;
        return dfs(len , 0 , 0 , 1);
    };
    cout << solve(r-1) - solve(l-1) << endl;
}