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
    int n = s.size();
    map<char , int> mp;
    for(auto &c : s) mp[c]++;
    string t = "";
    char zz;
    int cnt = 0;
    for(auto it : mp){
        if(it.ss > cnt){
            cnt = it.ss;zz = it.ff; 
        }
    }
    if(zz == 'P') zz = 'S';
    else if (zz == 'R') zz = 'P';
    else zz = 'R';
    for(int i = 0; i < n; i++){
        t += zz;
    }
    cout << t << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}