/*
 * Author: Gatevin
 * Created Time:  2015/3/3 16:08:44
 * File Name: Shana.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
 
/*
 * 首先我们考虑n是偶数的情况(n >= 6)
 * 将点分为两组一组是(1, 2, 3, ... n / 2), 另一组是(n/2 + 1, n/2 + 2, ... n)
 * 首先连接边(1, n/2 + 1) (2, n/2 + 2).. (n/2, n)且边权值都设为1
 * 那么t数组就变成了[1, 2, 3, 4, ... n/2, n/2, n/2 - 1, ... 2, 1]
 * 接下来连接(n/2 + 1, n/2 + 2)边权值设为1, 可以发现(1, 2)距离是3且t[1] + t[2] == 3
 * 接下来将(n/2 + 2, n/2 + 3) (n/2 + 3, n/2 + 4) ... (n/2 + n/2 - 1, n/2 + n/2)
 * 边权值依次设为3, 4, 5, 6,...n/2
 * 可以发现此时(1, 2) (1, 3) (1, 4) ... (1, n/2)都满足条件, 并且(2, 3)也满足条件
 * 所以对于偶数个点(n >= 6)此构造有效
 * 对于n为奇数且n >= 7而言, 分组为(1, 2, 3, ... n/2) (n/2 + 1, n/2 + 2,...,n - 1) (n)即可
 * 前面两组构造好之后把n和n - 1连接起来, 实际上也一样
 * 最后就是n == 5的情况较特殊= =, 我的这个构造方法不适用
 * 所以n == 5需要特殊讨论自己构造一个...不过我画了半天没画出来...还是参考了作者的画法..
 */
 
int n;
 // others
int main()
{
    scanf("%d", &n);
    if(n == 5)//n == 5的情况特殊讨论, 因为按照之前的构造法(1, 2)之后没有(1, 3)存在也没有(2, 3)存在
    {
        printf("1 2 3\n");//这个n == 5的解释参考作者的...自己没构造出来= =
        printf("1 3 3\n");
        printf("2 4 2\n");
        printf("4 5 1\n");
        printf("3 4\n");
        printf("3 5\n");
        return 0;
    }
    for(int i = 1; i <= (n >> 1); i++)
        printf("%d %d %d\n", i, (n >> 1) + i, 1);
    printf("%d %d %d\n", (n >> 1) + 1, (n >> 1) + 2, 1);
    for(int i = (n >> 1) + 2; i < n; i++)
        printf("%d %d %d\n", i, i + 1, i - (n >> 1) + 1);
    for(int i = 2; i <= (n >> 1); i++)
        printf("1 %d\n", i);
    printf("2 3\n");
    return 0;
}