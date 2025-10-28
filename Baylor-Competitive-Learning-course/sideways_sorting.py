from sys import stdin

class m_str:
    def __init__(self, s):
        self.s = s

    def __lt__(self, other):
        ms = self.s.lower()
        os = other.s.lower()

        if ms == os:
            return self.s < other.s
        return ms < os

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

        
        for i in range(m):
            words[i] = m_str(words[i])

        
        words.sort()
        
        for j in range(n):
            c_word = ''
            for i in range(m):
                c_word += words[i].s[j]
            print(c_word)
        print()
if __name__ == '__main__':
    main()