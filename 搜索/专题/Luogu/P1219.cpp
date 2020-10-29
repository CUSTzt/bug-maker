// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n, cnt, column[N], row[N], xx[N], _xx[N];
void dfs(int i){
    if(i > n){
        if(cnt <= 2){
            for(int j = 1; j <= n ; j++){
                cout << row[j] << " \n"[j == n];
            }
        }
        cnt++;return ;
    }else{
        for(int j = 1; j <= n; j++){
            if(column[j]) continue;
            if(xx[i+j]) continue;
            if(_xx[n+i-j]) continue;
            row[i] = j,xx[i+j]=1,column[j]=1,_xx[n+i-j]=1;
            dfs(i+1);
            xx[i+j]=0,column[j]=0,_xx[n+i-j]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}