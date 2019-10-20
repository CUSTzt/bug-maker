 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月20日 星期日 10时08分49秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
bool vis[maxn], del[10]; // vis表示是否访问过， del表示不能出现的数字
int n , m ,pre[maxn];
char text[maxn];
bool bfs(){
    queue<int >q;
    q.push(0);
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i = 0; i < 10;i++){
            if(del[i] == true || cur == 0 &&  i == 0)continue;
            int mod = (cur * 10 + i ) % n;
            if(vis[mod])continue ; //剪枝
            text[mod] = i + '0';
            vis[mod] = true;
            pre[mod] = cur;//记录上一个节点
            q.push(mod);
            if(mod == 0)return true;
        }
    }return false;
}
void print(){
    string ans;
    int pos = 0;
    while(pos != 0 || ans.empty()){
        ans += text[pos];
        pos = pre[pos];
    }
    reverse(ans.begin(),ans.end());
    puts(ans.c_str());
}
int main(){
    int kase = 0, x;
    while(cin >> n >> m){
        memset(vis, 0 , sizeof vis);
        memset(del, 0 , sizeof del);
        for(int  i = 0; i < m;i++){
            cin >> x ;
            del[x] = true;
        }
        printf("Case %d: ",++kase);
        if(!bfs())cout << -1 << endl;
        else print();
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
