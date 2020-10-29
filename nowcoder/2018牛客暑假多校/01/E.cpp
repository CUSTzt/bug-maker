#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
int t,n,m,k;
int a[MAXN],dp[15][MAXN],ans[MAXN];
int main(){
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		ans[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j>=max(1,i-m);j--){
				ans[j]=((ans[j]+ans[j-1])%mod-dp[a[i]][j])%mod;
				dp[a[i]][j]=ans[j-1];
			}
		}
		cout<<(ans[n-m]+mod)%mod<<"\n";
	}
	return 0;
}