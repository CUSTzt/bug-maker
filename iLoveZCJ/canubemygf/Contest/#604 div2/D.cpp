// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
vector <int> vec, ans , tmp;
int chk(int cnt){
    ans.clear(),tmp = vec;
    while(cnt <= 3 && tmp[cnt]){
        ans.pb(cnt);
        tmp[cnt] -- ;
        if(cnt && tmp[cnt-1]){
            cnt--;
        }else cnt++;
    }
    for(int i = 0; i < 4; i++){
        if(tmp[i]) return 0;
    }
    cout << "YES\n";
    for(auto i : ans)cout << i << ' ';
    return 1;
}
void solve(){
    for(int x, i = 1; i <= 4; i++){
        cin >> x;
        vec.pb(x);
    }
    int fl = 1;
    for(int i = 0; i < 4; i++){
        if(chk(i)){
            fl = 0;
            return ;
        }
    }
    cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}