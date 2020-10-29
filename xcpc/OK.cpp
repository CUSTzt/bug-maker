#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int queen[N][N];
int cnt = 0;          // 记录方案数
vector<int> v[1000];  // 用vector存储可行解，输出可行矩阵
bool check(int x) {   // 检查是不是可行
    for (int i = 0; i < x; i++) {
        // 如果在同一列，斜对角线，则会攻击到，就不是合法方案。
        if (queen[x] == queen[i] || (abs(x - i) == abs(queen[x] - queen[i])))
        {
            return 0;
        }
    }
    return 1;
}
void jilu(){
    for(int i = 0; i < N; i++){
        v[cnt].push_back(queen[i] + 1);
    }
}
void dfs(int x){
    if(x > N)return ;
    if(x == N) { //可行解。
        cnt++;
        jilu();
        cout << '1' << endl;
        return ;
    }
    for(int i = 0; i < N; i++){
        queen[x] = i;
        if(check(x)){
            dfs(i+1);
        }
    }
}
int main() {
    dfs(0);
    cout << "八皇后问题一共有" << cnt << " 种解法" << endl;
}