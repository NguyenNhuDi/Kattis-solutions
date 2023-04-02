x = int(input())

# copy = 0

# list = []

# while x != 0:
#     remainder = x % 2


a = bin(x).replace("0b","")

ans = 0
counter = 0
for i in a:
    ans += int(i) *( 2 ** counter)
    counter += 1
    
print(ans)
    
