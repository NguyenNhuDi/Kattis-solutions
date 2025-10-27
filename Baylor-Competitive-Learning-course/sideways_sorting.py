from sys import stdin

def main():
    while True:
        n, m = map(int, input().split())

        if n == 0 and m == 0:
            break

        words = ['' for i in range(m)]

        for j in range(n):
            temp = input()

            for i, c in enumerate(temp):
                words[i] += c

        print(words)
        words.sort()
        print(words)

        # for j in range(m):
            # c_word = ''
            # for i in range(n):
            #     c_word += words[i][j]
            # print(c_word)
if __name__ == '__main__':
    main()