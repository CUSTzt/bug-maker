#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6 + 10;
struct BST {
    int l, r;  // 左右子节点在数组中的下标
    int val;   // 结点关键码
} a[SIZE];
int tot, root, INF = 1 << 30;

int New(int val) {
    a[++tot].val = val;
    return tot;
}
void build() {
    New(-INF), New(INF);
    root = 1, a[1].r = 2;
}

// BST 的检索
int Get(int p, int val) {
    if (p == 0) return 0;           // 检索失败
    if (val == a[p].val) return p;  // 检索成功
    return val < a[p].val ? Get(a[p].l, val) : Get(a[p].r, val);
}
// BST 的插入
void Insert(int &p, int val) {
    if (p == 0) {
        p = New(val);  // p是引用，其父节点的l或r值会被同时更新
        return;
    }
    if (val == a[p].val) return;
    if (val < a[p].val)
        Insert(a[p].l, val);
    else
        Insert(a[p].r, val);
}
int GetNect(int val) {  // 求后继
    int ans = 2;        // a[2].val = INF
    int p = root;
    while (p) {
        if (val == a[p].val) {  // 检索成功
            if (a[p].r > 0) {   // 有右子树
                p = a[p].r;
                // 右子树一直往左走
                while (a[p].l > 0) p = a[p].l;
                ans = p;
            }
            break;
        }
        // 每经过一个结点，都尝试更新后继
        if (a[p].val > val && a[p].val < a[ans].val) ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return ans;
}
void Remove(int &p, int val) {
    if (p == 0) return;
    if (val == a[p].val) {  // 从子树p中删除值为val的节点
        if (a[p].l == 0) { // 没有左子树
            p = a[p].r; // 右子树代替p的位置，p是引用
        } else if (a[p].r == 0) { //// 没有右子树
            p = a[p].l;// 左子树代替p的位置，p是引用
        } else {
            int nxt = a[p].r; //求后继结点
            while (a[nxt].l > 0) nxt = a[nxt].l;
            //nxt一定没有左子树，直接删除
            Remove(a[p].r, a[nxt].val);
            // 令结点nxt代替结点p的位置
            a[nxt].l = a[p].l, a[nxt].r = a[p].r;
            p = nxt; // p是引用
        }
        return;
    }
    if (val < a[p].val) {
        Remove(a[p].l, val);
    } else {
        Remove(a[p].r, val);
    }
}

// 期望 O（log N） 但是很容易退化成O（N）
int main() {}