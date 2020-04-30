#include <bits/stdc++.h>

using namespace std;
int N = 1e6;
int main() {
    int l = 1, r = N;
    while (l < r) {
        int mid = (l + r) >> 1;
        cout << mid << endl;
        string s;
        cin >> s;
        if (s[0] == '<')
            r = mid + 1;
        else
            l = mid + 1;
    }
    cout << "! " << l << endl;
}