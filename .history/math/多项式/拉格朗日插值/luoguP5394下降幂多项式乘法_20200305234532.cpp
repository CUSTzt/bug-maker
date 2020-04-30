#include<algorithm>
#include<cstdio>
#define mod 998244353
#define G 3
#define Maxn 200500
using namespace std;
int r[Maxn<<2];
long long invn,invG,fac[Maxn],inv[Maxn];
long long powM(long long a,long long t=mod-2)
{
  long long ans=1,buf=a;
  while(t){
    if(t&1)ans=(ans*buf)%mod;
    buf=(buf*buf)%mod;
    t>>=1;
  }return ans;
}
void NTT(long long *f,bool op,int n)
{
  for (int i=0;i<n;i++)
    if (r[i]<i)swap(f[r[i]],f[i]);
  for (int len=1;len<n;len<<=1){
    int w=powM(op==1 ? G:invG,(mod-1)/len/2);
    for (int p=0;p<n;p+=len+len){
      long long buf=1;
      for (int i=p;i<p+len;i++){
        int sav=f[i+len]*buf%mod;
        f[i+len]=f[i]-sav;
        if (f[i+len]<0)f[i+len]+=mod;
        f[i]=f[i]+sav;
        if (f[i]>=mod)f[i]-=mod;
        buf=buf*w%mod;
        }//F(x)=FL(x^2)+x*FR(x^2)
         //F(W^k)=FL(w^k)+W^k*FR(w^k)
         //F(W^{k+n/2})=FL(w^k)-W^k*FR(w^k)
    }
  }
}
void Init(int lim)
{
  inv[1]=inv[0]=fac[0]=1;
  for (int i=1;i<=lim;i++)fac[i]=fac[i-1]*i%mod;
  for (int i=2;i<=lim;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;
  for (int i=2;i<=lim;i++)inv[i]=inv[i-1]*inv[i]%mod;
}
long long s[Maxn<<2];
void FDT(long long *f,int n,bool op)
{
  if (op)
    for (int i=0;i<n;i++)s[i]=inv[i];
  else 
    for (int i=0;i<n;i++)
      if (i&1)s[i]=mod-inv[i];
      else s[i]=inv[i];
  int len=1;for (;len<n+n;len<<=1);
  for (int i=n;i<len;i++)s[i]=0;
  for (int i=0;i<len;i++)
    r[i]=(r[i>>1]>>1)|(i&1?len>>1:0);
  NTT(f,1,len);NTT(s,1,len);
  for (int i=0;i<len;i++)f[i]=f[i]*s[i]%mod;
  NTT(f,0,len);invn=powM(len);
  for (int i=0;i<n;i++)f[i]=f[i]*invn%mod;
  for (int i=n;i<len;i++)f[i]=0;
}
int n,m;
long long f[Maxn<<2],g[Maxn<<2];
int main()
{
  scanf("%d%d",&n,&m);
  invG=powM(G);
  n++;m++;
  for (int i=0;i<n;i++)scanf("%lld",&f[i]);
  for (int i=0;i<m;i++)scanf("%lld",&g[i]);
  int cnt=n+m-1;
  Init(cnt);
  FDT(f,cnt,1);FDT(g,cnt,1);
  for (int i=0;i<cnt;i++)
    f[i]=f[i]*g[i]%mod*fac[i]%mod;
  FDT(f,cnt,0);
  for (int i=0;i<cnt;i++)printf("%lld ",f[i]);
  return 0;
}