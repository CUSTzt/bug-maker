#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt","w",stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 30;

const string s0 = "1111111111111111";
const string s3 = "1111111111111110";
const string s5 = "1111111111111101";
const string s6 = "1111111111101110";
const string s7 = "1111111111111100";
const string s8 = "1111111111101100";
const string s9 = "1111111011101110";
const string s10 ="1111111111001100";
const string s11 ="1111111111111000";
const string s12 ="1111111111001000";
const string s13 ="1111111011001000";
const string s







int s;
int a[5][5];
int co[15];
int dy[10]={-1,-1,-1,0,0,1,1,1};
int dx[10]={1,0,-1,1,-1,1,-1,1};
int tar;
bool f=0;
pii d[12];

void dfs(int h){
    if(f)return;
    if(h==10){
        for(int i=1;i<=9;i++)a[d[i].fi][d[i].se]=co[i];
        int cnt=0;
        for(int i=1;i<=3;i++)for(int j=1;j<=3;j++){
            if(a[i][j]==1)continue;
            for(int z=0;z<8;z++){
                int xx=i+dx[z],yy=j+dy[z];
                if(xx>=1 && xx<=4 && yy>=1 && yy<=4 && a[xx][yy]==1)cnt++;
            }
        }
        if(cnt==tar){
            f=1;
            for(int i=1;i<=4;cout<<endl,i++)for(int j=1;j<=4;j++)cout<<a[i][j];
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<=1;i++){
        co[h]=i;
        dfs(h+1);
    }
}
void solve(){
    int id=0;
    f=0;
    for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)d[++id]={i,j};
    for(int i=1;i<=4;i++)a[i][4]=a[4][i]=1;
    for(int i=0;i<=21;i++){
        cout<<"222====="<<i<<endl;
        tar=i;
        f=0;
        dfs(1);
    }
}

int main(){
    IOS;
    solve();
    return 0;
}
