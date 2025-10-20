from sys import stdin

def main():
    n = int(input())

    tracker = {}

    for i in range(n):
        word = input()

        if word not in tracker:
            tracker[word] = (i, n * 2)
        else:
            prev_i = tracker[word][0]
            prev_dis = tracker[word][1]

            tracker[word] = [i, min(prev_dis, i - prev_i)]

    out = n * 2
    for word in tracker:
        out = min(tracker[word][1], out)
    print(max(n - out, 0))

if __name__ == '__main__':
    main()