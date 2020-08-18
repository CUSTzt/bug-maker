#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int N = 200010;
const int T = 200010;
const int S = 2000010;
char s[S];
queue<int> q;
int head[T], nxt[T], to[T], cnt;
int n, tr[T][26], fail[T], tot = 1, match[N], siz[T];
void dfs(int u) {
    int i, v;
    for (i = head[u]; i; i = nxt[i]) {
        v = to[i];
        dfs(v);
        siz[u] += siz[v];
    }
}
void add(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
int main() {
    int i, j, u;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%s", s);
        for (u = 1, j = 0; s[j]; ++j) {
            int c = s[j] - 'a';
            if (!tr[u][c]) tr[u][c] = ++tot;
            u = tr[u][c];
        }
        match[i] = u;  // 记录每个模式串在 Trie 树上的终止节点
    }
    for (i = 0; i < 26; ++i)
        tr[0][i] = 1;  // 一种比较与众不同（个人认为比较正确）的 AC
                       // 自动机建法，详见上文提到的我写的博客
    q.push(1);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (i = 0; i < 26; ++i) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            } else
                tr[u][i] = tr[fail[u]][i];
        }
    }
    scanf("%s", s);
    for (u = 1, i = 0; s[i]; ++i) {
        u = tr[u][s[i] - 'a'];
        ++siz[u];  // 记录匹配次数
    }
    for (i = 2; i <= tot; ++i) add(fail[i], i);  // 建 fail 树
    dfs(1);  // 统计子树和
    for (i = 1; i <= n; ++i) printf("%d\n", siz[match[i]]);
    return 0;
}