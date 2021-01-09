#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
struct Trie {
    int root, tot, nxt[MAXN][2], cnt[MAXN], end[MAXN];
    inline int Newnode() {
        memset(nxt[tot], -1, sizeof(nxt[tot]));
        cnt[tot] = 0;
        end[tot] = 0;
        return tot++;
    }
    inline void Init() {
        tot = 0;
        root = Newnode();
    }
    inline void Insert(int x) {
        int p = root;
        cnt[p]++;
        for (int i = 31; i >= 0; i--) {
            int idx = ((1 << i) & x) ? 1 : 0;
            if (nxt[p][idx] == -1) nxt[p][idx] = Newnode();
            p = nxt[p][idx];
            cnt[p]++;
        }
        end[p] = x;
    }
    inline void Del(int x) {
        int p = root;
        cnt[p]--;
        for (int i = 31; i >= 0; i--) {
            int idx = ((1 << i) & x) ? 1 : 0;
            p = nxt[p][idx];
            cnt[p]--;
        }
    }
    inline int Search(int x) {
        int p = root;
        for (int i = 31; i >= 0; i--) {
            int idx = ((1 << i) & x) ? 1 : 0;
            if (idx == 0) {
                if (nxt[p][1] != -1 && cnt[nxt[p][1]])
                    p = nxt[p][1];
                else
                    p = nxt[p][0];
            } else {
                if (nxt[p][0] != -1 && cnt[nxt[p][0]])
                    p = nxt[p][0];
                else
                    p = nxt[p][1];
            }
        }
        return x ^ end[p];
    }
    int dfs(int u) {
        cout << "u === " << u << endl;
        int l = 0, r = 0;
        if (!nxt[u][0] && !nxt[u][1]) {
            return cnt[u];
        }
        if (nxt[u][0]) l = dfs(nxt[u][0]);
        if (nxt[u][1]) r = dfs(nxt[u][1]);
        if (!nxt[u][0] || !nxt[u][1]) return l + r;
        return (max(l, r) + min(l, r) == 0 ? 0 : 1);
    }
} tr;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);
    int n;
    cin >> n;
    tr.Init();
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        tr.Insert(x);
    }
    cout << n-tr.dfs(0) << endl;
}