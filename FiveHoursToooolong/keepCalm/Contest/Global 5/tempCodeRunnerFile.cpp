#include <stdio.h>

#include <iostream>
using namespace std;
int f1(int x) {
    int s, t = 0;
    for (s = x ; s <= x + 18; s++) {
        if ((s % 4 == 0 && s % 100 != 0) || s % 400 == 0)  // 最好加一下括号
            t++;
    }
    return t;
}
int f2(int x) {
    int s, t = 0;
    for (s = x + 1; s < x + 19; s++) {
        if ((s % 4 == 0 && s % 100 != 0) || s % 400 == 0)  // 最好加一下括号
            t++;
    }
    return t;
}
int main() {
    int a, b, c, n, k, sum;
    cin >> n;
    for (int _ = 1; _ <= n; _++) { // 在外层循环用一个不太常用的符号，避免重复。
        scanf("%d-%d-%d", &a, &b, &c);
        sum = 365 * 18;
        if (b < 3)
            sum = sum + f1(a);
        else
            sum = sum + f2(a);
        if (b == 2 && c == 29 && ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)) {
            sum = -1;
        }
        cout << sum << endl;
    }
    return 0;
}
