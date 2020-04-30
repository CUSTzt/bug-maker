// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
vector<int> ans, a(1 << 21);
int g, h;
int check(int x) {
    while (1) {
        if (!a[x * 2] && !a[x * 2 + 1]) {
            if (x <= (1 << g) - 1)
                return false;
            else
                return true;
        }
        if (a[x * 2] > a[x * 2 + 1])
            x *= 2;
        else
            x = x * 2 + 1;
    }
}
void work(int x) {
    while (1) {
        if (!a[x * 2] && !a[x * 2 + 1]) {
            a[x] = 0;
            return;
        } else {
            if (a[x * 2] > a[x * 2 + 1]) {
                a[x] = a[x * 2];
                x = x * 2;
            } else {
                a[x] = a[x * 2 + 1];
                x = x * 2 + 1;
            }
        }
    }
}
void up() {
    cin >> h >> g;
    int tot = 1 << h;
    // vector<int > ans , a(tot+10);
    for (int i = 1; i < tot; i++) {
        cin >> a[i];
    }
    int cnt = (1 << h) - (1 << g);
    int now=  1;
    while(cnt){
        if(check(now)){
            ans.pb(now);
            work(now);
            cnt--;
        }else now++;
    }
    ll sum = 0;
    for
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}