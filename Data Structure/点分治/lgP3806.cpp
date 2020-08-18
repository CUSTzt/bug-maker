//coder: FeliksGM-YB
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i,a,b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(x) for(int i=first[x],y=v[i];i;i=nex[i],y=v[i])
typedef long long ll;
using namespace std;
const int N=1e5+5;
const int M=1e7+5;
inline int Max(int x,int y){
	if(x>y)return x;
	return y;
}
inline int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x;
}int n,m,rt;//rt: 重心 
int v[N<<1],nex[N<<1],first[N],w[N<<1],tot;
inline void add(int x,int y,int z){
    v[++tot]=y,w[tot]=z;
    nex[tot]=first[x];
    first[x]=tot;
}int q[N];
int mx[N],sum;
int sz[N];
bool vis[N];
void getrt(int x,int f){//找重心 
	sz[x]=1;mx[x]=0;
	go(x){
		if(y==f || vis[y])continue;
		getrt(y,x);
		sz[x]+=sz[y];
		mx[x]=Max(mx[x],sz[y]);
	}mx[x]=Max(mx[x],sum-sz[x]);
	if(mx[x]<mx[rt])rt=x;
}bool tes[N],ext[M];
int dis[N],rem[N],cnt;
//rem记录当前子树中找到的路径长度有哪些 
void getdis(int x,int f){
	rem[++cnt]=dis[x];
	go(x){
		if(y==f || vis[y])continue;
		dis[y]=dis[x]+w[i];
		getdis(y,x);
	}
}int used[N],num;
inline void calc(int x){
	num=0;
	go(x){
		if(vis[y])continue;
		cnt=0;dis[y]=w[i];
		getdis(y,x);//处理这棵子树里的点到根 x 的距离 
		fu(j,1,cnt){
			fu(k,1,m){
				if(q[k]-rem[j]>=0 && q[k]-rem[j]<=1e7 &&
				ext[q[k]-rem[j]])tes[k]=1;
				//如果和 rem[j] 和为 q[k] 的路径存在 
			}
		}fu(j,1,cnt)//把这棵子树的路径长度也记为存在 
			if(rem[j]<=1e7)used[++num]=rem[j],ext[rem[j]]=1;
		//我不知道niiick的题解没有判 <=1e7 是怎么过的 QwQ 但它确实过了（亲测） 
	}fu(i,1,num)ext[used[i]]=0;//分治的清零都不能 memset！！！ 
}
void solve(int x){
	vis[x]=ext[0]=1;
	calc(x);//处理经过 x 的路径 
	go(x){//分治 x 为根的这棵树 
		if(vis[y])continue;
		mx[rt=0]=sum=sz[y];//这里要注意 
		getrt(y,0);solve(rt);
	}
}
int main(){
    n=read(),m=read();
    fu(i,1,n-1){
        int x=read(),y=read(),z=read();
        add(x,y,z),add(y,x,z);
    }fu(i,1,m)q[i]=read();
    mx[rt]=sum=n;
    getrt(1,0);
    solve(rt);//以重心为根分治 
    fu(i,1,m){
    	if(tes[i])puts("AYE");
    	else puts("NAY");
	}return 0;
}//Θ

