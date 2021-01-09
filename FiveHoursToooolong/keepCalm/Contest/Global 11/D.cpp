#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
using pii = pair<int, int>;
// string s[maxn];
// int ans = 0;
// struct pii{
//     int first , second;
// }item[maxn];
bool cmp1(pii a, pii b){
    if(a.first > b.first) return a.first > b.first;
    else {
        return a.second < b.second;
    }
}
bool cmp2(pii a, pii b){
    if(a.first > b.first) return a.first > b.first;
    else {
        return a.second > b.second;
    }
}
bool cmp3(pii a, pii b){
    if(a.second < b.second) return a.second < b.second;
    else {
        return a.first < b.first;
    }
}
bool cmp4(pii a, pii b){
    if(a.second < b.second) return a.second < b.second;
    else {
        return a.first > b.first;
    }
}
string s;
pii item[maxn];
void up(){
    int n, ans = 0;
    cin >> n;
    stack<char> stk;
    for(int i = 1; i <= n; i++){
        item[i].first = item[i].second = 0;
        cin >> s;
        for(auto c : s){
            if(c == '('){
                stk.push(c);
            }else{
                if((!stk.empty()) && stk.top() == '('){
                    ans+=2;
                    stk.pop();
                }else {
                    stk.push(c);
                }
            }
        }
        // string tp = "";
        while(!stk.empty()){
            if(stk.top() == '(')item[i].first++;
            else item[i].second++;
            stk.pop();
        }
        // reverse(tp.begin(),tp.end());
        // s = tp;
        // item[i].id = i;
        // for(auto &c : tp){
        // if(c == '(')item[i].first++;
        // else item[i].second++;
        // }
    }
    int tp1 =0, tp2 = 0, tp3 = 0, tp4 = 0;
    sort(item+1, item+1+n, cmp1);
    int l = item[1].first;
    for(int i = 2; i <= n; i++){
        int zz = min(item[i].second, l);
        tp1 += zz*2;
        l-=zz;
        l+=item[i].first;
    }

    sort(item+1, item+1+n, cmp2);
    l = item[1].first;
    for(int i = 2; i <= n; i++){
        int zz = min(item[i].second, l);
        tp2 += zz*2;
        l-=zz;
        l+=item[i].first;
    }

    sort(item+1, item+1+n, cmp3);
    l = item[1].first;
    for(int i = 2; i <= n; i++){
        int zz = min(item[i].second, l);
        tp3 += zz*2;
        l-=zz;
        l+=item[i].first;
    }

    sort(item+1, item+1+n, cmp4);
    l = item[1].first;
    for(int i = 2; i <= n; i++){
        int zz = min(item[i].second, l);
        tp4 += zz*2;
        l-=zz;
        l+=item[i].first;
    }
    ans += max(max(max(tp1, tp2), tp3), tp4);
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int _;cin >> _;
    while(_--){
        up();
    }
}