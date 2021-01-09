// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
bool chk(string s, int i) {
    if (s[i - 6] != 'a' && s[i - 6] != '?') return 0;
    if (s[i - 5] != 'b' && s[i - 5] != '?') return 0;
    if (s[i - 4] != 'a' && s[i - 4] != '?') return 0;
    if (s[i - 3] != 'c' && s[i - 3] != '?') return 0;
    if (s[i - 2] != 'a' && s[i - 2] != '?') return 0;
    if (s[i - 1] != 'b' && s[i - 1] != '?') return 0;
    if (s[i - 0] != 'a' && s[i - 0] != '?') return 0;
    return 1;
}
void up() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 7; i < s.size(); i++) {
        if (chk(s, i)) {
            string t = s;
            t[i - 6] = 'a';
            t[i - 5] = 'b';
            t[i - 4] = 'a';
            t[i - 3] = 'c';
            t[i - 2] = 'a';
            t[i - 1] = 'b';
            t[i - 0] = 'a';
            for (int j = 1; j < s.size(); j++)
                if (t[j] == '?') t[j] = 'z';
            int fl = 1;
            for (int j = 7; j < s.size(); j++)
                if (j != i && chk(t, j) == 1) fl = 0;
            if (fl) {
                cout << "Yes\n";
                for (int j = 1; j < t.size(); j++) cout << t[j];
                cout << "\n";
                return;
            }
        }
    }
    cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}