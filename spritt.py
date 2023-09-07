n, s = input().split()
n = int(n)
s = int(s)


sum = 0
for i in range(n):
    sum += int(input())

print("Jebb" if sum <= s else "Neibb")
