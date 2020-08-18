#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
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
} tr;

int a[MAXN];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        tr.Init();
        int n;
        cin >> n;
        int ma = 0;
        for(int i = 0; i < n; i++) cin >> a[i], tr.Insert(a[i]);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                tr.Del(a[i]);
                tr.Del(a[j]);
                ma = max(ma , tr.Search(a[i] + a[j]));
                tr.Insert(a[i]), tr.Insert(a[j]);
            }
        }
        cout << ma << endl;
    }
}