#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxlogn=18;
const int maxn=(1<<maxlogn)|1;
const int G0=15311432;
const int kcz=998244353;
int n,rev[maxn];
ll G[2][24],f[maxn],g[maxn],a[maxn],b[maxn];
void gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b) x=1,y=0;
    else gcd(b,a%b,y,x),y-=x*(a/b);
}
inline ll inv(ll a)
{
    ll x,y;
    gcd(a,kcz,x,y);
    return (x+kcz)%kcz;
}
inline void calcrev(int logn)
{
    register int i;
    rev[0]=0;
    for(i=1;i<(1<<logn);i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(logn-1));
}
inline void FFT(ll *a,int logn,int flag)
{
    register int i,j,k,mid;
    register ll t1,t2,t;
    for(i=0;i<(1<<logn);i++)
        if(rev[i]<i)
            swap(a[rev[i]],a[i]);
    for(i=1;i<=logn;i++)
        for(mid=1<<(i-1),j=0;j<(1<<logn);j+=1<<i)
            for(k=0,t=1;k<mid;k++,t=t*G[flag][i]%kcz)
            {
                t1=a[j|k],t2=t*a[j|k|mid];
                a[j|k]=(t1+t2)%kcz,a[j|k|mid]=(t1-t2)%kcz;
            }
}
void solve(int l,int r,int logn)
{
    if(logn<=0) return;
    if(l>=n) return;
    int mid=(l+r)>>1,i;
    ll t=inv(r-l);
    solve(l,mid,logn-1); // 计算左区间
    calcrev(logn);
    memset(a+(r-l)/2,0,sizeof(ll)*(r-l)/2); // 拷贝左区间
    memcpy(a,f+l,sizeof(ll)*(r-l)/2); // 填充0
    memcpy(b,g,sizeof(ll)*(r-l)); // 拷贝g
    FFT(a,logn,0),FFT(b,logn,0); // 卷积
    for(i=0;i<r-l;i++) a[i]=a[i]*b[i]%kcz;
    FFT(a,logn,1);
    for(i=0;i<r-l;i++) a[i]=a[i]*t%kcz;
    for(i=(r-l)/2;i<r-l;i++)
        f[l+i]=(f[l+i]+a[i])%kcz; // 把卷积后的右半段的数加到f数组后半段
    // 可能你会注意到，这个卷积是(r-l)/2的长度卷一个r-l的长度，而我卷积时最终结果当作r-l的长度来存，这会不会有影响？注意到超出部分是(r-l)/2左右，根据fft的实现，超出部分是会重新从0开始填的，所以只会影响结果的前半段，与后半段无关
    solve(mid,r,logn-1); // 计算右区间
}
int main()
{
    int logn,i;
    G[1][23]=inv(G[0][23]=G0);
    for(i=22;i>=0;i--)
    {
        G[0][i]=G[0][i+1]*G[0][i+1]%kcz;
        G[1][i]=G[1][i+1]*G[1][i+1]%kcz;
    }
    scanf("%d",&n);
    for(logn=0;(1<<logn)<n;logn++);
    for(i=1;i<n;i++) scanf("%lld",&g[i]);
    for(i=0;i<n;i++) f[i]=!i;
    solve(0,1<<logn,logn);
    for(i=0;i<n;i++)
        printf("%lld ",(f[i]+kcz)%kcz);
    printf("\n");
    return 0;
}