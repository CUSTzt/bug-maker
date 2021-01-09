#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, y, z;
int main() {
    cin >> x >> y >> z;
    int max_ = max(max(x, y), z);
    if (max_ == x) {
        if (max_ > y + z) {
            cout << "+" << endl;
            return 0;
        }
    }
    if (max_ == y) {
        if (max_ > x + z) {
            cout << "-" << endl;
            return 0;
        }
    }
    if (x == y && z == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << "?" << endl;
}