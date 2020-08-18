#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], k, len, L[N], R[N], add[N], F[N];
// a[N]是记录数列，k指块的数目，len指块的长度
// L[N]记录每个块起始元素的下标，R[N]记录每个块末尾元素的下标
// F[N]记录每一个元素所属于哪个块，add[N]是加法标记

void Build() {
    memset(a, 0, sizeof(a));
    memset(add, 0, sizeof add);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    len = sqrt(n);
    k = n / len;  // 计算块的长度和数目
    if (n % k)
        k++;  // 特判最后一个不完整块
    for (int i = 1; i <= k; i++) {
        R[i] = i * len, L[i] = R[i - 1] + 1;
    }
    R[k] = n;  // 特判最后一个块的末尾下标为n
    for (int i = 1; i <= k; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            F[j] = i;  // 计算每个元素属于哪个块
        }
    }
}
void Add(int x, int y, int z) {
    if (F[x] == F[y]) {  // 如果区间被包含于一个整块
        for (int i = x; i <= y; i++) a[i] += z;
        return;
    }
    // 如果区间跨过整块
    for (int i = x; i <= R[F[x]]; i++) {
        a[i] += z;  // 把左边的不完整块的元素值直接改变
    }
    for (int i = L[F[y]]; i <= y; i++) {
        a[i] += z;  // 把右边的不完整块的元素值直接改变
    }
    for (int i = F[x] + 1; i < F[y]; i++) add[i] += z;  // 最后改变夹在中间整块的加法标记
}

int Ask(int x) {              // 单点查询
    return a[x] + add[F[x]];  // 直接输出原数列的值和块的加法标记
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    Build();
    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;
        if (!op)
            Add(l, r, c);
        else
            cout << Ask(r) << endl;
    }
    return 0;
}