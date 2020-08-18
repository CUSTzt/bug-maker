#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 5;
const int SQRT_MAXN = 1005;
const int INF = LONG_LONG_MAX;
int n;
int len, len_;              //记录块长
int id[MAXN];               //记录每个点所属的块
int l[MAXN], r[MAXN];       //记录每个块的区间
long long lazy[SQRT_MAXN];  //记录标记
long long arr[MAXN];        //记录原序列
long long sor[MAXN];        //记录排完序的序列
void Sort(int id)           //排序操作
{
    for (int i = l[id]; i <= r[id]; i++) sor[i] = arr[i];
    sort(sor + l[id], sor + r[id] + 1);
}
void Updata(int left, int right, long long add)  //修改操作
{
    if (id[left] == id[right])  //在同一个块就暴力修改然后重新排序
    {
        for (int i = left; i <= right; i++) arr[i] += add;
        Sort(id[left]);
        return;
    }
    for (int i = id[left] + 1; i <= id[right] - 1;
         i++)  //对于中间的块直接修改标记就可以了
    {
        lazy[i] += add;
    }
    //对于两边不完整的块保留修改后排序
    for (int i = left; i <= r[id[left]]; i++) arr[i] += add;
    Sort(id[left]);
    for (int i = l[id[right]]; i <= right; i++) arr[i] += add;
    Sort(id[right]);
}
int Smaller(int id, long long x)  //二分
{
    int left = l[id];  //二分的范围
    int right = r[id];
    int answer = l[id];
    int middle;
    while (left <= right) {
        middle = (left + right) >> 1;
        if (sor[middle] + lazy[id] /*需要加上标记*/ < x) {
            answer = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    if (sor[answer] + lazy[id] < x) {
        return sor[answer] + lazy[id];
    }
    return -INF;
}
int Query(int left, int right, long long x)  //查询操作
{
    if (right - left < len_) {  // 小范围暴力查询
        int result = -INF;
        for (int i = left; i <= right; i++) {
            if (arr[i] + lazy[id[i]] < x) {
                result = max(result, arr[i] + lazy[id[i]]);
            }
        }
        return result;
    }
    int result = -INF;
    for (int i = left; i <= r[id[left]]; i++)  //完整的块二分查询
    {
        if (arr[i] + lazy[id[left]] < x) {
            result = max(result, arr[i] + lazy[id[left]]);
        }
    }
    for (int i = l[id[right]]; i <= right; i++)  //不完整的块暴力查询
    {
        if (arr[i] + lazy[id[right]] < x) {
            result = max(result, arr[i] + lazy[id[right]]);
        }
    }
    for (int i = id[left] + 1; i <= id[right] - 1; i++) {
        result = max(result, Smaller(i, x));
    }
    return result;
}
void build() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    len = sqrt(n);
    len_ = n / len;
    if (n % len) len_++;
    for (int i = 1; i <= len_; i++) {
        r[i] = i * len, l[i] = r[i - 1] + 1;
    }
    r[len_] = n;
    for (int i = 1; i <= len_; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            id[j] = i;
        }
    }
    for (int i = 0; i <= id[n]; i++) Sort(i);
}
int32_t main() {
    build();
    int opt, left, right, ans;
    long long x;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld%lld", &opt, &left, &right, &x);
        if (opt == 0) {
            Updata(left, right, x);
        }
        if (opt == 1) {
            ans = Query(left, right, x);
            if (ans == -INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
