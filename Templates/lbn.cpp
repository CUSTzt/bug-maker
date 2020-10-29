
#include<bits/stdc++.h>
using namespace std;
//�ض��� 
#define MP make_pair
#define MT make_tuple 
#define PH push
#define PB push_back
#define PP pop_back
#define RS resize
#define PQ priority_queue
#define VEC vector
#define STR string
#define BIT bitset
#define TI (*this)
#define X first
#define Y second
#define x(o) get<0>(o)
#define y(o) get<1>(o)
#define z(o) get<2>(o)
#define Get(o,x) get<x>(o)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define sqr(x) ((x)*(x))
#define CL(a) memset(a,0,sizeof a)
#define FIL(a,b) memset(a,b,sizeof a)
#define CP(a,b) memcpy(a,b,sizeof b)
#define CR(a) a.clear()
#define fr(i,n) for(int i=1;i<=n;i++)
#define FR(i,s,n) for(int i=s;i<=n;i++)
#define f0(i,n) for(int i=0;i<=n;i++)
#define dr(i,n) for(int i=n;i;i--)
#define DR(i,n,s) for(int i=n;i>=s;i--)
#define d0(i,n) for(int i=n;~i;i--)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define rd(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
//���ͱ��� 
typedef double D;
typedef long double LD;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef queue<int> QI;
typedef complex<double>CD;
//���� 
const int N=111111;
const int M=1000000007;
const int INF=1e9;
const D eps=1e-8;
const D pi=acos(-1);
//���ú��� 
template<typename T>int sgn(T x){return x<eps?-1:x>eps;}
template<typename T,typename T2>int cmp(T x,T2 y){return sgn(x-y);}
template<typename T,typename T2>bool Fmin(T&x,const T2&y){return x>y?x=y,1:0;}
template<typename T,typename T2>bool Fmax(T&x,const T2&y){return x<y?x=y,1:0;} 
template<typename T,typename T2>T GF(T fz,T2 fm){return fz>=0?fz/fm:-((-fz-1)/fm)-1;}
template<typename T,typename T2>T GC(T fz,T2 fm){return fz>0?(fz-1)/fm+1:-(-fz/fm);}
namespace Math{//author lbn187
	LL Mul(LL a,LL b,LL p){
		LL t=(a*b-LL((long double)a/p*b+1e-3)*p)%p;
		return t<0?t+p:t;
	}
	LL FastMul(LL a,LL b,LL p){
	   	LL v=0;
	   	for(;b;a=(a+a)%p,b>>=1)
	       	if(b&1)v=(v+a)%p;
	   	return v;
	}
	LL Pw(LL a,LL b,LL p=M){
		LL v=1;
		for(a%=p;b;a=a*a%p,b>>=1)
			if(b&1)v=v*a%p;
		return v;
	}
	LL gcd(LL a,LL b){//递归版gcd 
		return b?gcd(b,a%b):a;
	}
	LL ungcd(LL a,LL b){//非递归版gcd 
		for(LL t;b;)t=a%b,a=b,b=t;
	    	return a;
	}
	void exgcd(LL a,LL b,LL&x,LL&y,LL&d){
		if(!b)x=1,y=0,d=a;else
		exgcd(b,a%b,y,x,d),y-=a/b*x;
	}
	LL phi(LL n){
		LL i,V=n;
		for(i=2;i*i<=n;i++)
		    if(n%i==0)for(V=V/i*(i-1);n%i==0;)n/=i;
		if(n>1)V=V/n*(n-1);
		return V;
	}
	LL inv1(LL a,LL n){//求a关于模数n的逆元 
		LL d,x,y;
		exgcd(a,n,x,y,d);
		return d==1?(x+n)%n:-1;
	}
	LL inv2(LL a,LL p){return Pw(a,p-2,p);}//费马小定理 
	LL inv3(LL a,LL n){return Pw(a,phi(n)-1,n);}//欧拉定理
	LL inv4(LL i,LL m){//递归求单个数的逆元 
		if(i==1)return 1;
		return inv4(m%i,m)*(m-m/i)%m;
	}
	void preinv(int n,int M,int inv[]){//预处理1~n模M的逆元 
		inv[1]=1;
		for(int i=2;i<=n;i++)inv[i]=1ll*inv[M%i]*(M-M/i)%M;
	}
	bool IsPrime(LL x){
		for(LL i=2;i*i<=x;i++)if(x%i==0)return 0;
		return 1;
	}
	VEC<LL> Factor(LL x){
		VEC<LL>p;
		for(LL i=2;i*i<=x;i++)
			for(;x%i==0;x/=i)p.PB(i);
		return p;
	}
	VI GetPrime(int n){
		VI P,f;f.RS(n+1); 
		FR(i,2,n){//enumnate
			if(!f[i])P.PB(i);//i is a prime
			for(auto x:P){
				if(i*x>n)continue;
				f[i*x]=1;//i*x is not a prime
				if(i%x==0)break;//optimize
			}
		}
		return P;
	}
	bool ck(LL a,LL n){
		if(a>=n)return 0;
		LL d=n-1,t=0;for(;d%2==0;d/=2)t++;
		LL V=Pw(a,d,n),la=V;
		fr(i,t){
			V=FastMul(V,V,n);
			if(V==1&&la!=1&&la!=n-1)return 1;
			la=V;
		}
		return V!=1;
	}
	bool MillerRabin(LL n){
		static vector<LL> numbers={2,7,61,325,9375,28178,450775,9780504,1795265022};
		if(n<=1)return 0;if(n==2)return 1;if(n%2==0)return 0;
		for(LL x:numbers)if(ck(x,n))return 0;
		return 1;
	}
	LL Rho(LL n,LL c){
	    LL i=1,k=2,x0=rand()%(n-1)+1,y=x0,d;//随机x_0∈[1,n)
		for(;;){
		    i++;
		    x0=(FastMul(x0,x0,n)+c)%n;//x_(i+1)=x_i^2+c
		    d=gcd(labs(y-x0),n);//计算d=gcd?(a-b,n)
		    if(d!=1&&d!=n)return d;//如果d≠1且d≠n，则d是n的因子
		    if(y==x0)return n;//出现循环，退出
		    if(i==k)y=x0,k+=k;//i是2的次幂，令y=x_i
		}
	}
	VEC<LL> PollardRho(LL n){
		if(MillerRabin(n))return {n};
		LL p=n;//尝试分解
		for(;p>=n;)p=Rho(n,rand()%(n-1)+1);//随机c∈[1,n)
		VEC<LL>a=PollardRho(p),b=PollardRho(n/p);
		for(auto x:b)a.PB(x);
		return a;
	}
}
using namespace Math;
	namespace GraphTheory{//author lbn187
		namespace GRAPH{
			struct Graph{
				static const int N=111111;
				int n,m;
				VI V[N];
				Graph()=default;
				Graph(int _n):n(_n){}
				Graph(const Graph &G):n(G.n),m(G.m){fr(i,n)V[i]=G.V[i];}
				Graph &operator=(const Graph &G){
					if(this==&G)return *this;
					fr(i,n)V[i].clear();
					n=G.n;m=G.m;
					fr(i,n)V[i]=G.V[i];
					return *this;
				}
				Graph(Graph &&G)noexcept:n(G.n),m(G.m){fr(i,n)V[i].swap(G.V[i]);}
				Graph &operator=(Graph &&G)noexcept{
					n=G.n;m=G.m;
					fr(i,n)V[i].swap(G.V[i]);
					return *this;
				}
				~Graph(){clear();}
				void init(int _n){n=_n;clear();}
				void clear(){fr(i,n)V[i].clear();m=0;}
				void ins(int x,int y){V[x].PB(y);m++;}
			};
			ostream &operator<<(ostream &os,const Graph &G){//重载输出
				os<<"N = "<<G.n<<" , "<<"M = "<<G.m<<endl;
				fr(x,G.n)for(auto y:G.V[x])os<<x<<" -> "<<y<<endl;
				return os;
			}
			istream &operator>>(istream &is,Graph &G){//重载输入
				is>>G.n>>G.m;
				int x,y;
				fr(i,G.m)is>>x>>y,G.ins(x,y);
				return is;
			}
			Graph Transpose_Graph(Graph G){//反图
				Graph _G(G.n);
				fr(x,G.n)for(int y:G.V[x])_G.ins(y,x);
				return _G;
			}
			Graph Anti_Graph(Graph G){//补图
				bool vs[G.N];
				Graph _G(G.n);
				fr(i,G.n){
					fr(j,G.n)vs[j]=0;vs[i]=1;
					for(int x:G.V[i])vs[x]=1;
					fr(j,G.n)if(!vs[j])_G.ins(i,j);
				}
				return _G;
			}
			VI BFS(Graph G,int S){
				VI E;QI Q;bool v[G.N];
				fr(i,G.n)v[i]=0;
				Q.PH(S);v[S]=1;
				for(;!Q.empty();){
					int x=Q.front();E.PB(x);Q.pop();
					for(int y:G.V[x])if(!v[y])v[y]=1,Q.PH(y);
				}
				return E;
			}
			VI Topological_Sorting(Graph G){
				int du[G.N];VI E;QI Q; 
				fr(i,G.n)du[i]=0;
				fr(x,G.n)for(int y:G.V[x])du[y]++;
				fr(i,G.n)if(!du[i])Q.PH(i);
				for(;!Q.empty();){
					int x=Q.front();E.PB(x);Q.pop();
					for(int y:G.V[x])if(!--du[y])Q.PH(y);
				}
				return E;
			}
			struct Undirected_Graph{
				static const int N=111111;
				int n,m;
				VI V[N];
				Undirected_Graph()=default;
				Undirected_Graph(int _n):n(_n),m(0){}
				Undirected_Graph(const Undirected_Graph &G):n(G.n),m(G.m){fr(i,n)V[i]=G.V[i];}
				~Undirected_Graph(){clear();}
				Undirected_Graph &operator=(const Undirected_Graph &G){
					if(this==&G)return *this;
					fr(i,n)V[i].clear();
					n=G.n;m=G.m;
					fr(i,n)V[i]=G.V[i];
					return *this;
				}
				Undirected_Graph(Undirected_Graph &&G)noexcept:n(G.n),m(G.m){fr(i,n)V[i].swap(G.V[i]);}
				Undirected_Graph &operator=(Undirected_Graph &&G)noexcept{
					n=G.n;m=G.m;
					fr(i,n)V[i].swap(G.V[i]);
					return *this;
				}
				void init(int _n){n=_n;clear();}
				void clear(){fr(i,n)V[i].clear();m=0;}
				void ins(int x,int y){V[x].PB(y);V[y].PB(x);m++;}
				Graph To_Graph(){
					Graph G(n);
					fr(x,n)for(auto y:V[x])G.ins(x,y);
					return G;
				}
			};
			ostream &operator<<(ostream &os,const Undirected_Graph &G){
				os<<"N = "<<G.n<<" , "<<"M = "<<G.m<<endl;
				fr(x,G.n)for(auto y:G.V[x])if(x<=y)os<<x<<" --- "<<y<<endl;
				return os;
			}
			istream &operator>>(istream &is,Undirected_Graph &G){
				is>>G.n>>G.m;
				int x,y;
				fr(i,G.m)is>>x>>y,G.ins(x,y);
				return is;
			}
			template<typename T,const int N> struct Weight_Graph{
				int n,m;
				VEC<pair<int,T> >V[N];
				Weight_Graph()=default;
				Weight_Graph(int _n):n(_n),m(0){}
				Weight_Graph(const Weight_Graph&G):n(G.n),m(G.m){fr(i,n)V[i]=G.V[i];}
				~Weight_Graph(){clear();}
				Weight_Graph &operator=(const Weight_Graph&G){
					if(this==&G)return *this;
					fr(i,n)V[i].clear();
					n=G.n;m=G.m;
					fr(i,n)V[i]=G.V[i];
					return *this;
				}
				Weight_Graph(Weight_Graph &&G)noexcept:n(G.n),m(G.m){fr(i,n)V[i].swap(G.V[i]);}
				Weight_Graph &operator=(Weight_Graph &&G)noexcept{
					n=G.n;m=G.m;
					fr(i,n)V[i].swap(G.V[i]);
					return *this;
				}
				void init(int _n){n=_n;clear();}
				void clear(){fr(i,n)V[i].clear();m=0;}
				void ins(int x,int y,T z){V[x].PB(MP(y,z));m++;}
				Graph To_Graph(){
					Graph G(n);
					fr(x,n)for(auto o:V[x])G.ins(x,o.X);
					return G;
				}
			};
			template<typename T,const int N> ostream &operator<<(ostream &os,const Weight_Graph<T,N> &G){
				os<<"N = "<<G.n<<" , "<<"M = "<<G.m<<endl;
				fr(x,G.n)for(auto o:G.V[x])os<<x<<" -> "<<o.X<<" ["<<o.Y<<"]"<<endl;
				return os;
			}
			template<typename T,const int N> istream &operator>>(istream &is,Weight_Graph<T,N> &G){
				is>>G.n>>G.m;
				int x,y;T z;
				fr(i,G.m)is>>x>>y>>z,G.ins(x,y,z);
				return is;
			}
		}
		namespace TREE{//basic
			using namespace GRAPH;
			struct Tree{
				int n,rt,allhash;
				VEC<VI>V,fa;
				VI sz,mv,st,ed,to,d,F,pos,bl,fztr,hash1,hash2;
				private:
					int id,nv,u,w,logv,mt;
					bool fBLLCA,fLCA,fSTLCA,fShupou,fXushu,fHash,FEvHash,fHashVal;
					VI hs,vis,VIS,d1,d2;
					VEC<PII>seq,UV;
					//RMQ<PII>Tr;//ST倍增LCA中用到，需要用到RMQ类
					//VEC<TrHash>HASH;//树哈希类，在树哈希中才会用到
					void dfsfa(int x,int fa);
					void dfssz(int x,int fa);
					void dfsid(int x,int fa);
					void dfsdeep(int x,int fa,int dis);
					void dfsdis(int x,int fa,int dis);		
					void BLInit();
					void LCAInit();
					void STdfs(int x,int fa);
					void STLCAInit();
					void Shupoudfs(int x);
					void Shupoudfs2(int x,int fa);
					void ShupouInit();
					void dsz(int x,int fa);
					void drt(int zs,int x,int fa,int &rt);
					int fz(int x);
					void XushuInit();
					void dfsHash(int x,int fa);
					void dfsEveryHash(int x,int fa);
					void HashInit();
					void EveryHashInit();
					void HashValueInit();
				public:
					Tree(){rt=1;};
					Tree(int _n,int _rt=1):n(_n),rt(_rt){V.RS(n+1);}
					Tree(VEC<PII> p,int _rt=1):rt(_rt){
						n=SZ(p)+1;V.RS(n+1);
						for(auto o:p)ins(o.X,o.Y);
					}
					Tree(int _n,int *fa,int _rt=1):n(_n),rt(_rt){
						V.RS(n+1);
						fr(i,n){
							if(fa[i])ins(fa[i],i);
							if(!fa[i]&&!rt)rt=i;
						}
					}
					Tree(const Tree&G):n(G.n),rt(G.rt),V(G.V),sz(G.sz),mv(G.mv),st(G.st),ed(G.ed),to(G.to),d(G.d),F(G.F),pos(G.pos),fa(G.fa),seq(G.seq),bl(G.bl),fztr(G.fztr),hash1(G.hash1),hash2(G.hash2){
						logv=G.logv;fBLLCA=G.fBLLCA;fLCA=G.fLCA;fSTLCA=G.fSTLCA;fShupou=G.fShupou;fXushu=G.fXushu;
					}
					Tree &operator=(const Tree&G){
						if(this==&G)return *this;
						n=G.n;rt=G.rt;V=G.V;sz=G.sz;mv=G.mv;st=G.st;ed=G.ed;to=G.to;d=G.d;F=G.F;pos=G.pos;fa=G.fa;seq=G.seq;bl=G.bl;fztr=G.fztr;hash1=G.hash1;hash2=G.hash2;	
						logv=G.logv;fBLLCA=G.fBLLCA;fLCA=G.fLCA;fSTLCA=G.fSTLCA;fShupou=G.fShupou;fXushu=G.fXushu;
						return *this;
					}
					~Tree(){clear();}
					void init(int _n,int _rt=1){
						n=_n;clear();V.RS(n+1);
						if(_rt)rt=_rt;
					}
					void init(vector<PII> p,int _rt=1){
						n=SZ(p)+1;clear();V.RS(n+1);
						if(_rt)rt=_rt;
						for(auto o:p)ins(o.X,o.Y);
					}
					void clear(){
						CR(V);CR(sz);CR(mv);CR(st);CR(ed);CR(to);CR(d);CR(F);CR(pos);CR(fa);CR(seq);CR(fztr);CR(hash1);CR(hash2);
						fBLLCA=fLCA=fSTLCA=fShupou=fXushu=0;
					}
					void ins(int x,int y){V[x].PB(y);V[y].PB(x);}
					void SetRT(int x){
						if(x==rt)return;rt=x;
						CR(V);CR(sz);CR(mv);CR(st);CR(ed);CR(to);CR(d);CR(F);CR(pos);CR(fa);CR(seq);CR(fztr);CR(hash1);CR(hash2);
						fBLLCA=fLCA=fSTLCA=fShupou=fXushu=0;
					}
					Graph ToGraph(){
						Graph G(n);
						fr(x,n)for(int y:V[x])G.ins(x,y);
						return G;
					}
					Undirected_Graph ToUDGraph(){
						Undirected_Graph G(n);
						fr(x,n)for(int y:V[x])if(x<y)G.ins(x,y);
						return G;
					}
					void Dfsfa(int x=0);
					void Dfssz(int x=0);
					void Dfsid(int x=0);
					void Dfsdeep(int x=0,int dis=0);
					pair<int,PII> Diameter();
					int Center();	
					int BruteLCA(int x,int y);
					int BruteLCA(int x,int y,int z);
					int BruteDis(int x,int y);
					VI Path(int x,int y);
					int LCA(int x,int y);
					int LCA(int x,int y,int z);
					int GetFa(int x,int step);
					int Dis(int x,int y);
					int Append(int x);
					PII Intersect(int s1,int t1,int s2,int t2);
					int STLCA(int x,int y);
					int STLCA(int x,int y,int z);
					int STDis(int x,int y);
					vector<PII> Shupou(int x,int y);
					int ShupouLCA(int x,int y);
					int ShupouLCA(int x,int y,int z);
					int ShupouDis(int x,int y);
					VI Prufer();
					VI Fenzhi();
					vector<PII> Xushu(VI p);
					int Hash(int x);
					int EveryHash(int x);
					int HashValue();
			};
			void Tree::dfsfa(int x,int fa){
				for(int y:V[x])if(y!=fa)
					F[y]=x,dfsfa(y,x);
			}
			void Tree::Dfsfa(int x){
				if(x<0||x>n)cerr<<"GG"<<endl;
				F.RS(n+1);
				if(x)rt=x;
				if(!rt)rt=1;//默认以1为根
				dfsfa(rt,0);
			}
			void Tree::dfsid(int x,int fa){
				st[x]=++id;to[id]=x;
				for(int y:V[x])if(y!=fa)dfsid(y,x);
				ed[x]=id;
			}
			void Tree::Dfsid(int x){
				if(x<0||x>n)cerr<<"GG"<<endl;
				st.RS(n+1);to.RS(n+1);ed.RS(n+1);id=0;
				if(x)rt=x;
				if(!rt)rt=1;//默认以1为根
				dfsid(rt,0);
			}
			void Tree::dfssz(int x,int fa){
				sz[x]=1;mv[x]=0;
				for(int y:V[x])if(y!=fa)
					dfssz(y,x),sz[x]+=sz[y],mv[x]=max(mv[x],mv[y]);
				mv[x]=max(mv[x],n-sz[x]);
			}
			void Tree::Dfssz(int x){
				if(x<0||x>n)cerr<<"GG"<<endl;
				sz.RS(n+1);mv.RS(n+1);
				if(x)rt=x;
				if(!rt)rt=1;//默认以1为根
				dfssz(rt,0);
			}
			int Tree::Center(){//树的重心
				Dfssz(1);
				fr(i,n)if(mv[i]<=n/2)return i;
			}
			void Tree::dfsdeep(int x,int fa,int dis){
				d[x]=dis;
				for(int y:V[x])if(y!=fa)dfsdeep(y,x,dis+1); 
			}
			void Tree::Dfsdeep(int x,int dis){
				if(x<0||x>n)cerr<<"GG"<<endl;
				d.RS(n+1);
				if(x)rt=x;
				if(!rt)rt=1;//默认以1为根
				dfsdeep(rt,0,dis);
			}
			void Tree::dfsdis(int x,int fa,int dis){
				if(dis>nv)nv=dis,u=x;
				for(int y:V[x])if(y!=fa)dfsdis(y,x,dis+1);
			}
			pair<int,PII> Tree::Diameter(){
				u=1;nv=0;
				dfsdis(1,0,0);
				w=u;nv=0;dfsdis(w,0,0);
				return MP(nv,MP(w,u));
			}
			void Tree::BLInit(){
				if(!rt)rt=1;
				Dfsfa(rt);
				Dfsdeep(rt,1);
				fBLLCA=1;
			}
			int Tree::BruteLCA(int x,int y){
				if(x<=0||y<=0||x>n||y>n)cerr<<"GG"<<endl;
				if(!fBLLCA)BLInit();
				for(;x!=y;x=F[x])if(d[x]<d[y])swap(x,y);
				return x;
			}
			int Tree::BruteLCA(int x,int y,int z){
				return BruteLCA(x,y)^BruteLCA(x,z)^BruteLCA(y,z);
			}
			int Tree::BruteDis(int x,int y){
				int z=BruteLCA(x,y);
				return d[x]+d[y]-d[z]*2;
			}
			VI Tree::Path(int x,int y){
				int z=BruteLCA(x,y);VI p,q;
				for(;x!=z;x=F[x])p.PB(x);
				for(;y!=z;y=F[x])q.PB(x);
				reverse(ALL(q));p.PB(z);
				for(auto o:q)p.PB(o);
				return p;
			}
			void Tree::LCAInit(){
				BLInit();//要用到暴力LCA初始化
				fa.resize(n+1);
				f0(i,n)fa[i].PB(F[i]);
				logv=(int)log2(n+1);
				fr(j,logv)f0(i,n)fa[i].PB(fa[fa[i][j-1]][j-1]);
			}
			int Tree::LCA(int x,int y){
				if(x<=0||y<=0||x>n||y>n)cerr<<"GG"<<endl;
				if(!fLCA)LCAInit();
				if(d[x]<d[y])swap(x,y);
				int t=d[x]-d[y];
				f0(i,logv)if(t>>i&1)x=fa[x][i];
				d0(i,logv)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
				return x==y?x:fa[x][0];
			}
			int Tree::LCA(int x,int y,int z){
				return LCA(x,y)^LCA(x,z)^LCA(y,z);
			}
			int Tree::GetFa(int x,int step){
				if(x<=0||x>n||step<0)cerr<<"GG"<<endl;
				if(step>n)return 0;
				if(!fLCA)LCAInit();
				f0(i,logv)if(step>>i&1)x=fa[x][i];
				return x;
			}
			int Tree::Dis(int x,int y){
				int z=LCA(x,y);
				return d[x]+d[y]-2*d[z];
			}
			int Tree::Append(int x){
				n++;
				F.PB(x);d.PB(d[x]+1);
				fa.PB({});fa[n].PB(x);
				logv=(int)log2(n+1);
				fr(i,logv)fa[n][i]=fa[fa[n][i-1]][i-1];
				return n; 
			}
			PII Tree::Intersect(int s1,int t1,int s2,int t2){
				int v1=LCA(s1,t1,s2),v2=LCA(s1,t1,t2);
				if(v1!=v2||v1==v2&&LCA(s2,t2)==v1)return MP(v1,v2);
				return MP(0,0);
			}
			ostream &operator<<(ostream &os,const Tree&G){
				os<<"N = "<<G.n<<",   rt = "<<G.rt<<endl;
				fr(x,G.n)for(auto y:G.V[x])if(x<y)os<<x<<" --- "<<y<<endl;
				return os;
			}
			istream &operator>>(istream &is,Tree &G){
				G.clear();
				is>>G.n;G.rt=1;//默认以1为根
				G.V.RS(G.n+1);
				int x,y;
				fr(i,G.n-1)is>>x>>y,G.ins(x,y);
				return is;
			}
			bool operator==(Tree a,Tree b);//要用到树哈希
			bool operator!=(Tree a,Tree b);
			Tree GetTree(VI seq);
		}
		struct DSU{
			static const int N=111111;
    		int n,cnt,F[N];
			DSU()=default;
			DSU(int _n):n(_n),cnt(_n){clear();}
			DSU(const DSU&A):n(A.n),cnt(A.n){fr(i,n)F[i]=A.F[i];}
			DSU& operator=(const DSU&A){
				if(this==&A)return *this;
				n=cnt=A.n;
				fr(i,n)F[i]=A.F[i];
				return *this;
			}
			void init(int _n){n=cnt=_n;clear();}
			void clear(){cnt=n;iota(F,F+n+1,0);}
			int fd(int x){return F[x]==x?x:F[x]=fd(F[x]);}
			int& operator[](int x){return F[fd(x)];}
			bool merge(int x,int y){
				x=fd(x);y=fd(y);
				if(x==y)return 0;
				cnt--;F[x]=y;
				return 1;
			}
		};
	}
namespace DataStructure{//author lbn187
		namespace BIT{//one
			template<typename T,const int N>struct IBIT{
				T a[N],b[N];
				private:
					void ad(int x,T z){
						for(int i=x;i<N;i+=i&-i)a[i]+=z,b[i]+=z*(x-1);
					}
					T qu(int x){
						T v0=0,v1=0;
						for(int i=x;i;i-=i&-i)v0+=a[i],v1+=b[i];
						return x*v0-v1;
					}
				public:
					void clear(){CL(a);CL(b);}
					void add(int x,int y,T z){add(x,z);ad(y+1,-z);}
					T sum(int x,int y){return qu(y)-qu(x-1);}
			};
		}
}