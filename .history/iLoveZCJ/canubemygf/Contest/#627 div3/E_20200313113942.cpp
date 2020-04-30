//#include<bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2005
#define H 2005
int dp[N][H];
int n; int h; int l; int r; int a[N];
int main(){
    memset(dp,0xcf,sizeof(dp));
    scanf("%d %d %d %d",&n,&h,&l,&r);
    for(int i=1;i<=n;++i) scanf("%d",a+i); 
    dp[0][0]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<h;++j){
            if(dp[i][j]==0xcfcfcfcf) continue;
            int nex;
            nex=(j+a[i+1])%h;
            dp[i+1][nex]=max(dp[i+1][nex],dp[i][j]+(nex>=l&&nex<=r));
            nex=((j+a[i+1]-1)%h+h)%h;
            dp[i+1][nex]=max(dp[i+1][nex],dp[i][j]+(nex>=l&&nex<=r));
        }
    }
    int ans=0xcfcfcfcf;
    for(int i=0;i<h;++i)  ans=max(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}