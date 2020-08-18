// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e2+100;
int no[N][N], n , m , e, v[N], match[N];
bool dfs(int x){
    for(int y = 1; y <= m; y++){
        if(v[y] || no[x][y]) continue;
        v[y] = 1;
        if(match[y] == 0 || dfs(match[y])){
            return match[y] = x ,1;
        }
    }return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> e;
    int x, y;
    while(e--){
        cin >> x >> y;
        no[x][y] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(v , 0 , sizeof v);
        if(dfs(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}