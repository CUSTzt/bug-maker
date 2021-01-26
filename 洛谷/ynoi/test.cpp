// {{{ Template
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
 
typedef std::vector <int> poly;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define rez resize
#define mkp std::make_pair
#define pii std::pair <int,int>
#define lep(i,l,r) for(int i=l;i<=r;++i)
#define rep(i,r,l) for(int i=r;i>=l;--i)
#define CLEAR(x) memset((x),0,sizeof((x)))
#define COPY(x,y) memcpy((x),(y),sizeof(x))
 
const int inf=1e9+7;
const int mod=1e9+7;
 
namespace __________ {
	namespace _in {
		template <class T> inline T read() {
			char ch;bool flag=0;T x=0;
			while(ch=getchar(),!isdigit(ch)) if(ch=='-') flag=1;
			while(isdigit(ch)) x=x*10+ch-48,ch=getchar();
			return flag?-x:x;
		}
		struct {
			inline operator ll() {return read<ll>();}
			inline operator int() {return read<int>();}
			inline operator bool() {return read<bool>();}
			template <class T> inline void operator() (T &x) {x=*this;}
			template <class T,class ...A> inline void operator() (T &x,A &...a)
			{x=*this,this->operator()(a...);}
		} IN;
	}
	namespace _std {
		template <class T> inline T abs(T x) {if(x<0) x=-x;return x;}
		template <class T> inline T max(T x,T y) {if(x<y) x=y;return x;}
		template <class T> inline T min(T x,T y) {if(x>y) x=y;return x;}
		template <class T> inline void swap(T &x,T &y) {x^=y^=x^=y;}
		template <class T> inline void chkmax(T&x,T y) {if(x<y) x=y;}
		template <class T> inline void chkmin(T&x,T y) {if(x>y) x=y;}
	}
	namespace _mod {
		inline int mul(int x,int y) {return 1ll*x*y%mod;}
		inline int dec(int x,int y) {x-=y;if(x<0) x+=mod;return x;}
		inline int add(int x,int y) {x+=y;if(x>=mod) x-=mod;return x;}
		inline void pls(int&x,int y) {x+=y;if(x>=mod) x-=mod;}
		inline void sub(int&x,int y) {x-=y;if(x<0) x+=mod;}
		inline int modpow(int x,int y,int res=1) {
			if(y==-1) y=mod-2;
			for(;y;y>>=1,x=mul(x,x)) if(y&1) res=mul(res,x);
			return res;
		}
	} 
	
	using namespace _in;
	using namespace _std;
	using namespace _mod;
} using namespace __________;
// }}}
#define lep(i,l,r) for(int i=l;i<=r;++i)
#define rep(i,r,l) for(int i=r;i>=l;--i)
#define CLEAR(x) memset((x),0,sizeof((x)))
#define COPY(x,y) memcpy((x),(y),sizeof(x))
// 1 l r x y把区间 [l,r] 内所有的 x 变成 y。
// 2 l r k 查询区间 [l,r] 内第 k 小值。
const int N=1e5+5;
const int S=5e2+5;
const int M=1e5;
int n,m,x,y,a[N];
// {{{ Data_Struct_Block
int sqrtn,L[S],R[S],id[N],mi[S],mx[S],blo[N];
int sum[S][S],cnt[N][S],tmp_sum[S],tmp_cnt[N];
// {{{ Data_Struct_Dsu
int rt[S][N],col[N],fa[N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
inline void merge(const int &t) {
    if(!rt[t][x]) return ;
    if(!rt[t][y]) rt[t][y]=rt[t][x],col[rt[t][y]]=y;
    else fa[rt[t][x]]=rt[t][y];
    rt[t][x]=0;
}
inline void rebuild(const int &t,int l,int r) {
    lep(i,L[t],R[t]) a[i]=col[find(i)],rt[t][a[i]]=0;
    lep(i,l,r) if(a[i]==x) a[i]=y;
    lep(i,L[t],R[t]) {
        if(!rt[t][a[i]]) col[rt[t][a[i]]=i]=a[i];
        fa[i]=rt[t][a[i]];
    }
}
// }}}
inline void init() {
    sqrtn=sqrt(n*3/5+1);
    for(int i=1,c=1,j;i<=n;i=j+1,++c) { // seq_block
        L[c]=i,R[c]=j=min(n,i+sqrtn-1);
        lep(t,L[c],R[c]) id[t]=c;
    }
    for(int i=1,c=1,j;i<=M;i=j+1,++c) { // num_block
        mi[c]=i,mx[c]=j=min(M,i+315);
        lep(t,mi[c],mx[c]) blo[t]=c;
    }
    lep(c,1,id[n]) { // cnt & sum
        COPY(sum[c],sum[c-1]);
        lep(i,1,M) cnt[i][c]=cnt[i][c-1];
        lep(i,L[c],R[c]) ++cnt[a[i]][c],++sum[c][blo[a[i]]];
    }
    lep(c,1,id[n]) lep(i,L[c],R[c]) { // dsu
        if(!rt[c][a[i]]) col[rt[c][a[i]]=i]=a[i];
        fa[i]=rt[c][a[i]];
    }
}
inline void modify(int l,int r) {
    if(x==y) return ;
    int res=0,tmp=0,v1=0,v2=0;
    #define upd1 (sum[i][blo[x]]-=res,sum[i][blo[y]]+=res)
    #define upd2 (cnt[x][i]-=res,cnt[y][i]+=res)

    if(id[l]==id[r]) {
        lep(i,l,r) if(col[find(i)]==x) ++res;
        if(!res) return ;
        lep(i,id[r],id[n]) upd1,upd2;
        rebuild(id[l],l,r);
    } else {
        lep(i,l,R[id[l]]) if(col[find(i)]==x) ++res,++v1;
        lep(i,id[l],id[r]-1) res+=tmp,upd1,tmp=cnt[x][i+1]-cnt[x][i],upd2;
        lep(i,L[id[r]],r) if(col[find(i)]==x) ++res,++v2;
        lep(i,id[r],id[n]) upd1,upd2;

        lep(i,id[l]+1,id[r]-1) merge(i);
        if(v1) rebuild(id[l],l,R[id[l]]);
        if(v2) rebuild(id[r],L[id[r]],r);
    }
}
inline void query(int l,int r) {
    int tmp;
    const bool _=(id[l]!=id[r]);
    #define add (tmp=col[find(i)],++tmp_cnt[tmp],++tmp_sum[blo[tmp]])
    #define del (tmp=col[find(i)],--tmp_cnt[tmp],--tmp_sum[blo[tmp]])
    if(_) {lep(i,l,R[id[l]]) add; lep(i,L[id[r]],r) add;}
    else lep(i,l,r) add;
    int res=0,ans=-1;
    lep(t,1,blo[M]) {
        int now=tmp_sum[t]+sum[id[r]-_][t]-sum[id[l]][t];
        if(res+now>=x) lep(i,mi[t],mx[t]) {
            res+=tmp_cnt[i]+cnt[i][id[r]-_]-cnt[i][id[l]];
            if(res>=x) {ans=i; break;}
        }
        if(~ans) break; res+=now;
    }
    printf("%d\n",ans);
    if(_) {lep(i,l,R[id[l]]) del; lep(i,L[id[r]],r) del;}
    else lep(i,l,r) del;
}
// }}}
int op,l,r;
int main() {
    IN(n,m);
    lep(i,1,n) IN(a[i]);
    init();
    while(m--) {
        IN(op,l,r);
        if(op==1) IN(x,y),modify(l,r);
        if(op==2) IN(x),query(l,r);
    }
    return 0;
}