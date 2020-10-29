#include<bits/stdc++.h>
using namespace std;
const long long maxn=1001;
long long ans[maxn][maxn],n,m,head[maxn],last[maxn],Next[maxn],tot,x;
void add(int x,int y){				//建边 
    last[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
long long Hash(int x,int f)	{
    long long q[maxn],ans=maxn,top=0;
    for(int i=head[x];i;i=Next[i])	//遍历所以子节点 
    if(last[i]!=f)					//不能再次遍历以遍历的点，即x的父亲 
	q[++top]=Hash(last[i],x);
    sort(q+1,q+top+1);				//把哈希打得更乱 
    for(int i=1;i<=top;i++)			//对x点计算哈希值 
    ans=ans*2333+q[i];
    return ans*2333+maxn+1;
}
int main(){
    cin>>m;
    for(int i=1;i<=m;i++){
        tot=0;memset(head,0,sizeof(head));		//建边清0 
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>x; if(x!=0)add(x,j),add(j,x);
        }
        for(int j=1;j<=n;j++)
        ans[i][j]=Hash(j,0);			//树哈希 
        sort(ans[i]+1,ans[i]+n+1);
        for(int j=1,k=0;j<=i;j++){
            while(k<=n) if(ans[i][++k]!=ans[j][k]) break;	//找同构 
            if(k>n){printf("%d\n",j);break;}	//找到同构就输出 
        }
    }
    return 0;
}