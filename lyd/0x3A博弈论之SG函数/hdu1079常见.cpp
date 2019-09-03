 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-16 20:44:34
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
int dp[2100][13][32];
int f[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int y){
	if(y%400==0||(y%4==0&&y%100!=0))
		return true;
	return false;
}
bool ok(int y,int m,int d){
	if(isleap(y)&&m==2){
		if(d<=29)return true;
		return false;
	}
	if(d<=f[m])return true;
	return false;
}
int slove(int y,int m,int d){
	if(y==2001&&m==11&&d==4)return dp[y][m][d]=0;
	if(y>2001)return dp[y][m][d]=1;
	if(y==2001&&m>11)return dp[y][m][d]=1;
	if(y==2001&&m==11&&d>4)return dp[y][m][d]=1;
	if(dp[y][m][d]!=-1)
        return dp[y][m][d];
	int ty=y,tm=m,td=d;
	if(isleap(ty)&&tm==2){
		td++;
		if(td==30)td=1,tm++;
	}
	else {
		td++;
		if(td>f[tm]){
			td=1;
			tm++;
			if(tm>12)ty++,tm=1;
		}
	}
	if(slove(ty,tm,td)==0)return dp[y][m][d]=1;
	ty=y,tm=m,td=d;
	tm++;
	if(tm>12)ty++,tm=1;
	if(ok(ty,tm,td)&&slove(ty,tm,td)==0)
		return dp[y][m][d]=1;
	return dp[y][m][d]=0;
}
int main()
{
	int t;
	cin>>t;
	int y,m,d;
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		cin>>y>>m>>d;
		if(slove(y,m,d))cout<<"YES"<<endl;
		else cout<<"NO\n";
	}
}
