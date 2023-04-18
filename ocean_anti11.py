#Ocean's Anti-11
dp = [0 for i in range(10001)]

MOD = 1000000007
def f(n):
    if n == 2:
        return 3
    if n == 1:
        return 2
    if dp[n] != 0:
        return dp[n]
    
    dp[n] = (f(n-1) % MOD + f(n-2) % MOD) % MOD

    return dp[n]

n = int(input())

for i in range(n):
    t = int(input())
    print(f(t))
