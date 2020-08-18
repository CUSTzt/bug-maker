/*
Author: QAQAutomaton
Lang: C++
Code: seg.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n' || x=='\r');
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
int a[200005],nt;
struct smt{
	int ls,rs;
	smt *l,*r;
	int mx,se;
	int mxc;
	int mxt,nmxt;
	int mxht,nmxht;
	int mxmt,nmxmt;
	int sum,hsum,hmx;
	void push_up(){
		sum=l->sum+r->sum;
		hsum=l->hsum+r->hsum;
		hmx=max(l->hmx,r->hmx);
		mx=max(l->mx,r->mx);
		se=-inf;mxc=0;
		if(l->mx==mx){chkmax(se,l->se);mxc+=l->mxc;}else chkmax(se,l->mx);
		if(r->mx==mx){chkmax(se,r->se);mxc+=r->mxc;}else chkmax(se,r->mx);
	}
	smt(int la,int ra){
		ls=la;rs=ra;
		mxt=nmxt=mxht=nmxht=0;
		mxmt=nmxmt=-inf;
		hsum=0;
		if(ls==rs){
			mx=a[ls];
			se=-inf;
			mxc=1;
			sum=a[ls];
			hmx=a[ls];
			l=r=0;
			return;
		}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
		push_up();
	}
	void put_nmxt(int t,int ht,int mt){
		chkmax(nmxmt,nmxt+mt);
		nmxt+=t;
		nmxht+=ht;
		se+=t;
		sum+=t*(rs-ls+1-mxc);
		hsum-=ht*(rs-ls+1-mxc);
	}
	void put_mxt(int t,int ht,int mt){
		chkmax(mxmt,mxt+mt);
		chkmax(hmx,mx+mt);
		mxt+=t;
		mxht+=ht;
		mx+=t;
		sum+=t*mxc;
		hsum-=ht*mxc;
	}
	void push_down(){
		l->put_nmxt(nmxt,nmxht,nmxmt);
		r->put_nmxt(nmxt,nmxht,nmxmt);
		if(mx-mxt==l->mx)l->put_mxt(mxt,mxht,mxmt);
		else l->put_mxt(nmxt,nmxht,nmxmt);
		if(mx-mxt==r->mx)r->put_mxt(mxt,mxht,mxmt);
		else r->put_mxt(nmxt,nmxht,nmxmt);
		mxt=mxht=0;
		nmxt=nmxht=0;
		mxmt=nmxmt=-inf;
	}
	void add(int la,int ra,int x){
		if(la<=ls && rs<=ra){
			put_mxt(x,nt*x,x);
			put_nmxt(x,nt*x,x);
			return;
		}
		push_down();
		if(la<=l->rs)l->add(la,ra,x);
		if(r->ls<=ra)r->add(la,ra,x);
		push_up();
	}
	void ckmn(int la,int ra,int x){
		if(mx<=x)return;
		if(la<=ls && rs<=ra){
			if(se<x){
				put_mxt(x-mx,nt*(x-mx),x-mx);
				return;
			}
		}
		push_down();
		if(la<=l->rs)l->ckmn(la,ra,x);
		if(r->ls<=ra)r->ckmn(la,ra,x);
		push_up();
	}
	void qsum(int la,int ra,int &ans){
		if(la<=ls && rs<=ra){
			ans+=sum;return;
		}
		push_down();
		if(la<=l->rs)l->qsum(la,ra,ans);
		if(r->ls<=ra)r->qsum(la,ra,ans);
	}
	void qhsum(int la,int ra,int &ans){
		if(la<=ls && rs<=ra){
			ans+=sum*nt+hsum;return;
		}
		push_down();
		if(la<=l->rs)l->qhsum(la,ra,ans);
		if(r->ls<=ra)r->qhsum(la,ra,ans);
	}
	void qhmax(int la,int ra,int &ans){
		if(la<=ls && rs<=ra){chkmax(ans,hmx);return;}
		push_down();
		if(la<=l->rs)l->qhmax(la,ra,ans);
		if(r->ls<=ra)r->qhmax(la,ra,ans);
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	rt=new smt(1,n);
	for(;q;--q){
		int tp,l,r,x;	
		read(tp,l,r);
		if(tp==1){
			read(x);
			rt->ckmn(l,r,x);
			++nt;
		}
		else if(tp==2){
			read(x);
			rt->add(l,r,x);
			++nt;
		}
		else if(tp==3){
			int x=0;
			rt->qsum(l,r,x);
			write(x,'\n');
		}
		else if(tp==4){
			int x=0;
			rt->qhsum(l,r,x);
			write(x,'\n');
		}
		else{
			int x=-inf;
			rt->qhmax(l,r,x);
			write(x,'\n');
		}
	}
	return 0;
}