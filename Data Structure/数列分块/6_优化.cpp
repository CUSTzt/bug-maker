#include <bits/stdc++.h>
#define REP(i, first, last) for (int i = first; i <= last; ++i)
#define DOW(i, first, last) for (int i = first; i >= last; --i)
using namespace std;
const int MAXN = 2e5 + 5;
const int MAX_SQRTN = 100005;
int n;
int len, len_;
int block_cnt = 0;
int to[MAX_SQRTN];
vector<int> vec[MAX_SQRTN];
void Insert(int place, int num) {
    int now = 0;
    int id = block_cnt;
    for (id = 1; id; id = to[id]) {
        now += vec[id].size();
        if (now >= place) {
            break;
        }
    }
    now -= vec[id].size();
    now = place - now;
    vec[id].insert(vec[id].begin() + now - 1, num);
    if (len_ < vec[id].size())  //如果这个块的大小太大了
    {
        ++block_cnt;  //添加一个新的块
        to[block_cnt] = to[id];  //这个块的下一个位置就是原来这个块的下一个位置
        to[id] = block_cnt;  //原来这个块的下一个位置变为这个块
        REP(i, vec[id].size() - len,
            vec[id].size() - 1)  //将这个过长的块的后面部分分裂到这个新的块中
        {
            vec[block_cnt].push_back(vec[id][i]);
        }
        REP(i, vec[id].size() - len, vec[id].size() - 1) { vec[id].pop_back(); }
    }
}
int Query(int place) {
    int now = 0;
    int id;
    for (id = 1; id; id = to[id]) {
        now += vec[id].size();
        if (now >= place) {
            break;
        }
    }
    now -= vec[id].size();
    now = place - now;
    return vec[id][now - 1];
}
int main() {
    scanf("%d", &n);
    len = max((int)sqrt(n * 1.5), 2);
    len_ = len * 3;
    int num;
    REP(i, 1, n) {
        scanf("%d", &num);
        vec[(i - 1) / len + 1].push_back(num);
    }
    block_cnt = (n - 1) / len + 1;
    REP(i, 1, block_cnt - 1) { to[i] = i + 1; }
    int opt, l, r, c;
    REP(i, 1, n) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if (opt == 0) {
            Insert(l, r);
        }
        if (opt == 1) {
            printf("%d\n", Query(r));
        }
    }
    return 0;
}
