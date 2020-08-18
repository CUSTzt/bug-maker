// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    int l, r;
} tree[500000];
int a[500000];

void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    if (l == r)
        tree[root].data = a[l];
    else {
        int mid = (l + r) / 2;
        build(root * 2 + 1, l, mid);
        build(root * 2 + 2, mid + 1, r);
        tree[root].data = tree[root * 2 + 1].data + tree[root * 2 + 2].data;
    }
}

int Query(int root, int l, int r) {
    int i = tree[root].l, j = tree[root].r;
    if (i > r || j < l) return 0;
    l = max(l, i);
    r = min(r, j);
    if (i == l && j == r) return tree[root].data;
    return Query(root * 2 + 1, l, r) + Query(root * 2 + 2, l, r);
}

void Updata(int root, int pos, int data) {
    int l = tree[root].l, r = tree[root].r;
    if (l > pos || r < pos) return;
    tree[root].data += data;
    if (l == r) return;
    Updata(root * 2 + 1, pos, data);
    Updata(root * 2 + 2, pos, data);
}

int main() {
    int t, cnt = 0;
    scanf("%d", &t);
    for (int cnt = 1; cnt <= t; cnt++) {
        memset(tree, 0, sizeof(tree));
        memset(a, 0, sizeof(a));
        int i, n;
        scanf("%d", &n);
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(0, 1, n);
        printf("Case %d:\n", cnt);
        char op[10];
        while (1) {
            scanf("%s", op);
            if (op[0] == 'E')
                break;
            else {
                int i, j;
                if (op[0] == 'A') {
                    scanf("%d %d", &i, &j);
                    Updata(0, i, j);
                } else if (op[0] == 'S') {
                    scanf("%d %d", &i, &j);
                    Updata(0, i, -1 * j);
                } else if (op[0] == 'Q') {
                    scanf("%d %d", &i, &j);
                    printf("%d\n", Query(0, i, j));
                }
            }
        }
    }
    return 0;
}