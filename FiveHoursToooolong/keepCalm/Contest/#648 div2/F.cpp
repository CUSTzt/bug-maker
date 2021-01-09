// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

void up() {
	int n; cin >> n;
    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector <bool> vis(n);
    for (int i = 0; i < n / 2; i++) {
        int j = n - i - 1;
        for (int k = 0; k < n; k++) {
            if (!vis[k]) {
                if (a[i] == b[k] && a[j] == b[n - k - 1]) {
                    c[k] = a[i];
                    c[n - k - 1] = a[j];
                    vis[k] = vis[n - k - 1] = true;
                    break;
                }
            }
        }
    }
    if (n & 1) {
        c[n / 2] = a[n / 2];
    }
    for (int i = 0; i < n; i++) {
        if (c[i] != b[i]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _; cin >> _; while (_--) up();
	return 0;
}