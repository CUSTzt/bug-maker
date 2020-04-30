// Wqr_
// Time : 20/01/23
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define int long long
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
int f[31], ans, p, q;
void init(){
    f[1] = 1;
    for(int i = 2; i <= 31; i++){
        f[i] = (1 << (i - 1)) + f[i - 1];
    }
   // dbg(f[31]);
}
void dfs(int cur, int now, int stop){
    if(cur == q) {
        ans = min(ans, now + stop - 1);
        return ;
    }

    //直接下降, 然后上升
    int tmp = upper_bound(f + 1, f + 30, cur - q) - f;
    int nx_dn = max(0LL, cur - f[tmp]);
    ans = min(ans, now + tmp + max(q - nx_dn, stop));

    //下降到前一个之后暂停, 然后dfs处理子问题
    dfs(cur - f[tmp - 1], now + (tmp - 1), stop + 1);
}
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int _;
    cin >> _;
    init();
    while(_--){
        ans = inf;
        cin >> p >> q;
        if(q >= p) {
            cout << q - p << endl;
            continue;
        }
        dfs(p, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
