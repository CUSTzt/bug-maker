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
int chk[MAXN];
void insert(char *s, int rt) {
    for (int i = 0; s[i]; i++) {
        int x = s[i] - '0';
        if (trie[rt][x] == 0) trie[rt][x] = ++tot;
        rt = trie[rt][x];
    }
    ed[rt] = true;
}
int find(char *s, int rt) {
    for (int i = 0; s[i]; i++) {
        int x = s[i] - '0';
        if (trie[rt][x] == 0) return false;
        /*if (ed[trie[rt][x]] != 0) {
            fl = 0;
            return true;
        }*/
        rt = trie[rt][x];
    }
    if(chk[rt] == 0) {
        chk[rt] = 1;
        return 1;    
    }
    return 2;
}
int main() {
    int n , m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%s", s);
        insert(s, 0);
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        scanf("%s", s);
        int zz = find(s , 0);
        puts(zz == 0 ? "WRONG" : (zz == 1 ? "OK" : "REPEAT"));
    }
    return 0;
}