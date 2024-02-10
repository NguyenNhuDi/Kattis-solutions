import math

def solve(invest, m):

    plans = []

    for i, data in enumerate(invest):
        p, c = data
        if i == 0:
            plans.append([p, c + m])
        else:
            p += plans[i-1][0]
            c += plans[i-1][1]

            plans.append([p,c])

    days = [math.ceil(x[1] / x[0]) for x in plans]

    return min(days)

def main():
    n, m = (int(x) for x in input().split())

    investments = [[int(x) for x in input().split()] for i in range(n)]

    investments = sorted(investments, key=lambda x: x[1] / x[0])

    print(solve(investments, m))

main()
