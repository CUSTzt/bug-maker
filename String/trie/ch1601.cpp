#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int tot = 1, n, m;
int trie[MAXN][26];
int ed[MAXN];
void insert(char *s, int rt) {
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (trie[rt][x] == 0) trie[rt][x] = ++tot;
        rt = trie[rt][x];
    }
    ed[rt]++;
}
int find(char *s, int rt) {
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (trie[rt][x] == 0) return ans;
        rt = trie[rt][x];
        ans += ed[rt];
    }
    return ans;
}
char s[1000500];
int main() {
    memset(ed, false, sizeof(ed));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s, 0);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", s);
        printf("%d\n", find(s, 0));
    }
    return 0;
}
