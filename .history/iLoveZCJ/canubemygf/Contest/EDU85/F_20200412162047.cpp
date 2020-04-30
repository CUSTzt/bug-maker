#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
int Begin[maxn],End[maxn];
int len[maxn];
char s[maxn];
int dp[maxn][26][2];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		len[i]=strlen(s);
		Begin[i]=s[0]-'a';
		End[i]=s[len[i]-1]-'a';
	}
	//dp[i][j][0/1] 到第i个串为止，以j结尾的最长长度，是不是单个串 的最大长度
	dp[1][End[1]][0]=len[1];
	for(int i=2;i<=n;i++){
		for(int j=0;j<26;j++){
			dp[i][j][0]=dp[i-1][j][0];
			dp[i][j][1]=dp[i-1][j][1];
		}
		dp[i][End[i]][0]=max(dp[i-1][End[i]][0],len[i]);
		if(dp[i-1][Begin[i]][0]!=0){
			dp[i][End[i]][1]=max(dp[i][End[i]][0],dp[i-1][Begin[i]][0]+len[i]);
		}
		if(dp[i-1][Begin[i]][1]!=0){
			dp[i][End[i]][1]=max(dp[i][End[i]][1],dp[i-1][Begin[i]][1]+len[i]);
		}
	}
	int mx=0;
	for(int i=0;i<26;i++)mx=max(mx,dp[n][i][1]);
	printf("%d\n",mx);
}
