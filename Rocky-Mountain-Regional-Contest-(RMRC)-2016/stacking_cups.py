from sys import stdin

def main():
    n = int(input())

    arr = []
    for i in range(n):
        l, r = input().split()

        try:
            l = int(l)
            l /= 2
            arr.append((l, r))
        except:
            r = int(r)
            arr.append((r, l))

    arr.sort(key=lambda x : x[0])
    for data in arr:
        print(data[1])

if __name__ == '__main__':
    main()