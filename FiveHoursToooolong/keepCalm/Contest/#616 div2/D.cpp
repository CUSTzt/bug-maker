// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int cnt[N][26], l, r, len;
string s;
void up() {
    cin >> l >> r;
    --l, --r;
    if(l == r){
        cout << "YES\n";
        return;
    }
    if(s[l]!= s[r]){
        cout << "YES\n";
        return ;
    }
    int tp = 0;
    for(int i = 0; i < 26;i++){
        int R = cnt[r][i], L = 0;
        if(l > 0) L = cnt[l-1][i];
        if(R>L)tp++;
    }
    if(tp >= 2){
        cout << "YES\n";return;
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int _;
    cin >> _;
    len = s.size();
    for (int i = 0; i < len; i++) {
        cnt[i][s[i] - 'a']++;
        if (i > 0) {
            for (int j = 0; j < 26; j++) {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
    }
    while (_--) up();
    return 0;
}