#Thanos the Hero
def main():
    n = int(input())

    worlds = [int(x) for x in input().split()]

    out = 0
    for i in reversed(range(1,n)):
        diff = worlds[i-1] - worlds[i]

        if worlds[i] == 0 and diff == 0:
            print(1)
            return
        if worlds[i] < worlds[i-1]:
            diff = worlds[i-1] - worlds[i] + 1

            if worlds[i -1] - diff < 0:
                print(1)
                return
            out += diff
            worlds[i-1] = worlds[i-1] - diff
    print(out)

main()
