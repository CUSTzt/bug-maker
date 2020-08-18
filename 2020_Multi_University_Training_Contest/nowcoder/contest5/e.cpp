#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxn =300003, INF = 0x7f7f7f7f;
int low[maxn], a[maxn];
int n, ans;
 
int binary_search(int *a, int R, int x)
//二分查找，返回a数组中第一个>=x的位置 
{
    int L = 1, mid;
    while(L <= R)
    {
        mid = (L+R) >> 1;
        if(a[mid] <= x)
            L = mid + 1;
        else 
            R = mid - 1;
    }
    return L;
}
 
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) 
    {
        scanf("%d", &a[i]); 
        low[i] = INF;   //由于low中存的是最小值，所以low初始化为INF 
    }
    low[1] = a[1]; 
    ans = 1;   //初始时LIS长度为1 
    for(int i=2; i<=n; i++)
    {
        if(a[i] > low[ans])    //若a[i]>=low[ans]，直接把a[i]接到后面 
            low[++ans] = a[i];
        else       //否则，找到low中第一个>=a[i]的位置low[j]，用a[i]更新low[j] 
            low[binary_search(low, ans, a[i])] = a[i];
    }
    printf("%d\n", ans);   //输出答案 
    return 0;
}