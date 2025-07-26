#Tricky Factoring
import math as m

bs = []

for i in range(1000000):
    bs.append(True)


p = []

def sieve():
    size = 1000000
    bs[0] = False
    bs[1] = False

    for i in range(2,size):
        if bs[i]:
            j = i * 2
            while j < size:
                bs[j] = False
                j += i
            p.append(i)

def numDib(N):
    sq = m.sqrt(N)
    sq = m.floor(sq)

    isSquare = False

    if sq * sq == N:
        isSquare = True

    ans = 1
    i = 0
    while (i < len(p)) and (p[i] * p[i] <= N):
        power = 0
        while N % p[i] == 0:
            N //= p[i]
            power += 1
        ans *= (power + 1)
        i += 1

    if N != 1:
        ans *= 2 
    
    if isSquare:
        return ans + 1
    else:
        return ans


def main():
    a,c = input().split()
    sieve()

    a,c = [int(a), int(c)]
        
    print(numDib(a * c))

main()


