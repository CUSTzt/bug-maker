#include<bits/stdc++.h>
using namespace std;
const int maxn = 30000 + 10;
int fa[maxn], dis[maxn], size[maxn];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 0; fa[i] = i; size[i] = 1;
    }
}
int Find(int x) {
    if (x == fa[x]) return x;
    int root = Find(fa[x]);
    dis[x] += dis[fa[x]];
    return fa[x] = root;
}
void merge(int x, int y) {
    x = Find(x), y = Find(y);
    fa[x] = y; dis[x] = size[y]; size[y] += size[x];
}
int main() {
    int t;
    init(30000);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        char op; int x, y;
        cin >> op >> x >> y;
        if (op == 'M') {
            merge(x, y);
        } else {
            int fx = Find(x), fy = Find(y);
            if (fx != fy)
                cout << -1 << "\n";
            else
                cout << abs(dis[x] - dis[y]) - 1 << "\n";
        }
    }
    return 0;
}