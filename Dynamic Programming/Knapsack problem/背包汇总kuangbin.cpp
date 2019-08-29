#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define endl "\n"
#define inf 0x3f3f3f3f
#define me(a,b) memset(a,b,sizeof(a))
int nValue,nKind;

int n,V;
int dp[1000+5];
//01背包
inline void ZeroOnePack(int v,int w) {
    for(int i=V; i>=v; i--)
        dp[i]=max(dp[i],dp[i-v]+w);
}
//完全背包
inline void CompletePack(int v,int w) {
    for(int i=v; i<=V; i++)
        dp[i]=max(dp[i],dp[i-v]+w);
}
//多重背包,二进制优化
inline void MultiplePack(int v,int w,int amount) {
    if(v*amount>=V)
        CompletePack(v,w);
    else {
        int k=1;
        while(k<amount) {
            ZeroOnePack(k*v,k*w);
            amount-=k;
            k<<=1;
        }
        ZeroOnePack(amount*v,amount*w);

    }
}
//单调队列优化，一般比二进制优化更快
pair<int,int> q[1005];
inline void pack(int f[], int V, int v, int amout, int w) {
    if (amout == 0 || v == 0)
        return;
    if (amout == 1) {               //01背包
        for (int i = V; i >= v; --i)
            if (f[i] < f[i - v] + w)
                f[i] = f[i - v] + w;
        return;
    }
    if (amout * v >= V - v + 1) {
        for (int i = v; i <= V; ++i)
            if (f[i] < f[i - v] + w)
                f[i] = f[i - v] + w;
        return;
    }
    for(int j=0;j<v;j++){
        int head=1,rear=1;
        for(int k=j,i=0;k<=V;k+=v,i++){
            int tt=f[k]-i*w;
            while(rear!=head&&q[rear].first<tt) --rear;
            q[++rear]=make_pair(tt,i);
            if(head!=rear&&(i-q[head+1].second)>n) ++head;
            f[k]=q[head+1].first+i*w;
        }
    }
}