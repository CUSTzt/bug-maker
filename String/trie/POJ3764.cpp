#include <bits/stdc++.h>
using namespace std;
const int u = 100010;
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define fic(i, a, b) for (int i = a; i >= b; i--)
int ver[2 * u], edge[2 * u], Next[2 * u], head[u], v[u], val[u * 32],
    a[u * 32][2], f[u], trie[2 * u][31];
int n, tot, i, ans, x, y, z;
inline void add(int x, int y, int z)  //链式前项星
{
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
inline void dfs(int x) {
    v[x] = 1;
    for (int i = head[x]; i; i = Next[i])  //枚举x节点所有的路径
        if (!v[ver[i]]) {
            f[ver[i]] = f[x] ^ edge[i];
            dfs(ver[i]);
        }
}
void insert(int x, int y, int now) {
    if (y < 0) {
        val[x] = now;
        return;
    }
    int z = (now >> y) & 1;  //取出第y位
    if (!a[x][z]) a[x][z] = ++tot;
    insert(a[x][z], y - 1, now);
}

int Search(int x, int y, int now) {
    if (y < 0) return val[x];
    int z = (now >> y) & 1;  //取出第y位
    if (a[x][z ^ 1])
        return Search(a[x][z ^ 1], y - 1, now);
    else
        return Search(a[x][z], y - 1, now);
}
int main() {
    n = read();
    for (i = 1; i < n; i++) {
        x = read();y = read();z = read();x++;y++;
        add(x, y, z);add(y, x, z);
    }
    dfs(1);
    tot = 1;
    ans = 0;
    insert(1, 30, 0);
    for (i = 1; i <= n; i++) {
        ans = max(ans, f[i] ^ Search(1, 30, f[i]));  //选取最大值
        insert(1, 30, f[i]);
    }
    cout << ans << endl;
    return 0;
}
