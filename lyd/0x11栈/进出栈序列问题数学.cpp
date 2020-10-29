/************************************************
# @Author:      miniLCT
# @DateTime:    2019-07-15 15:31:48
# @Description: 打好acm就能和cls一样天天吃小龙虾
***********************************************/
//相当于求卡特兰数，由于数很大，所以直接计算n！会超时超内存，所以可以对分子分母进行约分，然后用大整数乘int算法计算
// CH1102_火车进出栈问题
/*
#include <cstdio>
#include <deque>
using namespace std;
const int MAX = 6e4 + 5, HEX = 1e9;
int a[MAX], b[MAX], di[MAX * 2 + 5], n;//a = (n + 1)...2n, b = (n + 1)!
deque<int> operator * (const deque<int> &op1, int op2){
        deque<int> res; int carry = 0;
        for(long long i = op1.size() - 1, tmp; i >= 0; --i)
                tmp = (long long)op1[i] * op2 + carry, res.push_front(tmp %
HEX), carry = tmp / HEX; if(carry) res.push_front(carry); return res;
}
//将arr[l...r]分解质因数到di, k为1或-1,div[i](i为素数)将a/b分解质因数后i的次幂
void resolve(int *arr, int l, int r, int k){
        for(int i = l; i <= r; ++i){
                for(int j = 2; j * j <= arr[i]; ++j) if(!(arr[i] % j)) arr[i] /=
j, di[j] += k, --j; if(arr[i] > 1) di[arr[i]] += k;
        }
}
int main(){
        scanf("%d", &n);
        for(int i = 1; i <= n + 1; ++i) a[i] = n + i, b[i] = i;
        resolve(a, 1, n, 1), resolve(b, 1, n + 1, -1);
        deque<int> res(1, 1);
        for(int i = 1; i <= n << 1; ++i) for(int j = 1; j <= di[i]; ++j) res =
res * i; printf("%d", res[0]); for(int i = 1; i < res.size(); ++i)
printf("%09d", res[i]);
}*/
// Author:XuHt
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 60006;
int ans[1000000], len = 1, p[N * 2], c[N * 2], tot = 0;
bool v[N * 2];

void gj(int x) {
    for (int i = 1; i <= len; i++) ans[i] *= x;
    len += 6;
    for (int i = 1; i <= len; i++) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while (!ans[len]) len--;
}

int main() {
    int n;
    cin >> n;
    ans[0] = 0;
    ans[1] = 1;
    memset(v, 0, sizeof(v));
    for (int i = 2; i <= n * 2; i++)
        if (!v[i]) {
            p[++tot] = i;
            for (int j = i; j <= n * 2; j += i) v[j] = 1;
        }
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= tot; i++) {
        int a = p[i];
        while (a <= n * 2) {
            c[i] += n * 2 / a - n / a - (n + 1) / a;
            a *= p[i];
        }
        while (c[i]--) gj(p[i]);
    }
    for (int i = len; i; i--) printf("%d", ans[i]);
    cout << endl;
    return 0;
}