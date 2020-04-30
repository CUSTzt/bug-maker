// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e3 + 100;
const int mod = 1e9 + 7;
int h, w;
char a[N][N];
int dp[N][N];
int main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(a[i][j] == '.'){

            }else dp[i][j] = 0;
        }
    }
    cout << dp[h][w];
    return 0;
}