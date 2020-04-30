// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e3 + 100;
int fa[N], n, m, deg[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unit(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
}
void init() {
    for (int i = 0; i < n + 3; i++) {
        fa[i] = i;
        deg[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        if (!n) break;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            deg[x]++, deg[y]++;
            unit(x, y);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) cnt++;
        }
        if(cnt > 1){
            cout << "0\n";;
            continue;
        }
        int fl = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i]&1){fl = 1;}
        }
        if(fl){
            cout <<"0\n";
            continue;
        }cout << 1 << endl;
    }
    return 0;
}