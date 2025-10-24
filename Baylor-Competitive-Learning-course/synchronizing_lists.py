from sys import stdin

def main():
    for line in stdin:
        n = int(line.split()[0])

        if n == 0: 
            break

        a1 = [int(input()) for x in range(n)]
        a2 = [int(input()) for x in range(n)]

        a1_sorted = sorted(a1)
        a2_sorted = sorted(a2)

        tracker = {}

        for i, num in enumerate(a1_sorted):
            tracker[num] = a2_sorted[i]

        for num in a1:
            print(tracker[num])
        print()

if __name__ == '__main__':
    main()