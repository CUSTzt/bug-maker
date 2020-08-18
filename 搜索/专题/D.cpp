// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 100;
int f[N][N];
string s;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> s){
        if(s == "0"){
            for(int k = 0; k < 26; k++){
                for(int i = 0; i < 26; i++){
                    if(f[i][k] == 0)continue;
                    for(int j = 0; j < 26; j++){
                        if(f[i][k] && f[k][j]){
                            f[i][j] = 1;
                        }
                    }
                }
            }
            cout << (f['b'-'a']['m'-'a'] ? "Yes." : "No.") << endl;
            memset(f, 0 , sizeof f);
        }else{
            f[s[0]-'a'][s[s.size()-1]-'a'] = 1;
        }
    }
    return 0;
}