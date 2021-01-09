#include <bits/stdc++.h>

using namespace std;
int n;
// int t;
int main() {
    cin >> n;
    if (n == 1) {
        cout << "1" << endl;
        cout << "1 1" << endl;
        return 0;
    } else if (n == 2) {
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1 2" << endl;
        return 0;
    } else if (n == 3) {
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "2 1" << endl;
        cout << "2 2" << endl;
    } else if (n == 4) {
        cout << "3" << endl;
        cout << "1 1" << endl;
        cout << "1 3" << endl;
        cout << "3 1" << endl;
        cout << "3 3" << endl;
    } else {
        int fyz;
        if (n % 2 == 0)
            fyz = n / 2 + 1;
        else
            fyz = (n + 1) / 2;
        cout << fyz << endl;
        int k = 0;
        for (int i = 1; i <= fyz; i++) {
            k++;
            cout << i << " " << i << endl;
            if (k == n) break;
            k++;
            cout << i << " " << i + 1 << endl;
            if (k == n) break;
        }
    }
}