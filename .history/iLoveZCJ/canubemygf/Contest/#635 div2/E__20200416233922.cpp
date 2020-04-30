// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3100;
char s[N], t[N];
int dp[N][N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n , m;
    cin >> s+1 >> t+1;
    n = strlen(s+1), m = strlen(t+1);
    for(int i = 1; i <= m; i++){
        dp[i][i-1] = 1; 
    }
    for(int i = 1, len = 1; i <= n; i++, len++){
        for(int l = 1; ;l++){
            int r = l+len - 1;

        }
    }
    ll ans = 0;
    for(int i = n; i >= m; i--){
        add()

    }
    return 0;
}