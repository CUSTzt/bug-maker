// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , a[N], cnt , b[10];
int main()
{
    set<int > s;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    if(s.size()>3)return cout <<"NO",0;
    else{
        for(auto it : s){
            b[cnt++] = it;
        }
        if(cnt == 1)return cout << "YES",0;
        if(cnt == 2){
            if((b[0] + b[1])%2==0)return cout << "YES",0;
            else return cout << "NO",0;
        }
        if(cnt == 3){
            if(b[2] - b[1] == b[1]-b[0]){
                return cout << "YES",0;
            }else return cout << "NO",0;
        }
    }

    return 0;
}