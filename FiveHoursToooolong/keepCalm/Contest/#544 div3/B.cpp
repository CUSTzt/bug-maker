#include <iostream>

using namespace std;
int n, k, a[101], t, s;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        a[t % k]++;
    }
    for (int i = 1; i < (k + 1) / 2; ++i) s += min(a[k - i], a[i]);
    if (k % 2 == 0) s += a[k / 2] / 2;
    s += a[0] / 2;
    cout << 2 * s;
}