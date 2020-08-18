#include <bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int tot = 1, n, fl;
int trie[MAXN][12];
char s[MAXN];
bool ed[MAXN];
void insert(char *s, int rt) {
    for (int i = 0; s[i]; i++) {
        int x = s[i] - '0';
        if (trie[rt][x] == 0) trie[rt][x] = ++tot;
        rt = trie[rt][x];
    }
    ed[rt] = true;
}
bool find(char *s, int rt) {
    for (int i = 0; s[i]; i++) {
        int x = s[i] - '0';
        if (trie[rt][x] == 0) return false;
        if (ed[trie[rt][x]] != 0) {
            fl = 0;
            return true;
        }
        rt = trie[rt][x];
    }
    return 1;
}
int main() {
    int kp;
    cin >> kp;
    for (int _ = 1; _ <= kp; _++) {
        memset(ed, false, sizeof(ed));
        memset(trie, 0, sizeof trie);
        fl = 1;
        tot = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            if (!fl) continue;
            if (find(s, 0)) fl = 0;
            insert(s, 0);
        }
        cout << (fl ? "YES" : "NO") << endl;
    }
    return 0;
}