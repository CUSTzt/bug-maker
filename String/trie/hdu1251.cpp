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
        ed[rt]++;
    }
    // ed[rt]++;
}
int find(char *s, int rt) {
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (trie[rt][x] == 0) return 0;
        rt = trie[rt][x];
        ans += ed[rt];
    }
    return ed[rt];
}
char s[15];
int main() {
    memset(ed, false, sizeof(ed));
    while (cin.getline(s,15)) {
        // cout << s << endl;
        if (s[0] == ' ' || strlen(s) == 0) break;
        insert(s, 0);
        // cout << "11 " <<endl;
    }
    while (cin.getline(s,15)) {
        printf("%d\n", find(s,0));
    }

    return 0;
}
