/**
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
|Esc|   | F1| F2| F3| F4| | F5| F6| F7| F8| | F9|F10|F11|F12| |P/S|S L|P/B|  ┌┐    ┌┐    ┌┐
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
|~ `|! 1|@ 2|# 3|$ 4|% 5|^ 6|& 7|* 8|( 9|) 0|_ -|+ =| BacSp | |Ins|Hom|PUp| |N L| / | * | - |
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
| Tab | Q | W | E | R | T | Y | U | I | O | P |[ {|] }| | \ | |Del|End|PDn| | 7 | 8 | 9 |   |
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + |
| Caps | A | S | D | F | G | H | J | K | L |; :|" '| Enter  |               | 4 | 5 | 6 |   |
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
| Shift  | Z | X | C | V | B | N | M |< ,|> .|? /|  Shift   |     | ↑ |     | 1 | 2 | 3 |   |
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E||
| Ctrl|Win |Alt |         Space         | Alt| Fn |    |Ctrl| | ← | ↓ | → | |   0   | . |←-┘|
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
**/
/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-23 12:35:16
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int SG[2000], mex[2000];
/*void get_SG(int n){
    SG[0] = 0;
    for(int i = 1; i <= n; i++){
        memset(mex, 0 , sizeof mex);
        for(int j = 0; j < i ; j++){
            mex[SG[j]] = 1;
        }
        for(int k = 1; k < i; k++){
            for(int h = 1; h < i; h++){
                if(i - k - h <= 0)break;
                int ll = i - k - h;
                mex[SG[k] ^ SG[h] ^ SG[ll]] = 1;
            }
        }
        for(int p = 0; ;p++){
            if(!mex[p]){
                SG[i] = p;
                break;
            }
        }
    }
}*/
int work(int x){
    if(x % 8 == 0){
        return x-1;
    }
    if(x % 8 == 7){
        return x+1;
    }
    return x;
}
int s[maxn];
int main()
{
    /*freopen("out.txt", "w" , stdout);
    get_SG(100);
    for(int i = 0; i <= 99; i++){
        printf("SG[%d] === %d\n", i , SG[i]);
    }
    */
    int  t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int fl = 0;
        for(int i = 0; i < n;i ++){
            cin >> s[i];
            fl ^= work(s[i]);
        }
        if(fl){
            cout << "First player wins.\n";
        }else cout << "Second player wins.\n";
    }
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/