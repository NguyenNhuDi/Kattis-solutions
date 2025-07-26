#Digit Sum

def contribute(number, digits,bound):
    power = 10 ** digits
    if bound == 0:
        return power
    if digits == 0:
        return 1
    
    return number % power + 1

def f(number, digits, bound, dp):
    if digits == 0:
        return 0
    if dp[bound][digits] != -1:
        return dp[bound][digits]
    
    power = 10 ** (digits-1)

    uperBound = 0

    if bound == 1:
        uperBound = number//power
    else:
        uperBound = 9

    out = 0

    i = 0
    while i <= uperBound:
        nextBound = 0
        if bound == 1 and i == uperBound:
            nextBound = 1
        out += i * contribute(number,digits-1,nextBound)
        out += f(number % power,digits -1,nextBound,dp)

        i += 1   

    dp[bound][digits] = out
    return out 

def ilen(number):
    out = 0
    while number > 0:
        number //=10
        out += 1
    return out

def main():
    n = int(input())
    for i in range(n):
        lB,rB = input().split()

        lB,rB = [int(lB), int(rB)]

        rL = ilen(rB)
        rdp = [[-1 for j in range(18)] for i in range(2)]

        rSum = f(rB,rL,1,rdp)

        if lB == 0:
            print(rSum)
            continue

        lB -= 1
        lL = ilen(lB)
        ldp = [[-1 for j in range(18)] for i in range(2)]

        print(rSum - f(lB,lL,1,ldp))

main()
