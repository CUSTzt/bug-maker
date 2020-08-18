#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n;
int block, sum;  // block为块的长度,sum为块的个数
int a[maxn];     //存放数列元素
int pos[maxn];   // pos记录第i个元素在第几个块中
int val[maxn];   //记录编号为i的原值
int num[maxn];   //记录众数
bool vis[maxn];  //标记数组
int maxx[2000 + 5][2000 + 5];
int tot;              //记录第几个出现的数
map<int, int> mp;     //用于将序列转换为编号
vector<int> V[maxn];  //存储编号相同时为原来的第几个值，用于二分求众数
void init(int x) {    //预处理每块间的众数
    memset(num, 0, sizeof(num));
    int modeNum = 0, id = 0;
    for (int i = (x - 1) * block + 1; i <= n; i++) {
        num[a[i]]++;
        if (num[a[i]] > modeNum || (num[a[i]] == modeNum && val[a[i]] < val[id])) {  //寻找最小众数
            modeNum = num[a[i]];                                                     //更新众数数量
            id = a[i];  //记录最小众数的编号
        }
        maxx[x][pos[i]] = id;  //记录第i块间的最小众数编号
    }
}
int dich(int L, int R, int x) {  //二分找众数
    return upper_bound(V[x].begin(), V[x].end(), R) - lower_bound(V[x].begin(), V[x].end(), L);
}
int query(int L, int R) {
    memset(vis, false, sizeof(vis));
    int res = maxx[pos[L] + 1][pos[R] - 1];  //中间一整块的众数
    int modeNum = dich(L, R, res);
    vis[res] = true;

    for (int i = L; i <= min(pos[L] * block, R); i++) {  //左边的边角料
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            int temp = dich(L, R, a[i]);
            if (temp > modeNum || (temp == modeNum && val[a[i]] < val[res])) {  //寻找最小众数
                modeNum = temp;                                                 //更新众数数量
                res = a[i];                                                     //更新答案
            }
        }
    }
    if (pos[L] != pos[R]) {                                    //存在右区间才遍历，防止重复计算
        for (int i = (pos[R] - 1) * block + 1; i <= R; i++) {  //右边的边角料
            if (!vis[a[i]]) {
                vis[a[i]] = true;
                int temp = dich(L, R, a[i]);
                if (temp > modeNum || (temp == modeNum && val[a[i]] < val[res])) {  //寻找最小众数
                    modeNum = temp;                                                 //更新众数数量
                    res = a[i];                                                     //更新答案
                }
            }
        }
    }
    return val[res];
}
int main() {
    scanf("%d", &n);
    block = 200;      //块的长度
    sum = n / block;  //块个数
    if (n % block)
        sum++;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[i] = (i - 1) / block + 1;  //第i个元素在第几块中
        if (mp[a[i]] == 0) {
            mp[a[i]] = ++tot;
            val[tot] = a[i];  //保存原始值
        }
        a[i] = mp[a[i]];  //保存为编号
        V[a[i]].push_back(i);
    }

    for (int i = 1; i <= sum; i++)  //预处理每块间的众数
        init(i);

    for (int i = 1; i <= n; i++) {
        int left, right;
        scanf("%d%d", &left, &right);
        printf("%d\n", query(left, right));
    }
    return 0;
}