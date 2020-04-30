// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 16;
int n , k , pre[1 << N];
double dp[110][1 << N];
//我们可以用dp[i][j]记录第i个回合，当前状态为j时能获得的最大收益。
//如果我们正着DP，那么显然可以发现，当我们要从一个状态转移至另一个状态时，
//有可能前一个状态无法得到，因此我们要倒着推。
int main()
{
    cin >> k >> n;
    
    return 0;
}