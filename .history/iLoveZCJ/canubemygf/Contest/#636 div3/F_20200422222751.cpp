#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long LL;

typedef unsigned long long ull;

const int inf = 0x3f3f3f3f;

const int N = 2e5 + 100;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
    //	ios::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        vector<set<int>> seg;
        int n;
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            set<int> st;
            int k;
            scanf("%d", &k);
            while (k--) {
                int num;
                scanf("%d", &num);
                st.insert(num);
            }
            seg.push_back(st);
        }
        for (int st = 1; st <= n; st++)  //枚举第一个数
        {
            vector<int> ans;
            vector<set<int>> cur = seg;
            bool flag = true;
            for (auto &it : cur)
                if (it.count(st)) it.erase(st);
            ans.push_back(st);
            for (int i = 1; i < n; i++)  //迭代n-1次，找出剩余n-1个数
            {
                vector<int> temp;
                for (auto &it : cur)
                    if (it.size() == 1) temp.push_back(*it.begin());
                if (temp.size() != 1)  //无法找到
                {
                    flag = false;
                    break;
                }
                ans.push_back(temp.front());
                for (auto &it : cur)
                    if (it.count(temp.front())) it.erase(temp.front());
            }
            set<set<int>> all(seg.begin(), seg.end());
            if (flag)  //构造出数列后，判断是否合理
            {
                for (int l = 0; l < n - 1; l++) {
                    set<int> st;
                    for (int r = l; r < n; r++) {
                        st.insert(ans[r]);
                        if (all.count(st)) all.erase(st);
                    }
                }
            }
            if (all.empty())  //判断合理的话，直接输出答案
            {
                for (auto it : ans) printf("%d ", it);
                puts("");
                break;
            }
        }
    }
    return 0;
}