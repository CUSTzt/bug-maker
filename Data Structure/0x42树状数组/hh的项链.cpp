#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 1000119
int num[maxn], tree[maxn], vis[maxn], ans[maxn], N, m;
// num数组保存原数列，tree树状数组，ans保存结果
struct tt {
    int l, r;  //左右边界
    int pos;   //原位置（因为我们要离线排序后处理）
};
tt ask[maxn];
bool cmp(tt x, tt y) { return x.r < y.r; }
int lowbit(int n) { return n & (-n); }
void add(int n, int now) {
    while (n <= N) {
        tree[n] += now;
        n += lowbit(n);
    }
}
int sum(int n) {
    int ans = 0;
    while (n != 0) {
        ans += tree[n];
        n -= lowbit(n);
    }
    return ans;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &num[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &ask[i].l, &ask[i].r);
        ask[i].pos = i;  //存储初始位置
    }
    sort(ask + 1, ask + 1 + m, cmp);  //按r排序
    int next = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = next; j <= ask[i].r; j++) {
            if (vis[num[j]]) add(vis[num[j]], -1);
            //之前打过标记，在之前的位置加上-1，保证无重复
            add(j, 1);
            vis[num[j]] = j;
        }
        next = ask[i].r + 1;
        //更新下一次查询的位置
        ans[ask[i].pos] = sum(ask[i].r) - sum(ask[i].l - 1);
        //按询问编号存储每组询问的结果
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
    return 0;
}