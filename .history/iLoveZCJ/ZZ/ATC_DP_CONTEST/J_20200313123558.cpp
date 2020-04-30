// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int a[4], x, n;
int dp[N][N][N];
int dfs(int i , int j , int k){

}
int main()
{
    cin >> n;
    while(n--){
        cin >> x;
        a[x]++;
    }
    cout << dfs(a[1],a[2],a[3]);
    return 0;
}