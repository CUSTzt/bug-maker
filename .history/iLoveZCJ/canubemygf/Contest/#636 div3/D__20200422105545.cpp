// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int cnt[N], ans, a[N];
void up() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 2 * k + 10; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n / 2;i++){
        cnt[1] += 2;
        


    }
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