// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
struct rec {
    int x, y, z;
    friend int operator<(rec const &a, rec const &b) { return a.z < b.z; }
} edge[N];
ll fa[N], n, s[N], ans;
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for(int i = 1; i <= n; i++){
            fa[i] = i;s[i] = 1;
        }
        for(int i = 1; i < n; i++){
            cin >> edge[i].x >> edge[i].y >> edge[i].z;
        }
        sort(edge+1, edge+n);
        ans = 0;
        for(int i = 1; i < n; i++){
            int x = find(edge[i].x), y = find(edge[i].y);
            if(x == y) continue;
            ans += 1ll * (edge[i].z + 1) * (s[x]*s[y]-1);
            fa[x] = y;
            s[y]+=s[x];
        }
        cout << ans << endl;
    }
    return 0;
}