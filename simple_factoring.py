def main():
    n = int(input())

    for _ in range(n):
        a, b, c = (int(x) for x in input().split())

        temp = (b * b) - (4 * a * c)

        if temp < 0:
            print("NO")
            continue

        temp **= 0.5

        if(temp == int(temp)): print("YES")
        else: print("NO")
    


main()