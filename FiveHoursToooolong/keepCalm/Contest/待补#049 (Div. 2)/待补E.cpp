//https://blog.csdn.net/V5ZSQ/article/details/80034145

//题意：给定n个节点的无向图，n<=10，图里面有m条边，以这m条边构建生成树，
//求所有生成树中只含有k个度数为1的点的方案数
//状压dp写法
//dp[i][j]表示生成树状态为i时，所含度数为1的点状态为j的方案数。
//状态转移：有两种更新方式，①加入一条边，（即一个新点）到原来度数为1的点，相当于替换
//②把边加到度数不为1的节点上。
//注意有一个点是当生成树状态只有一个点时更新只能是操作2，而不是操作1替换。
/*#include <bits/stdc++.h>

using namespace std;
const int maxn = (1 << 11) +10;
int dp[maxn][maxn];
vector<int > g[100];
int n , m , k , u , v , mx, cc[maxn];
void init(){
    for(int i = 0; i < maxn ; i++){
        cc[i] = __builtin_popcount(i);
    }
}
int main(){
    cin >> n >> m >> k;
    init();
    for(int i = 0; i < m ; i++){
        cin >> u >> v;
        u--,v--;
        g[u].emplace_back(v),g[v].emplace_back(u);
    }
    mx = (1 << n) - 1;
    for(int i = 1; i <= mx; i <<= 1)dp[i][i] = 1;
    for(int i=1;i<=mx;++i) {
        for(int j=i;j;--j&=i) {
            if(dp[i][j]) {
                for(int k=0;k<n;++k) {
                    if(i&(1<<k)) {
                        for(int u:g[k]) {
                            if(~i&(1<<u)) {
                                if(cc[i]==1) v=i|(1<<u);
                                else v=j&~(1<<k)|(1<<u);
                                if(!(v>>u+1)) dp[i|(1<<u)][v]+=dp[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<mx;++i) if(cc[i]==k)ans+=dp[mx][i];
    cout << ans << endl;
}*/
//https://primopan.org/?p=111
//记dp[s1][s2]为当前生成树顶点集合为s1,叶子集合为s2的情况，因为每次加边都必然产生一个叶子，
//我们在s2中枚举叶子，再枚举与它连通的点是/不是叶子的情况转移，由于dp[s1][s2]可以从|s2|个结点转移过来所以答案还要/|s2|。
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxsum 1<<11
#define maxm 105
int dp[maxsum][maxsum];
vector<int> S;
map<int,int>M;
int key[maxsum];
int a[11][11];
int n,m,k;
inline void init()
{
    for (int i=0;i<(1<<n);i++)
    {
        int cnt=0;
        for (int j=0;j<=n-1;j++)
          if ((1<<j)&i) cnt++;
        key[i]=cnt;
        if (cnt==k) {S.push_back(i);M[i]=1;}
    }
}
inline void work()
{
    for (int i=0;i<(1<<n);i++)
    {
        if (key[i]<=2) continue;
        for (int j=i;j;j=(j-1)&i)
        {
            dp[i][j]=0;
            for (int x=0;x<n;x++)
              if ((1<<x)&j)//x点作为叶子
                for (int y=0;y<n;y++)
                  if (!((1<<y)&j) && a[x][y] && (1<<y)&i)//y点不作为叶子
                  {
                  		int nm=i^(1<<x);
                    int nsm=j^(1<<x);
                    dp[i][j]+=dp[nm][nsm];//y原先度数>1
                    dp[i][j]+=dp[nm][nsm^(1<<y)];//y原先度数=1
                  }
            dp[i][j]/=key[j];
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    init();
    int x,y;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        x--,y--;
        a[x][y]=a[y][x]=1;
        int s=(1<<x)|(1<<y);
        dp[s][s]=1;
    }
    work();
    ll ans=0;
    int s=(1<<n)-1;
    for (int i=0;i<S.size();i++)
    {
        ans+=dp[s][S[i]];
    }
    cout<<ans<<endl;
}
/*
cjc
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAXN=11;
vector<int>G[MAXN];
ll dp[1<<MAXN][1<<MAXN],ans,n,m,K;
 
int chkin(int a,int b){
	return (a&b)==b;
}
int chk(int s){
	int cnt=0;
	for(int i=0;i<n;i++){
		if((s>>i)&1)cnt++;
		if(cnt>K)return 0;
	}
	if(cnt==K)return 1;
	return 0;
}
int main(){
	cin>>n>>m>>K;	
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
		dp[(1<<u)^(1<<v)][(1<<u)^(1<<v)]=1;
	}
	int state=1<<n;
	for(int s=1;s<state;s++){
		for(int lv=1;lv<state;lv++){
			if(!chkin(s,lv)||dp[s][lv]==0)continue;
			for(int u=0;u<n;u++){
				if(s>>u&1){
					for(auto v:G[u]){
						if((s>>v)&1)continue;
						if(((lv>>u)&1)&&(1<<v)>(lv^(1<<u))){
							dp[s^(1<<v)][lv^(1<<u)^(1<<v)]+=dp[s][lv];
						}else if(!((lv>>u)&1)&&(1<<v)>lv){
							dp[s^(1<<v)][lv^(1<<v)]+=dp[s][lv];
						}
					}
				}
			}
		}
	}
	ans=0;
	for(int s=0;s<state;s++){
		if(chk(s)){
			ans+=dp[state-1][s];
		}
	}
	cout<<ans;
}
*/