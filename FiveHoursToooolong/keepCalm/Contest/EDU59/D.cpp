// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
string zz(char a) {
    switch (a) {
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'A':
            return "1010";
        case 'B':
            return "1011";
        case 'C':
            return "1100";
        case 'D':
            return "1101";
        case 'E':
            return "1110";
        default:
            return "1111";
    }
}
vector<string> a(N + 10, "");
int n;
int dfs(int x) {
    for (int i = 0; i < n; i += x) {
        for (int j = 0; j < n; j += x) {
            char tpp = a[i][j];
            for (int k = i; k < i + x; k++) {
                for (int l = j; l < j + x; l++) {
                    if (a[k][l] != tpp) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int n;
    // vector<string> a(n + 10, "");
    cin >> n;
    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;
        for (int j = 0; j < p.size(); j++) {
            a[i] += zz(p[j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (dfs(i)) {
                ans = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}