//https://ac.nowcoder.com/acm/contest/4853/C
// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e3+100;
constexpr int mod = 1e9+7;
int n , k;
char s[N];
int dp[N][N], nxt[N][26];
void add(int &x, int y){x+=y;if(x > mod)x-=mod;}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> (s+1); 
    for(int i = 0; i < 26; i++) {
        nxt[n][i] = n+1;
    }
    for(int c = 0; c < 26; c++){
        for(int i = n-1; i >= 0; i--){
            nxt[i][c] = (s[i+1] == ('a'+c) ? i+1 : nxt[i+1][c]);
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!dp[i][j]) continue;
            for(int c = 0; c < 26; c++){
                if(nxt[i][c] <= n){
                    add(dp[nxt[i][c]][j+1], dp[i][j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        add(ans , dp[i][k]);
    }
    cout << ans << endl;
    return 0;
}