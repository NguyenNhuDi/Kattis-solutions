n = int(input())

nums = [input() for i in range(n)]

out = 0
for i in nums:
    num = int(i[0:-1])
    exp = int(i[-1])

    out += num ** exp

print(out)
