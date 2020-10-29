#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
const int Maxn=2010;
using namespace std;
typedef pair<int,int> pll;
int a[Maxn],b[Maxn],c[Maxn];
signed main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&m,&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<m-1;i++){
			priority_queue<pll,vector<pll>,greater<pll> >q;
			for(int j=0;j<n;j++){
				scanf("%d",&b[j]);
				q.push(make_pair(a[0]+b[j],0)); 
			}
			for(int j=0;j<n;j++){
				pll tmp=q.top();q.pop();
				int s=tmp.first,p=tmp.second;
				q.push(make_pair(s-a[p]+a[p+1],p+1));
				c[j]=s;
			}
			for(int j=0;j<n;j++)a[j]=c[j];
			
		}
		for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}printf("\n");
	}
	return 0;
}
