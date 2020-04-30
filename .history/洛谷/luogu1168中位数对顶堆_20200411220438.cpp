// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n;
int a[N];
priority_queue<int, vector<int>, less<int>> Big;
priority_queue<int, vector<int>, greater<int>> Small;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a[1];
    cout << a[1] << endl;
    int mid = a[1];
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        if(a[i] > mid){
            Small.push(a[i]);
        }else Big.push(a[i]);
        if(i & 1){
            while(Big.size() != Small.size()){
                if(Big.size() > Small.size()){
                    Small.push(mid);
                    mid = Big.top();
                    Big.pop();
                }else {
                    Big.push(mid);
                    mid = Small.top();
                    Small.pop();
                }
            }
        }
        cout << mid << endl;
    }
    return 0;
}