#include<bits/stdc++.h>
#define lson (o<<1)
#define rson (o<<1|1)
#define fi first
#define sc second
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
using namespace std;
const double pi=acos(-1);
const double eps=1e-6;
inline int lowbit(int x){return x&(-x);}
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
template<typename T> inline T max(T x,T y,T z){return max(max(x,y),z);}
template<typename T> inline T min(T x,T y,T z){return min(min(x,y),z);}
template<typename T> inline T sqr(T x){return x*x;}
template<typename T> inline void checkmax(T &x,T y){x=max(x,y);}
template<typename T> inline void checkmin(T &x,T y){x=min(x,y);}
template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
template<typename A,typename B,typename C> inline A fpow(A x,B p,C yql){
	A ans=1;
	for(;p;p>>=1,x=1LL*x*x%yql)if(p&1)ans=1LL*x*ans%yql;
	return ans;
}
struct FastIO{
	static const int S=1310720;
	int wpos;char wbuf[S];
	FastIO():wpos(0) {}
	inline int xchar(){
		static char buf[S];
		static int len=0,pos=0;
		if(pos==len)pos=0,len=fread(buf,1,S,stdin);
		if(pos==len)return -1;
		return buf[pos++];
	}
	inline int read(){
		int c=xchar(),x=0;
		while(c<=32&&~c)c=xchar();
		if(c==-1)return -1;
		for(;'0'<=c&&c<='9';c=xchar())x=x*10+c-'0';
		return x;
	}
}io;
//#define read io.read

const int N=1e6+10;
queue<pair<int,int> > Q,Q2;
int n,m;
int fa1[N],size1[N];
int fa2[N],size2[N];
inline int find(int *fa,int x){return x==fa[x]?x:fa[x]=find(fa,fa[x]);}
inline void merge(int *fa,int *size,int u,int v){
	u=find(fa,u);v=find(fa,v);
	if(u==v)return;
	if(size[u]<size[v])swap(u,v);
	fa[v]=u;size[u]+=size[v];
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){fa1[i]=i;size1[i]=1;fa2[i]=i;size2[i]=1;}
	while(m--){
		int opt=read(),u=read(),v=read();
		if(opt==1)Q.push(make_pair(u,v)),merge(fa2,size2,u,v);
		else merge(fa1,size1,u,v),Q2.push(make_pair(u,v));
		while(!Q.empty()){
			int u=Q.front().fi,v=Q.front().sc;
			if(find(fa1,u)!=find(fa1,v))break;
			Q.pop();
		}
		while(!Q2.empty()){
			int u=Q2.front().fi,v=Q2.front().sc;
			if(find(fa2,u)!=find(fa2,v))break;
			Q2.pop();
		}
		if(Q.empty()&&Q2.empty())puts("A");else puts("B");
	}
}
