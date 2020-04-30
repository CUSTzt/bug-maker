n, m =map(int , input().split())
A = list(map(int , input().split))
B = list(sorted(set(A)))
for i in range (len(B) - 1 , -1 , -1):
    if i:
        B[i] -= B[i-1]
    if len(B) > m:
        B = B[0:m]
    while len(B) < m:
        B.append(0)