#zoom
n, k = [int(x) for x in input().split()]

num = [int(x) for x in input().split()]

for i in range(n):
    if (i + 1) % k == 0:
        print(num[i], end =" ")
print()
