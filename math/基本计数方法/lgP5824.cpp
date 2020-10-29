// 12重计数法 
// https://blog.csdn.net/qq_42555009/article/details/105079419
#include<bits/stdc++.h>
using namespace std;
#define cs const
#define re register
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define bg begin
cs int RLEN=1<<20|1;
inline char gc(){
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob)&&(ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob)?EOF:*ib++;
}
inline int read(){
    char ch=gc();
    int res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
    return f?res:-res;
}
inline ll readll(){
    char ch=gc();
    ll res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
    return f?res:-res;
}
inline int readstring(char *s){
	int top=0;char ch=gc();
	while(isspace(ch))ch=gc();
	while(!isspace(ch)&&ch!=EOF)s[++top]=ch,ch=gc();
	return top;
}
template<typename tp>inline void chemx(tp &a,tp b){a<b?a=b:0;}
template<typename tp>inline void chemn(tp &a,tp b){a>b?a=b:0;}
cs int mod=998244353;
inline int add(int a,int b){return (a+=b)>=mod?(a-mod):a;}
inline int dec(int a,int b){a-=b;return a+(a>>31&mod);}
inline int mul(int a,int b){static ll r;r=1ll*a*b;return (r>=mod)?(r%mod):r;}
inline void Add(int &a,int b){(a+=b)>=mod?(a-=mod):0;}
inline void Dec(int &a,int b){a-=b,a+=a>>31&mod;}
inline void Mul(int &a,int b){static ll r;r=1ll*a*b;a=(r>=mod)?(r%mod):r;}
inline int ksm(int a,int b,int res=1){for(;b;b>>=1,Mul(a,a))(b&1)&&(Mul(res,a),1);return res;}
inline int Inv(int x){return ksm(x,mod-2);}
inline int fix(int x){return (x<0)?x+mod:x;}
cs int N=400005;
int fac[N],ifac[N];
typedef vector<int> poly;
inline void init_inv(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<N;i++)fac[i]=mul(fac[i-1],i);
	ifac[N-1]=Inv(fac[N-1]);
	for(int i=N-2;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
inline int c(int n,int m){return n<m?0:mul(fac[n],mul(ifac[m],ifac[n-m]));}
namespace Poly{
	cs int C=19,M=(1<<C)|5,G=3;
	int *w[C+1],rev[M],inv[M];
	inline void init_rev(int lim){
		for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
	}
	inline void init_w(){
		for(int i=1;i<=C;i++)w[i]=new int[(1<<(i-1))|1];
		int wn=ksm(G,(mod-1)/(1<<C));w[C][0]=1;
		for(int i=1,l=(1<<(C-1));i<l;i++)w[C][i]=mul(w[C][i-1],wn);
		for(int i=C-1;i;i--)
		for(int j=0,l=1<<(i-1);j<l;j++)w[i][j]=w[i+1][j<<1];
		inv[0]=inv[1]=1;
		for(int i=2;i<M;i++)inv[i]=mul(mod-mod/i,inv[mod%i]);
	}
	inline void ntt(int *f,int lim,int kd){
		for(int i=0;i<lim;i++)if(i>rev[i])swap(f[i],f[rev[i]]);
		for(int mid=1,l=1,a0,a1;mid<lim;mid<<=1,l++)
		for(int i=0;i<lim;i+=mid<<1)
		for(int j=0;j<mid;j++)
		a0=f[i+j],a1=mul(w[l][j],f[i+j+mid]),f[i+j]=add(a0,a1),f[i+j+mid]=dec(a0,a1);
		if(kd==-1){
			reverse(f+1,f+lim);
			for(int i=0;i<lim;i++)Mul(f[i],inv[lim]);
		}
	}
	inline poly operator *(poly a,poly b){
		int deg=a.size()+b.size()-1;
		if(a.size()<=12||b.size()<=12){
			poly c(deg,0);
			for(int i=0;i<a.size();i++)
			for(int j=0;j<b.size();j++)
			Add(c[i+j],mul(a[i],b[j]));
			return c;
		}
		int lim=1;while(lim<deg)lim<<=1;
		init_rev(lim);
		a.resize(lim),ntt(&a[0],lim,1);
		b.resize(lim),ntt(&b[0],lim,1);
		for(int i=0;i<lim;i++)Mul(a[i],b[i]);
		ntt(&a[0],lim,-1),a.resize(deg);
		return a;
	}
	inline poly Inv(poly a,int deg){
		poly b(1,::Inv(a[0])),c;
		for(int lim=4;lim<(deg<<2);lim<<=1){
			c.resize(lim>>1);
			for(int i=0;i<(lim>>1);i++)c[i]=(i<a.size()?a[i]:0);
			init_rev(lim);
			b.resize(lim),ntt(&b[0],lim,1);
			c.resize(lim),ntt(&c[0],lim,1);
			for(int i=0;i<lim;i++)Mul(b[i],dec(2,mul(b[i],c[i])));
			ntt(&b[0],lim,-1),b.resize(lim>>1);
		}b.resize(deg);return b;
	}
	inline poly deriv(poly a){
		for(int i=0;i+1<a.size();i++)a[i]=mul(a[i+1],i+1);
		a.pop_back();return a;
	}
	inline poly integ(poly a){
		a.pb(0);
		for(int i=a.size()-1;i;i--)a[i]=mul(a[i-1],inv[i]);
		a[0]=0;return a;
	}
	inline poly Ln(poly a,int deg){
		a=integ(Inv(a,deg)*deriv(a)),a.resize(deg);return a;
	}
	inline poly Exp(poly a,int deg){
		poly b(1,1),c;
		for(int lim=2;lim<(deg<<1);lim<<=1){
			c=Ln(b,lim);
			for(int i=0;i<lim;i++)c[i]=dec(i<a.size()?a[i]:0,c[i]);
			Add(c[0],1),b=b*c,b.resize(lim);
		}b.resize(deg);return b;
	}
}
using namespace Poly;
int n,m;
poly S,P;
inline void calc_S(){
	poly a(n+1),b(n+1);
	for(int i=0;i<=n;i++){
		a[i]=(i&1)?mod-ifac[i]:ifac[i],b[i]=mul(ksm(i,n),ifac[i]);
	}
	S=a*b;
}
inline void calc_P(){
	P.resize(n+1);
	for(int i=1;i<=m;i++)
	for(int j=1;i*j<=n;j++)
	Add(P[i*j],inv[j]);
	P=Exp(P,n+1);
}
int main(){
	init_inv(),init_w();
	n=read(),m=read();
	calc_S(),calc_P();

    // 1
	cout<<ksm(m,n)<<'\n';
	// 2
	int res=1;
	for(int i=0;i<n;i++)Mul(res,m-i);
	cout<<res<<'\n';
	// 3
	cout<<mul(fac[m],n<m?0:S[m])<<'\n';
	//4
	res=0;
	for(int i=0;i<=m&&i<=n;i++)Add(res,S[i]);
	cout<<res<<'\n';
	//5
	cout<<(n<=m)<<'\n';
	//6
	cout<<(n<m?0:S[m])<<'\n';
	//7
	cout<<c(n+m-1,m-1)<<'\n';
	//8
	cout<<c(m,n)<<'\n';
	//9
	cout<<c(n-1,m-1)<<'\n';
	//10
	cout<<P[n]<<'\n';
	//11
	cout<<(n<=m)<<'\n';
	//12
	cout<<(n<m?0:P[n-m])<<'\n';
}
