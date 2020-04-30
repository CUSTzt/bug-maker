// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 100;
int n, p, k;
int a[N], s[N][10];
vector<pair<int , int > >v;
ll dp[N][1<<7];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i],v.pb(mp(a[i],i));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];
    sort(v.begin(),v.end(),greater<pair<int , int > >());
    memset(dp , )
    return 0;
}