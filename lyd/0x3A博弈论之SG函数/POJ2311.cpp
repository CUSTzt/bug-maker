 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-16 15:15:24
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
const int N = 206;
int sg[N][N];
int n,m;
int SG(int x,int y){
	bool f[N];
	memset(f,0,sizeof(f));
	if (sg[x][y]!=-1)return sg[x][y];
	for(int i = 2;i <= x-i ;i++)f[SG(i,y)^SG(x-i,y)]=1;
	for(int i = 2;i <= y-i ;i++)f[SG(x,i)^SG(x,y-i)]=1;
    int t=0;
	while(f[t])t++;
	return sg[x][y]=t;
}
int main()
{
	memset(sg, -1 ,sizeof(sg));
	sg[2][2]=sg[2][3]=sg[3][2]=0;
	while(cin>>n>>m){
		puts(SG(n,m)?"WIN":"LOSE");
	}
}