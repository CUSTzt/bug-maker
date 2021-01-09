// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
void noo() { puts("No"); }
void yes() { puts("Yes"); }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    int n, now = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < now - 1 || s.count(0))
            noo();
        else if (x == now - 1 && s.size() && *s.rbegin() > x) {
            noo();
        } else {
            while(!s.insert(x).second){ // exist
                s.erase(x);x--;
            }
            while(s.count(now))now++;
            yes();
        }
    }
    return 0;
}