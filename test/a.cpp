#include <stdio.h>
#include <algorithm>

int main() {
    int a, b, c, ans;
    scanf("%d%d%d", &a, &b, &c);  // 读入数据
    int d;
    if (a > b) {
        d = a;
    } else {
        d = b;
    } // d 存的是 a，b中较大的值
    if(c > d){
        d = c; // 如果c比d大，那么c是最大的。
    }
    ans = d; // 此时d是最大的，把d赋值给ans
    // 法1

    if(a < b) a = b;
    if(a < c) a = c; // 此时a就是三个数中最大值，但是不一定是原来的a，这样写的好处就是少开了一两个变量。。
    // 法2

    ans = std::max(std::max(a, b), c);  // 用max函数（返回两个数中大的值）,a,b中最大值和c比的最大值就是三个数最大值
    // 法3

    ans = std::max({a, b, c});
    // 法4（和法3一样，更方便的写法）
    printf("max === %d\n", ans);
    return 0;
}