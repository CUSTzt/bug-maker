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
    for(int i = 0; i <= 19;i++)
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n == 1 || n == 2 || n == 5){
        return cout << "-1",0;
    }
    
    return 0;
}