#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 333;
int cnt[maxn][maxn],ans[maxn];
int fa[maxn];
bitset<maxn>b[maxn],tmp;
 
int Find(int x) {
    if(fa[x]==x) return fa[x];
    return fa[x]=Find(fa[x]);
}
 
void Union(int x,int y) {
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return ;
    if(fx>fy) swap(fx,fy);
    fa[fy]=fx;
 
}
 
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        int n,s;scanf("%d%d",&n,&s);
        for(int i=0;i<n;i++) fa[i]=i,b[i].reset();
        getchar();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                char ch;scanf("%c",&ch);
                int now=ch-'0';
                if(now==1) {
                    b[i].set(j);b[j].set(i);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                cnt[i][j]=cnt[j][i]=(b[i]&b[j]).count();
            }
        }
 
        for(int i=0;i<n;i++) {
            int mx=0;
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                mx=max(mx,cnt[i][j]);
            }
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                if(cnt[i][j]>2*mx/3) Union(i,j);
            }
        }
 
        int f=0;
        for(int i=0;i<n;i++) {
            if(Find(i)==i) ans[i]=f++;//,printf("i=%d\n",i);
            ans[i]=ans[Find(i)];
        }
        for(int i=0;i<n;i++) {
            printf("%d ",ans[Find(i)]);
        }
        printf("\n");
    }
    return 0;
}