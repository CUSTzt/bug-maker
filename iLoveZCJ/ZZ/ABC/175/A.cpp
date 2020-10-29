// can i beat Mod Love?
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
constexpr int maxn = 1e6+100;
int main(){
    close;
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, tp = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            tp++;
        }else {
            ans = max(ans , tp);
            tp = 0;
        }
    }
    ans = max(ans , tp);
    cout << ans << endl;
    return 0;
}

