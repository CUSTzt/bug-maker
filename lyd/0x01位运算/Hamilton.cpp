/*
题目描述

给定一张 n(n≤20) 个点的带权无向图，点从 0~n-1 标号，求起点 0 到终点 n-1 的最短Hamilton路径。 Hamilton路径的定义是从
 0 到 n-1 不重不漏地经过每个点恰好一次。

输入

第一行一个整数n。
接下来n行每行n个整数，其中第i行第j个整数表示点i到j的距离（一个不超过10^7的正整数，记为a[i,j]）。
对于任意的x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]>=a[x,z]。

输出

一个整数，表示最短Hamilton路径的长度。
样例输入

4
0 2 1 3
2 0 2 1
1 2 0 1
3 1 1 0
样例输出

4
提示

从0到3的Hamilton路径有两条，0-1-2-3和0-2-1-3。前者的长度为2+2+1=5，后者的长度为1+2+1=4
*/
/*
题意

1为起点，n为终点的最短汉密顿路径。数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]>=a[x,z]

题解

用二进制上的数代表一个点的状态，取（1）或不取（0）。题目让求从点1到n的最短汉密顿路径，即经过每个点一次，这时的状态
用二进制表示就是 (1<<n)-1 （n个1）。用dp[i][j]表示在状态 i 下，从1到 j 的最短汉密顿路径。

dp[i][j]可由上一个状态（上一状态就是把 j从当前状态中去掉）dp[i^(1<<(j-1))][k]得到，其中保证k是中存在的点，即 (i>>k)&1。

表示 i 的第 k 位是1，即经过点 k。  注意是 i>>k 不是 i<<k

则状态转移方程为：dp[i][j]=min{dp[i^(1<<j)][k]+Map[k][j]}(k=1~n); 其含义就是枚举到达点j之前的前一个点k，取其最短；
*/

#include <bits/stdc++.h>

using namespace std;

int f[1<<20][20];
int hamilton(int n ,int weight[20][20])
{
    memset(f,0x3f,sizeof(f));
    f[1][0]=0;
    for(int i=1;i<1<<n;i++)
        for(int j=0;j<n;j++)if(i>>j&1)
            for(int k=0;k<n;k++)if((i^1<<j)>>k&1)
            f[i][j]=min(f[i][j],f[i^1<<j][k]+weight[k][j]);
    return f[(1<<n)-1][n-1];
}

int n;
int weight[20][20];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>weight[i][j];
    hamilton(n,weight);
    cout<<f[(1<<n)-1][n-1]<<endl;
}