a, b = input().split(" ")

a = int(a)
b = int(b)


c = [(x, y)for x in range(1,a+1) for y in range(1,b+1)]


r = [sum(x) for x in c]

set_r = set(r)

maxm = 0
result = []
for temp in set_r:
    tt = r.count(temp)
    if tt > maxm:
        result.clear()
        maxm=tt
        result.append(temp)
    elif tt == maxm:
        result.append(temp)

for i in result:
    print(i)

