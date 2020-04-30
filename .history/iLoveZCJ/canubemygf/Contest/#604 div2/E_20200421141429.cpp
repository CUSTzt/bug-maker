// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char c;int n;
    while(cin >> c){
        if(c == '@'){
            break;
        }else {
            cin >> n;
            for(int i = 1; i <= n;i++)cout << 
            for(int i = 2; i < n; i++){
                for(int j = 1; j <= 2*n+1; j++){
                    if(j == n+2-i||n+1+i == j){
                        cout << c;
                    }else cout << ' ';
                }cout << endl;
            }
            for(int i = 1; i <= 2*n+1; i++){
                cout << c;
            }cout << endl;
        }
    }
    return 0;
}