import math

def main():
    div, ans = (int(x) for x in input().split())
    

    maxi = div * ans
    mini = (ans - 1) * div

    for i in range(mini+1, maxi+1):
        if math.ceil(i / div) == ans:
            print(i)
            break


main()