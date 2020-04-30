// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n, a[N], use[N];
vector<int> v;
void dfs(int x) {
    use[x] = 1;
    v.pb(x);
    if (!use[a[x]]) dfs(a[x]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            use[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(!use[])
        }
    }
    return 0;
}