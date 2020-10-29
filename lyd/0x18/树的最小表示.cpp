#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define eps 1E-8
/*注意可能会有输出-0.000*/
#define Sgn(x) \
    (x < -eps ? -1 : x < eps ? 0 : 1)  // x为两个浮点数差的比较,注意返回整型
#define Cvs(x) (x > 0.0 ? x + eps : x - eps)    //浮点数转化
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)  //判断是否等于0
#define mul(a, b) (a << b)
#define dir(a, b) (a >> b)
typedef long long ll;
typedef unsigned long long ull;
const int Inf = 1 << 28;
const ll INF = 1ll << 60;
const double Pi = acos(-1.0);
const int Mod = 1e9 + 7;
const int Max = 3050;
char str[Max];
string dfs(int now) {
    vector<string> vec;
    while (str[now] == '0')  //可看做‘(’
    {
        vec.push_back('0' + dfs(now + 1));
        now += vec.back().size();  //末尾元素的长度
    }
    string tem;
    sort(vec.begin(), vec.end());  //将01序列进行排序
    int m = vec.size();
    for (int i = 0; i < m; ++i) tem += vec[i];
    return tem + '1';  //看做‘)’
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        string op1 = dfs(0);
        scanf("%s", str);
        string op2 = dfs(0);
        if (op1 == op2)
            printf("same\n");
        else
            printf("different\n");
    }
    return 0;
}