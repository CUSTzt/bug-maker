#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
void umax(int &x, int y) {
    if (x < y)
        x = y;
}
int n, len, len_;
int id[maxn], l[maxn], r[maxn], sum[maxn], arr[maxn], mx_num[maxn];
void ChangeBlock(int id) {  // 修改这个块需要维护的东西
    mx_num[id] = arr[l[id]];
    sum[id] = arr[l[id]];
    for (int i = l[id] + 1; i <= r[id]; i++) {
        sum[id] += arr[i];
        umax(mx_num[id], arr[i]);
    }
}
void Update(int left, int right) {
    if (id[left] == id[right])  //在同一个块内就暴力修改
    {
        for (int i = left; i <= right; i++) {
            arr[i] = sqrt(arr[i]);
        }
        ChangeBlock(id[left]);  //需要修改维护的信息
        return;
    }
    for (int i = id[left] + 1; i <= id[right] - 1; i++)
    //对于完整的块
    {
        if (mx_num[i] > 1)  //如果最大值>1,那么就暴力修改
        {
            for (int j = l[i]; j <= r[i]; j++) {
                arr[j] = sqrt(arr[j]);
            }
            ChangeBlock(i);
        }
    }
    //对于不完整的块直接暴力修改

    for (int i = left; i <= r[id[left]]; i++) {
        arr[i] = sqrt(arr[i]);
    }
    ChangeBlock(id[left]);
    for (int i = l[id[right]]; i <= right; i++) {
        arr[i] = sqrt(arr[i]);
    }
    ChangeBlock(id[right]);
}

long long Query(int left, int right)  //查询方式与数列分块入门4相同
{
    if (id[left] == id[right]) {
        long long result = 0;
        for (int i = left; i <= right; i++) {
            result += arr[i];
        }
        return result;
    }
    long long result = 0;
    for (int i = id[left] + 1; i <= id[right] - 1; i++) {
        result += sum[i];
    }
    for (int i = left; i <= r[id[left]]; i++) {
        result += arr[i];
    }
    for (int i = l[id[right]]; i <= right; i++) {
        result += arr[i];
    }
    return result;
}
int32_t main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    len = sqrt(n);
    len_ = len * 3;
    id[1] = 0;
    l[0] = 1;
    for (int i = 2; i <= n; i++) {
        id[i] = (i - 1) / len;
        if (id[i] ^ id[i - 1]) {
            l[id[i]] = i;
            r[id[i - 1]] = i - 1;
        }
    }
    r[id[n]] = n;
    for (int i = 0; i <= id[n]; i++)  //预处理一下每个块要维护的内容
    {
        ChangeBlock(i);
    }
    int opt, left, right, c;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld%lld", &opt, &left, &right, &c);
        if (opt == 0) {
            Update(left, right);
        } else {
            printf("%lld\n", Query(left, right));
        }
    }
    return 0;
}