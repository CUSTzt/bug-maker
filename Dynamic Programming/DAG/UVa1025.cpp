//others 
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int N,T,M1,M2,t[51],dp[201][51],num;
bool has_train[401][51][2];
void get(int &x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
}
int main()
{
    while(1){
        memset(has_train,0,sizeof has_train);
        memset(dp,0,sizeof dp);
        get(N);if(!N) return 0;get(T);
        for(int i=1;i<N;i++)
            get(t[i]);
        get(M1);
        for(int i=1;i<=M1;i++){
            int a;get(a);
            for(int j=1;j<=N;j++){
                has_train[a][j][0]=1;//这一时间点有往右开的火车
                a+=t[j];//累加火车行驶的时间
            }
        }
        get(M2);
        for(int i=1;i<=M2;i++){
            int a;get(a);
            for(int j=N;j>0;j--){
                has_train[a][j][1]=1;//这一时间点有往左开的火车
                a+=t[j-1];//累加火车行驶时间
            }
        }
        for(int i=1;i<=N-1;i++)
            dp[T][i]=INF;
        dp[T][N]=0;
        for(int i=T-1;i>=0;i--)
            for(int j=1;j<=N;j++){
                dp[i][j]=dp[i+1][j]+1;//等待一个单位
                if(j<N&&has_train[i][j][0]&&i+t[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);//向右开
                if(j>1&&has_train[i][j][1]&&i+t[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);//向左开
            }
        printf("Case Number %d: ",++num);
        if(dp[0][1]>=INF) puts("impossible");//无解
        else printf("%d\n",dp[0][1]);
    }
}