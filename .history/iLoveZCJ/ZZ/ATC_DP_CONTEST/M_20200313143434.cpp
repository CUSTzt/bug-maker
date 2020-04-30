// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e3+100;
ll dp[N][N];
int a[N], n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i ; j <= n; j++){
            int l = j - i + 1, r = j;
            dp[l][r] = 
        }
    }
    return 0;
}