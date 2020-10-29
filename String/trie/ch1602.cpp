#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int trie[N * 32][2], tot = 1, a[N], n, ans;
void insert(int x) {
    int p = 1;
    for (int k = 30; k >= 0; k--) {
        int ch = x >> k & 1;
        if (trie[p][ch] == 0) trie[p][ch] = (++tot);
        p = trie[p][ch];
    }
}
int Search(int x) {
    int p = 1, ans = 0;
    for (int k = 30; k >= 0; k--) {
        int ch = x >> k & 1;  //取出第k位
        if (trie[p][ch ^ 1]) { //走异或路
            p = trie[p][ch ^ 1]; ans |= (1 << k);
        } else p = trie[p][ch];
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
        ans = max(ans, Search(a[i]));  //取最大值
    }
    cout << ans << endl;
}