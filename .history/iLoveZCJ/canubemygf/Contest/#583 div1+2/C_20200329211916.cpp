#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x) & (-x)
#define eps 1e-8
const int maxn = 1e6 + 10;
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            a++;
        else {
            if (a > 0)
                a--;
            else
                b++;
        }
    }
    if ((a == 0 && b == 0) || (a == 1 && b == 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}