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
    string s;
    cin >> s;
    vector<int> cnt;
    int ans = 0, kp = 0;
    for(auto c:s){
        if(c == '0'){
            if(kp)cnt.push_back(kp);
            kp = 0;
        }else{
            kp++;
        }
    }
    if(kp)cnt.push_back(kp);
    
    sort(cnt.begin(),cnt.end(),greater<int>());
    for(int i = 0; i < cnt.size(); i+=2)ans+=cnt[i];
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}