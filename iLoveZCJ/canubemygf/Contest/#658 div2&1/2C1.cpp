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
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> a, b;
    s += '0', t += '0';
    for(int i = 1; i <= n; i++){
        if(s[i] != s[i-1]) a.emplace_back(i);
        if(t[i] != t[i-1]) b.emplace_back(i);
    }
    reverse(b.begin(), b.end());
    a.insert(a.end(),b.begin(), b.end());
    cout << a.size() <<" " ;
    for(auto x : a) cout << x << ' ';
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}