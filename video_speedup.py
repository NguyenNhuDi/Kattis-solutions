#video Speedup

n,p,k = [int(x) for x in input().split()]

tStamp = [int(x) for x in input().split()]

pTime = 0
out = 0
for i in range(n):
    eTime = tStamp[i] - pTime
    out += eTime * (100 + i * p)/100
    pTime = tStamp[i]

out += (k-pTime) * (100 + n * p)/100
print("%.6f" % out)
