#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int SQRT_MAXN = 233;
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
    int answer = -1;
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
    if (answer == -1)  //可能会没有答案,即全部大于等于
    {
        return 0;
    }
    return answer - l[id] + 1;
}
int Query(int left, int right, long long x)  //查询操作
{
    if (right - left < len_)  //对于小范围的数据,直接暴力查询
    {
        int result = 0;
        for (int i = left; i <= right; i++) {
            if (arr[i] + lazy[id[i]] < x) {
                result++;
            }
        }
        return result;
    }
    int result = 0;
    for (int i = id[left] + 1; i <= id[right] - 1;
         i++) {  //对于完整的快二分查询
        result += Smaller(i, x);
    }
    //对于不完整的块直接暴力查询
    for (int i = left; i <= r[id[left]]; i++) {
        if (arr[i] + lazy[id[left]] < x) {
            result++;
        }
    }
    for (int i = l[id[right]]; i <= right; i++) {
        if (arr[i] + lazy[id[right]] < x) {
            result++;
        }
    }
    return result;
}
void build() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    len = sqrt(n);  
    len_ = n / len;
    if(n % len) len_++;
    for(int i = 1; i <= len_; i++){
        r[i] = i * len, l[i] = r[i-1] + 1;
    }
    r[len_] = n;
    for(int i = 1; i <= len_; i++){
        for(int j = l[i]; j <= r[i]; j++){
            id[j] = i;
        }
    }
    // len_ = len * 3;
    // id[1] = 0;
    // l[0] = 1;
    // for (int i = 2; i <= n; i++) {
    //     id[i] = (i - 1) / len;
    //     if (id[i] ^ id[i - 1]) {
    //         l[id[i]] = i;
    //         r[id[i - 1]] = i - 1;
    //     }
    // }
    // r[id[n]] = n;
    for (int i = 0; i <= id[n]; i++) Sort(i);
}
int main() {
    build();
    int opt, left, right;
    long long x;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%lld", &opt, &left, &right, &x);
        if (opt == 0) {
            Updata(left, right, x);
        }
        if (opt == 1) {
            printf("%d\n", Query(left, right, x * x));
        }
    }
    return 0;
}
