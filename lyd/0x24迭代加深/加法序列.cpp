#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, depmax;
bool vis[205], flag;
int d[205];
void dfs(int x, int lst) {
    if (x > depmax) {
        if (d[depmax] == n) flag = true;
        return;
    }
    for (int i = lst; i < x; i++) {
        for (int j = 1; j <= i; j++) {
            d[x] = d[i] + d[j];
            dfs(x + 1, i + 1);
            if (flag) return;
            d[x] = 0;
        }
    }
}
int main() {
    while (~scanf("%d", &n) && n) {
        depmax = 1;
        memset(vis, 0, sizeof(vis));
        flag = false;
        d[1] = 1;
        for (; !flag; depmax++) dfs(2, 1);
        for (int i = 1; i < depmax; i++) printf("%d ", d[i]);
        puts("");
    }
    return 0;
}