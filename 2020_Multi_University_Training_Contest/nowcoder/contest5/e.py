def third_way(a,b):
    """
    第三种方法思想：stein算法
        gcd(a,a)=a，也就是一个数和其自身的公约数仍是其自身。
        gcd(ka,kb)=k gcd(a,b)，也就是最大公约数运算和倍乘运算可以交换。特殊地，当k=2时，说明两个偶数的最大公约数必然能被2整除。
        当k与b互为质数，gcd(ka,b)=gcd(a,b)，也就是约掉两个数中只有其中一个含有的因子不影响最大公约数。特殊地，当k=2时，说明计算一个偶数
    和一个奇数的最大公约数时，可以先将偶数除以2。
    :param a: 第一个数
    :param b: 第二个数
    :return: 最大公约数
    """
    #保证b比a小
    if a < b:
        a, b = b, a
 
    if (0 == b):
        return a
    # a,b都是偶数 除2右移一位即可
    if a % 2 == 0 and b % 2 == 0:
        return 2 * third_way(a >> 1, b >> 1)
    # a是偶数
    if a % 2 == 0:
        return third_way(a >> 1, b)
    # b是偶数
    if b % 2 == 0:
        return third_way(a, b >> 1)
    # 都是奇数
    return third_way((a + b) >> 1, (a - b) >> 1)

# 求两个数的最小公倍数
def lcm(a,b):
    return a * b // third_way(a, b)

def dfs(x):
    if vis[x]:
        return 0
    vis[x] = 1
    return dfs(a[x]) + 1
n = int(input())
a = [0]*(n+20)
# for x in input().split():
#     a.append(int(x))

vis = [0] * (n + 2)
ans = 1
for i in range(1, n+1):
    if vis[i] == 0:
        xx = ans
        yy = dfs(i)
        ans = lcm(xx , yy)
print(ans % (10 ** n))