#include <iostream>

using namespace std;

string str;

bool check(int i, string de) {
    bool ret = true;
    for (int j = 0; j < de.size() - 1; j++) {
        if (str[i - 1 - j] != de[de.size() - 2 - j]) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main() {
    cin >> str;

    string dm = "dream", dmr = "dreamer", es = "erase", esr = "eraser";
    bool flag = true;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == 'm') {
            flag = check(i, dm);
            i -= 4;
        } else if (str[i] == 'e') {
            flag = check(i, es);
            i -= 4;
        } else if (str[i] == 'r') {
            if (i - 2 >= 0) {
                if (str[i - 2] == 'm') {
                    flag = check(i, dmr);
                    i -= 6;
                } else if (str[i - 2] == 's') {
                    flag = check(i, esr);
                    i -= 5;
                } else {
                    flag = false;
                }
            } else {
                flag = false;
            }
        } else {
            flag = false;
        }
        if (!flag) {
            break;
        }
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
