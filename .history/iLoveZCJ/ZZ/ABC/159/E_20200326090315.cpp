// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// bitmask dp,bf
const int N = 1e3 + 100;
int a[15][N], sum[15][N], n, m, k, b[15];
char s[15][N];
int cnt;
int get(int l1, int r1, int l2, int r2) {
    return sum[l2][r2] - sum[l1 - 1][r2] - sum[l2][r1 - 1] +
           sum[l1 - 1][r1 - 1];
}
pair<int , int > pr[N];
int work() {
    int r1 = 1, r2 = 1, t = 0;
    for (int i = 1; i <= m; i++) {
        int fl = 1;
        for (int j = 1; j <= cnt && fl; j++) {
            if(get(pr[j].ff,r1,pr[j].ss,r2) <= k){
                continue;
            }else{
                fl = 0;
            }
        }
        if(!fl){
            if(r1== r2)return INT_MAX;
            t++;
            r1=
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            a[i][j] = s[i][j] - '0';
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    return 0;
}