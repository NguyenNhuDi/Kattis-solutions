input = input()

flag = True
listInput = []
listInput[:0] = input

outList = []
for c in listInput:
    if flag:
        if c == 'a':
            outList.append(c)
            flag = False
    else:
        outList.append(c)
out = ""
for c in outList:
    out += c
print(out)
