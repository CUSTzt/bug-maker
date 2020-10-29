#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int label = 0;
int vis[1005][1005];  // 标记有没有走过
int A[1005][1005];    // 像素 ，已知
int main() {
    // 假设1000 *1000的图
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (A[i][j] == 0) continue;
            if (A[i][j] != 255) continue;
            label++;
            A[i][j] = label;
            vis[i][j] = 1;
            stack<pair<int, int> > s;
            s.push(make_pair(i, j));
            while (!s.empty()) {
                pair<int, int> top = s.top();
                s.pop();
                for (int i = 0; i < 4; i++) {
                    int xx = top.first + dx[i], yy = top.second + dy[i];
                    if (vis[xx][yy] = 1) continue;
                    if (A[xx][yy] == 255) {
                        A[xx][yy] = label;
                        vis[xx][yy] = 1;
                        s.push(make_pair(xx, yy));
                    }
                }
            }
        }
    }
    cout << label
         << endl;  // lable是几就是几个前景的连通块，A的值相同就在同一个连通块中
}