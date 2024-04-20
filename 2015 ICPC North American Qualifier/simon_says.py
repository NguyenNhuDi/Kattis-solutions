def main():
    n = int(input())

    for i in range(n):
        x = input().split()

        if x[0] == "Simon" and x[1] == "says":
            for i in range(2, len(x)):
                print(x[i], end=' ')

            print()
main()