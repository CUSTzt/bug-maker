// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int s[N], c[N], m[N];
vector<int> v[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> m[i], s[m[i]]++;
    sort(m, m + n);
    int ans = 0;
    for (int i = 1; i <= k; i++) cin >> c[i];
    for(int i = k-1; i>=1;i--){
        s[i]+=s[i+1];
    }
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans = max(ans, (s[i]-1)/c[i]+1);
    }
    for(int i = 0, j =0; j < n;i=(i+1)%ans, j++){
        v[i].pb(m[j]);
    }
    cout << ans << endl;
    fpr(int i = 0; i < ans ; i++){
        cout << 
    }
    return 0;
}