#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cctype>
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
using namespace std;

inline char gc() {
//  static char buf[100000],*p1,*p2;
//  return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    return getchar();
}

template<class T>
int read(T &ans) {
    ans=0;char ch=gc();T f=1;
    while(!isdigit(ch)) {
        if(ch==EOF) return -1;
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch))
        ans=ans*10+ch-'0',ch=gc();
    ans*=f;return 1;
}

template<class T1,class T2>
int read(T1 &a,T2 &b) {
    return read(a)!=EOF&&read(b)!=EOF?2:EOF;
}

template<class T1,class T2,class T3>
int read(T1 &a,T2 &b,T3 &c) {
    return read(a,b)!=EOF&&read(c)!=EOF?3:EOF;
}

typedef long long ll;
const int Maxn=11000;
const int inf=0x3f3f3f3f;
const int mod=1000000007;

int n;
double f[Maxn],p;

signed main() {
//  freopen("test.in","r",stdin);
    read(n);
    f[0]=1;
    for(int i=1;i<=n;i++) {
        scanf("%lf",&p);
        for(int j=i;j>=1;j--) f[j]=(f[j]*(1.0-p)+f[j-1]*p);
        f[0]*=1.0-p;
    }
    for(int i = 1; i <= n; i++)[
        printf("%.6f\n",dp[i]);
    ]
    double ans=0;
    for(int i=n/2+1;i<=n;i++) ans+=f[i];
    printf("%.10lf",ans);
    return 0;
}