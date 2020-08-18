#include <bits/stdc++.h>
#define REP(i, first, last) for (int i = first; i <= last; ++i)
#define DOW(i, first, last) for (int i = first; i >= last; --i)
using namespace std;
const int MAXN = 1e5 + 5;
const int SQRT_MAXN = 505;
const long long INF = 1e18;
int n;
int len, len_;
int id[MAXN];
int l[MAXN], r[MAXN];
long long lazy[SQRT_MAXN];
long long arr[MAXN];
long long sum[MAXN];  //在第一题的基础上记录每个块的和
void Updata(int left, int right, long long add) {
    if (right - left < len_) {
        REP(i, left, right) {
            arr[i] += add;
            sum[id[i]] += add;
        }
        return;
    }
    REP(i, id[left] + 1, id[right] - 1) { lazy[i] += add; }
    REP(i, left, r[id[left]]) {
        arr[i] += add;
        sum[id[left]] += add;
    }
    REP(i, l[id[right]], right) {
        arr[i] += add;
        sum[id[right]] += add;
    }
}
long long Query(int left, int right) {
    if (right - left < len_)  //小范围暴力查询
    {
        long long result = 0;
        REP(i, left, right) { result += arr[i] + lazy[id[i]]; }
        return result;
    }
    long long result = 0;
    REP(i, id[left] + 1, id[right] - 1)  //对于完整的块直接查询每个块的和就可以了
    {
        result += sum[i] + lazy[i] * (r[i] - l[i] + 1);
    }
    //对于不完整的块暴力查询
    REP(i, left, r[id[left]]) { result += arr[i] + lazy[id[left]]; }
    REP(i, l[id[right]], right) { result += arr[i] + lazy[id[right]]; }
    return result;
}
int main() {
    scanf("%d", &n);
    REP(i, 1, n) { scanf("%lld", &arr[i]); }
    len = sqrt(n);
    len_ = len * 3;
    id[1] = 0;
    l[0] = 1;
    sum[0] = arr[1];
    REP(i, 2, n) {
        id[i] = (i - 1) / len;
        sum[id[i]] += arr[i];
        if (id[i] ^ id[i - 1]) {
            l[id[i]] = i;
            r[id[i - 1]] = i - 1;
        }
    }
    r[id[n]] = n;
    int opt, left, right;
    long long x, answer;
    REP(i, 1, n) {
        scanf("%d%d%d%lld", &opt, &left, &right, &x);
        if (opt == 0) {
            Updata(left, right, x);
        }
        if (opt == 1) {
            printf("%lld\n", Query(left, right) % (x + 1));
        }
    }
    return 0;
}