// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') {
            pos = i;
            break;
        }
    }
    string s1 = s.substr(0, pos + 1), s2 = s.substr(pos + 1);
    if (pos == n - 1) s2 = "";
    cout << s1 << "          z" << s2 << 'z' << endl;
    string zz = s1;
    remove(s1.begin(), s1.end(), 'a');
    cout << s1 << endl;
    cout << s2 << endl;
    if (s1 == s2)
        cout << zz << endl;
    else
        cout << ":(" << endl;
    string aa = "", bb = "";
    if (aa == bb) cout << 1 << endl;
    return 0;
}