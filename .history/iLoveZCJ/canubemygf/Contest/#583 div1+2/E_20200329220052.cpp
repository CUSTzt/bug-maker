#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100000001];
bool flag[100000001];
bool dfs(int x, int y) {
    if (x >= n || y >= m || s[x * m + y] == '#' || flag[x * m + y]) return 0;
    if (x == n - 1 && y == m - 1) return 1;
    if (x != 0 || y != 0) flag[x * m + y] = 1;
    return dfs(x + 1, y) || dfs(x, y + 1);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s + i * m);
    int k1 = dfs(0, 0);
    for (int i = 0; i < n * m; i++) {
        cout << flag[i];
        if (i % m == m - 1) cout << endl;
    }
    cout << "----next --- \n";
    if(!k1)
        {
                printf("0\n");
                return 0;
        }*/
    if (!dfs(0, 0)) {
        printf("1\n");
        return 0;
    }
    printf("2\n");
    return 0;
}
