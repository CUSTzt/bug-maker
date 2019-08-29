#include <bits/stdc++.h>
#define forto(i,a,b) for(i=a;i<=b;i++)//循环宏定义，减小代码量
using namespace std;

int n,m,k,sum[20][20];
int f[16][226][16][16][2][2];
struct node{
    int l,r,x,y;
}pre[16][226][16][16][2][2];

void read_and_parse(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&sum[i][j]);
            sum[i][j]+=sum[i][j-1];
        }
}

int x,y,i,j,l,r,ans,ai,al,ar,ax,ay;//本题状态数较多，因此采用当前变量全局化，避免参数传递混乱

inline void update(int dat,int L,int R,int X,int Y){
    int& ans=f[i][j][l][r][x][y];//使用引用减小代码量
    node& p=pre[i][j][l][r][x][y];
    if(ans>=dat)return;
    ans=dat;
    p=(node){L,R,X,Y};
}

void print(int i,int j,int l,int r,int x,int y){
    if(!j)return;
    node& p=pre[i][j][l][r][x][y];
    print(i-1,j-(r-l+1),p.l,p.r,p.x,p.y);
    forto(j,l,r)printf("%d %d\n",i,j);
}

void solve(){
    forto(i,1,n)forto(j,1,k)forto(l,1,m)forto(r,l,m){
        int t=r-l+1;if(t>j)break;
        int now=sum[i][r]-sum[i][l-1];
        x=y=1;
        for(int p=l;p<=r;p++)
            for(int q=r;q<=m;q++){
                update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0);
                update(f[i-1][j-t][p][q][1][1]+now,p,q,1,1);
            }
        x=1,y=0;
        for(int p=l;p<=r;p++)
            for(int q=p;q<=r;q++)
                update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0);
        x=0,y=1;
        for(int p=1;p<=l;p++)
            for(int q=r;q<=m;q++){
                update(f[i-1][j-t][p][q][1][1]+now,p,q,1,1);
                update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0);
                update(f[i-1][j-t][p][q][0][1]+now,p,q,0,1);
                update(f[i-1][j-t][p][q][0][0]+now,p,q,0,0);
            }
        x=y=0;
        for(int p=1;p<=l;p++)
            for(int q=l;q<=r;q++){
                update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0);
                update(f[i-1][j-t][p][q][0][0]+now,p,q,0,0);
            }
    }
    forto(i,1,n)forto(l,1,m)forto(r,l,m)forto(x,0,1)forto(y,0,1)
        if(ans<f[i][k][l][r][x][y]){
            ans=f[i][k][l][r][x][y];
            ai=i,al=l,ar=r,ax=x,ay=y;
        }
    printf("Oil : %d\n",ans);
    print(ai,k,al,ar,ax,ay);//传入终点状态参数
}

int main(){
    read_and_parse();
    solve();
    return 0;
}