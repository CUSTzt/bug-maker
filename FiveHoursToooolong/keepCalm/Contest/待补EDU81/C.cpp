#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int nxt[maxn][26];
char s[maxn];
char t[maxn];
int main()
{
    int T;cin>>T;
    while(T--){
        scanf("%s", s+1);
        int n = strlen(s+1);
        scanf("%s", t+1);
        int len = strlen(t+1);
        for(int i = 0; i < 26; ++i) nxt[n][i] = 0;
        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < 26; ++j) nxt[i][j] = nxt[i+1][j];
            nxt[i][s[i+1]-'a'] = i+1;
        }
        int ans = 1;
        int cur = 0;
        for(int i = 1; i <= len; ++i){
            int x = t[i]-'a';
            if(!nxt[0][x]){
                ans = -1;break;
            }
            if(nxt[cur][x]){
                cur = nxt[cur][x];
            }else{
                cur = nxt[0][x];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

