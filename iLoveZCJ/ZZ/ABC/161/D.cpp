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
    int k;
    cin >> k;
    queue<string> q;
    for (int i = 1; i <= 9; i++) {
        q.push(to_string(i));
    }
    vector<ll> v;
    set<string> s;
    while (s.size() <= 2e5) {
        string top = q.front();
        q.pop();
        s.insert(top);
        char ch = top.back();
        if (ch == '0') {
            q.push(top + ch);
            ch++;
            q.push(top + ch);
        } else if (ch == '9') {
            q.push(top + ch);
            ch--;
            q.push(top + ch);
        } else {
            q.push(top + ch);
            ch--;
            q.push(top + ch);
            ch += 2;
            q.push(top + ch);
        }
    }
    for (auto it : s) {
        v.pb((ll)stoll(it));
    }
    sort(v.begin(), v.end());
    cout << v[k - 1];
    return 0;
}