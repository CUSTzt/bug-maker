#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 1000;
//others
struct SAM {
    int last, cnt, nxt[N * 2][10], fa[N * 2], l[N * 2], num[N * 2];
    /*
    nxt:字典树类似
    fa[a]:endpos集合为a的父集合
    l[a]:这个位置所属endpos集合中字符串的最大长度
    num[a]:出现次数为a的字符串
    */
    void init() {
        last = cnt = 1;
        memset(nxt[1], 0, sizeof nxt[1]);
        fa[1] = l[1] = num[1] = 0;
    }
    int inline newnode() {
        cnt++;
        memset(nxt[cnt], 0, sizeof nxt[cnt]);
        fa[cnt] = l[cnt] = num[cnt] = 0;
        return cnt;
    }
    void add(int c) {
        int p = last;
        int np = newnode();
        last = np;
        l[np] = l[p] + 1;
        while (p && !nxt[p][c]) {
            nxt[p][c] = np;
            p = fa[p];
        }
        if (!p) {
            fa[np] = 1;  //表示这个字符在之前的字符串中没有出现过
        } else {
            int q = nxt[p][c];
            if (l[q] == l[p] + 1) {
                /*
                    找到第一个出边为c的位置，
                    len[p]表示p所属的endpos集合的最大字符串长度
                    那么len[p]+1表示p的儿子类的最短子串长度：
                    在abcdabc中
                    在最后一个c进来的时候找到前面的abc是这整个字符串的后缀，那么fa[7]=3;
                */
                fa[np] = q;
            } else {
                int nq = newnode();
                memcpy(nxt[nq], nxt[q], sizeof nxt[q]);
                fa[nq] = fa[q];
                num[nq] = num[q];
                l[nq] = l[p] + 1;
                fa[np] = fa[q] = nq;
                while (nxt[p][c] == q) {
                    nxt[p][c] = nq;
                    p = fa[p];
                }
            }
        }
    }
} sam;
char s[N];
int pos[N], st[N], top;
int main() {
    scanf("%s", s);
    sam.init();
    int len = strlen(s);
    pos[len] = 1;
    st[0] = len;
    for (int i = len - 1; ~i; i--) {
        while (top && s[st[top]] < s[i]) top--;
        sam.last = pos[st[top]];
        for (int j = i; j < st[top]; j++) sam.add(s[i] - 'a');
        st[++top] = i;
        pos[i] = sam.last;
    }
    ll ans = 0;
    for (int i = 2; i <= sam.cnt; i++) ans += (ll)(sam.l[i] - sam.l[sam.fa[i]]);
    printf("%lld\n", ans);
    return 0;
}
