// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
struct node
{
    int w , h , id;
    friend int operator < (const node &a , const node &b){
        if(a.w == b.w) return a.h < b.h;
        else return a.w < b.w;
    }
    /* data */
}a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n , h , w;
    cin >> n >> w >> h;
    for(int i = 1; i <= n; i++){
        cin >> a[i].w >> a[i].h;
        a[i].id = i;
    }
    sort(a+1, a+1+n);
    vector<int> dp(n+10), pre(n+10);
    for(int i = 1; i <= n; i++){
        if(a[i].h <= h || a[i].w <= w) continue;
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[i].w > a[j].w and a[i].h > a[j].h) {
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
        }
    }
    int mx = 0, pos = 0;
    for(int i = 1; i <= n; i++){
        if(mx < dp[i]) {
            mx = dp[i];
            pos = i;
        }
    }
    function<void (int )> dfs = [&](int x){
        if(!x) return ;
        dfs(pre[x]);
        cout << a[x].id << ' ';
    };
    cout << mx << endl;
    dfs(pos);
    return 0;

}