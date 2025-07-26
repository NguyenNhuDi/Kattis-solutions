#grass seed inc
p = float(input())
l = int(input())

out = 0
for i in range(l):
    x,y = [float(i) for i in input().split()]
    
    out += x * y * p

print("%.7f" % out)
