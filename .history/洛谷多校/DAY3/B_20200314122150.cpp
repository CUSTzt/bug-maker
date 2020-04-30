#include <iostream>
#include <string>
using namespace std;

const int CardsSum = 4;
int ResultValue;
int number[CardsSum];

bool PointsGame(int n) {
    if (n == 1) {
        // 如果只剩下一个数字，且这个数字是24，那么返回true，否则返回false
        if (number[0] == ResultValue)
            return true;
        else
            return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = number[i], b = number[j];
            number[j] = number[n - 1];  //压缩卡数

            // 取两个数字并且进行加减乘除运算尝试

            number[i] = a + b;
            if (PointsGame(n - 1)) return true;

            number[i] = a - b;
            if (PointsGame(n - 1)) return true;

            number[i] = b - a;
            if (PointsGame(n - 1)) return true;

            number[i] = a * b;
            if (PointsGame(n - 1)) return true;

            if (b != 0 ) {
                number[i] = a / b;
                if (PointsGame(n - 1)) return true;
            }
            if (a != 0 && (b % a) == 0) {
                number[i] = b / a;
                if (PointsGame(n - 1)) return true;
            }

            // 如果这两个数相运算无法在后面计算出24点
            // 那么回溯，找下一个数
            number[i] = a;
            number[j] = b;
        }
    }
    return false;
}
int main() {
    int i;
    int temp[4];
    int tp;
    cin >> tp;
    while (tp--) {
        (cin >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> ResultValue);
        {
            for (i = 0; i < CardsSum; ++i) number[i] = temp[i];
            if (PointsGame(CardsSum)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}