from sys import stdin

def f(a, b, c, x):
    return a * (x ** 2) + b * x + c

def main():
    n, t = map(int, input().split())
    funcs = [[float(x) for x in input().split()] for i in range(n)]
    nums = [0 for i in range(n)]

    for idx in range(t * 1000):
        maxi = -1        
        idx = 0
        for i, func in enumerate(funcs):
            diff = f(*func, nums[i] + 0.001) - f(*func, nums[i])

            if diff > maxi:
                maxi = diff
                idx = i
        nums[idx] += 0.001

    sumi = 0
    for i, func in enumerate(funcs):
        sumi += f(*func, nums[i])
    print(sumi / n)

if __name__ == '__main__':
    main()