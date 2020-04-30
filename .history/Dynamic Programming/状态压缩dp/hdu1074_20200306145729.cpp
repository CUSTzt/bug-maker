// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 16;
int n;
struct node{
    char s[105];
    int d , c;
}a[N];
struct NODE{
    int mn , pre , t;
}dp[1 << N];
int main()
{
    int tt;cin >> tt;
    while(tt--){
        cin >> n;
        dp[0].mn = 0,dp[0].pre = -1,dp[0].t = 0;
        for(int i = 1; i < (1 << n);i++){
            dp[i].mn = 0x3f3f3f3f;
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i].s >> a[i].d >> a[i].c;
        }
        for(int i = 0; i < (1<<n);i++){
            for(int j = 1;j <= n; j++){
                if(!(i&(1<<j-1))){
                    int now=i|(1<<j-1),nowt=dp[i].t+a[j].c;
                    int less=max(0,nowt-a[j].d);
                    if(dp[now].mn>dp[i].mn+less)
                        dp[now].mn=dp[i].mn+less,dp[now].pre=i,dp[now].t=nowt;
                }
            }
        }
        cout << dp[ (1<<n )- 1].mn << endl;
        print((1<<n)-1);
    }
    return 0;
}