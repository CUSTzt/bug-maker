#include<cstdio>
#define For(i,A,B) for(i=(A);i<=(B);++i)
const int N=500050;
const short S=750;
const int BUF=1<<23;
char rB[BUF],*rS,*rT,wB[BUF+50],*wT=wB;
inline char gc(){return rS==rT&&(rT=(rS=rB)+fread(rB,1,BUF,stdin),rS==rT)?EOF:*rS++;}
inline void flush(){fwrite(wB,1,wT-wB,stdout);wT=wB;}
inline int rd(){
    char c=gc();
    while(c<48||c>57)c=gc();
    int x=c&15;
    for(c=gc();c>=48&&c<=57;c=gc())x=x*10+(c&15);
    return x;
}
short buf[15];
inline void wt(int x){
    short l=-1;
    if(wT-wB>BUF)flush();
    while(x>9){
        buf[++l]=x%10;
        x/=10;
    }
    *wT++=x|48;
    while(l>=0)*wT++=buf[l--]|48;
    *wT++='\n';
}
int a[N],opt[N],ql[N],qr[N],qx[N],ps[S+5],st[N+S],sl=-1,s[N],mxn,decv;
//st 用于记录历史上的非空链表（也就是重构时要清空的链表），它的大小和插入与合并的总次数等规模
//注意 mxn 保存的是真实的最大值
short nxt[S+5],bg[N],ed[N],cnt[N];
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
inline short bel(int x){return (x-1)/S+1;}
inline void ins(int x,short p){
    if(!bg[x]){
        st[++sl]=x;
        bg[x]=ed[x]=p;
        cnt[x]=1;
    }else{
        nxt[ed[x]]=p;
        ed[x]=p;
        ++cnt[x];
    }
}
inline void merg(int x,int y){
    if(!bg[x]){
        st[++sl]=x;
        bg[x]=bg[y];ed[x]=ed[y];
        cnt[x]=cnt[y];
    }else{
        nxt[ed[x]]=bg[y];
        ed[x]=ed[y];
        cnt[x]+=cnt[y];
    }
    bg[y]=ed[y]=cnt[y]=0;
}
inline void clr(int x){
    for(short i=bg[x],t=nxt[i];i;t=nxt[i=t]){
        a[ps[i]]=x-decv;
        nxt[i]=0;
    }
    bg[x]=ed[x]=cnt[x]=0;
}
inline void build(int L,int R){  //重构
    int i;
    mxn=0;
    For(i,L,R){
        ins(a[i],i-L+1);
        mxn=Max(mxn,a[i]);
    }
}
inline void back(){  //拆链表
    while(sl>=0){clr(st[sl--]);}
    decv=0;
}
int main(){
    int n=rd(),m=rd(),q=0,i,j,L,R;
    short k,t,tot=bel(n);
    For(i,1,n)a[i]=rd();
    For(i,1,m){
        opt[i]=rd();ql[i]=rd();qr[i]=rd();qx[i]=rd();
        opt[i]=opt[i]==1?0:++q;
    }
    For(k,1,tot){
        L=(int)(k-1)*S+1;R=Min((int)k*S,n);
        For(i,L,R)ps[i-L+1]=i;
        build(L,R);
        For(i,1,m){
            if(ql[i]>R||qr[i]<L||mxn<qx[i])continue;
            if(opt[i])if(bel(ql[i])==k||bel(qr[i])==k)for(t=bg[qx[i]+decv];t;t=nxt[t])if(ps[t]>=ql[i]&&ps[t]<=qr[i])++s[opt[i]];  //块内查询
            else;
            else s[opt[i]]+=cnt[qx[i]+decv];  //整块查询
            else if(bel(ql[i])==k||bel(qr[i])==k){  //块内修改
                back();
                For(j,Max(L,ql[i]),Min(R,qr[i]))if(a[j]>qx[i])a[j]-=qx[i];
                build(L,R);
            }else if(mxn<=qx[i]*2){
                For(j,qx[i]+decv+1,mxn+decv)if(bg[j])merg(j-qx[i],j);
                mxn=qx[i];  //其实 mxn 不一定是 qx[i]，但是只要它和值域一起缩小就不会影响复杂度
            }else{
                For(j,1+decv,qx[i]+decv)if(bg[j])merg(j+qx[i],j);
                decv+=qx[i];
                mxn-=qx[i];
            }
//整块修改，两类情况如上所述
        }
        back();
    }
    For(i,1,q)wt(s[i]);
    flush();
    return 0;
}