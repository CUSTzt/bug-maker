// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , a[N], b[N];
set<int >s;
void work(int x){
    if(x==1)s.insert(1);
    if(x==-1)s.insert(-1);
}
void up() {
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> a[i];
    }
    for(int j = 1; j <= n; j++){
        cin >> b[j];
    }
    int fl = 1;
    s.clear();
    work(a[1]);
    for(int i = 2; i <= n; i++){
        if(b[i]-a[i] > 0 && s.count(1)==0)fl=0;
        work(a[i]);
    }
    cout << (fl?"YES":"NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}