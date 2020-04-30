// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
//7a+4b+3c=n
//max (min(a,b,c))
//a+b+c MAX
int dp[20][3];
void pre(){
    memset(dp , 0xff,  sizeof dp);
    for(int i = 0; i <= 19; i++){
        for(int a = 0; 7*a <= i; a++){
            for(int b = 0; 7*a+4*b <= i; b++){
                if((i-7*a-4*b) % 3 == 0){
                    int c = (i-7*a-4*b) / 3 ;
                    if(dp[i][0] == -1){
                        dp[i][0] = a,dp[i][1] = b,dp[i][2] = c;
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    pre();
    cin >> n;
    if(n == 1 || n == 2 || n == 5){
        return cout << "-1",0;
    }
    for(int i = n/14; i >= n/14-1;i--){
        int left = n - 14 * i;
        if(dp[left][0] != -1){
            cout << i + dp[left][0] << ' ' << i + dp[left][1] << ' ' << i + dp[left][2] ;
            exit(0);
        }
    }
    return 0;
}