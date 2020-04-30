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
bool check(int x, int y){
    if(x <= h && y <= w && x >= 1 && y >= 1)return true;
    return false;
}
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
                if(check(i-1,j))
            }else dp[i][j] = 0;
        }
    }
    cout << dp[h][w];
    return 0;
}