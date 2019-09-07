//others
/*

异或  按位做
假设现在在做第i位，为了描述方便，现在的边权是val[y]&(1<<i)

设f[x]表示x到n的路径异或和为1的期望，

那么就有方程f[x]=∑f[son[x]]*(1-val[y])（如果边权为0）+(1-f[son[x]])*val[y]（如果边权为1）

然后解方程就可以了。


*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=205,maxm=20010;
const double eps=1e-10;
using namespace std;
typedef double ld;
int n,m,pre[maxm],now[maxn],son[maxm],val[maxm],tot,deg[maxn];ld a[maxn][maxn],ans;
void add(int x,int y,int z){pre[++tot]=now[x],now[x]=tot,son[tot]=y,val[tot]=z,++deg[x];}
 
void gauss(){
	/*for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n+1;j++)
			printf("%.10f ",(double)a[i][j]);*/
	for (int i=1;i<=n;i++){
		int id=i;ld maxs=0.0;
		for (int j=i;j<=n;j++) if (fabs(a[j][i])>maxs) id=j,maxs=fabs(a[j][i]);
		if (id!=i) for (int j=1;j<=n+1;j++) swap(a[id][j],a[i][j]);
		ld t=a[i][i];for (int j=1;j<=n+1;j++) a[i][j]/=t;
		for (int j=1;j<=n;j++)
			if (j!=i){
				ld t=a[j][i];
				for (int k=1;k<=n+1;k++) a[j][k]-=t*a[i][k];
			}
	}
}
 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z),add(x,y,z);
		if (x!=y) add(y,x,z);
	}
	for (int i=0;i<=30;i++){
		memset(a,0,sizeof(a));
		for (int x=1;x<=n-1;x++){
			a[x][x]=1.0;
			for (int y=now[x];y;y=pre[y]){
				if (val[y]&(1<<i)) a[x][son[y]]+=1.0/deg[x],a[x][n+1]+=1.0/deg[x];
				else a[x][son[y]]-=1.0/deg[x];
			}
		}
		a[n][n]=1.0,gauss(),ans+=(a[1][n+1])*(1<<i);
	}
	printf("%.3lf\n",(double)ans);
	return 0;
}