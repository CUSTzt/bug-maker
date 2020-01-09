#include <bits/stdc++.h>
using namespace std;
int n,len;
int dp[100005];
int a[100005],b[100005];
int solve(int a[])
{
	int len;
	dp[0]=a[0];
	len=1;
	for(int i=1;i<n;i++)
	{
		dp[a[i] >= dp[len - 1] ? len++ : upper_bound(dp, dp+ len, a[i]) - dp] = a[i];
	}
	return len;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int flag=n-1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[flag--]=a[i];
		}
		int sum1=solve(a),sum2=solve(b);
		if((sum1>=n-1)||(sum2>=n-1)) printf("YES\n");
		else printf("NO\n");
	}
 } 