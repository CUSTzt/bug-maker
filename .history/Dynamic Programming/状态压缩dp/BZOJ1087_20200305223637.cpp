// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , k;
ll dp[15][15][]
//dp[i][j][k]为前i行已经放了j个国王并且第i行的状态为k（二进制）的方案数，
//那么dp[i][j][k] = Σdp[i-1][j - num[k]][p],
//其中num数组记录着一行为状态k的放的国王的数目，p为上一行符合要求的状态.
int main()
{
    
    return 0;
}