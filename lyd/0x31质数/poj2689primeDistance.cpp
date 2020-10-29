#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=1e6+10;
int pri[maxn],tot;
bool vis[maxn];
void pre()
{
	for(int i=2;i<maxn;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<maxn;j++){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)	break;
		}
	}
}
bool bk[1000086];
int32_t main()
{
	int l,r;pre();
	while(~scanf("%lld%lld",&l,&r)){
		int t1=0,t2=0,t3=0,t4=0,pre=0,mi=1e9,mx=0;
		memset(bk,0,sizeof bk);
		for(int i=0;i<tot;i++){
			for(int j=max((int)ceil(1.0*l/pri[i]),2ll);j<=r/pri[i];j++){
				bk[pri[i]*j-l]=1;
			}
		}
		for(int i=l;i<=r;i++){
			if(bk[i-l])	continue;
			if(i==1)	continue;
			if(pre){
				if(i-pre>mx){
					mx=i-pre;t3=pre;t4=i;
				}
				if(i-pre<mi){
					mi=i-pre;t1=pre;t2=i;
				}
			}
			pre=i;
		}
		if(t1&&t2&&t3&&t4)
			printf("%d,%d are closest, %d,%d are most distant.\n",t1,t2,t3,t4);
		else
			printf("There are no adjacent primes.\n");
	}
	
}