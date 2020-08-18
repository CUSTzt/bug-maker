s = input()
st = ''
for ch in s:
    if ch == '(':
        st += '**'
    st += ch
print(eval(st))