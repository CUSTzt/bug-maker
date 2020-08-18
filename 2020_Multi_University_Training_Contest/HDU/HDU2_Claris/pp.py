# 标程是
tt=int(input())
for n in range(tt):
# n=int(input())
    x=1
    for i in range(1,n):x=x^(2*x)
    print(' '.join(bin(x)[2:]))
