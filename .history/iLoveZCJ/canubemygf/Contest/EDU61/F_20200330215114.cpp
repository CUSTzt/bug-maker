// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1100;
int n;
char s[N];
ll dp[N][N];
int main() {
    cin >> n;
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++){
        for(int j = i ; j <= n; j++){
            if(i == j)dp[i][j] = 0;else dp[i][j] = n;
        }
    }
    return 0;
}