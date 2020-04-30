#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;
int dp[105][105],p[105];//dp[i][j]表示从第i个矩阵到第j个矩阵相乘的最少次数是dp[i][j]
int main()
{
    int n;//n个矩阵相乘
    cin>>n;
    for(int i=0;i<n;i++)//输入矩阵的行数和列数
        cin>>p[i]>>p[i+1];
    memset(dp,0,sizeof(dp));
    for(int len=2;len<=n;len++)//区间长度
    {
        for(int i=1;i<=n;i++)//起始位置
        {
            int cnt=99999999;
            int j=i+len-1;//结束位置
            if(j>n)
                break;
            for(int k=i;k<j;k++)//分割点k
                cnt=min(cnt,dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            dp[i][j]=cnt;
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}