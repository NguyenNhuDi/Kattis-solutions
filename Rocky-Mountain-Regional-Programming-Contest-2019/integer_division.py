# Integer Division

def nCr(n):
   return (n * (n - 1)) // 2


nd = (int(x) for x in input().split())

n, d = nd

nums = [int(x) // d for x in input().split()]

div_counter = {}

for num in nums:
   
    if num not in div_counter:
      div_counter[num] = 1
    else:
        div_counter[num] += 1

out = 0

for num in div_counter:
   out += nCr(div_counter[num])

print(int(out))

