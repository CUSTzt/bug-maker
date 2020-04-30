// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
const int mod = 1e9+7;
vector<int > v[N];
int ans1[N], ans2[N];
int n , x, y;
void dfs(int x, int fa){
    ans1[x] = ans2[x] = 1;
    for(int i = 0 ; i < v[x].size(); i++){
        if(v[x][i]!=fa){
            dfs(v[x][i], x);
            ans1[x] = ans1[x] * (ans1[v[x][i]]+ans2[v[x][i]])%mod;
            ans2[x] = ans2[x] * ans1[v[x][i]] % mod;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        v[x].pb(y);v[y].pb(x);
    }
    dfs(1, 0);
    return 0;
}