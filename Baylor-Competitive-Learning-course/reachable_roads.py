from sys import stdin

class UF:
    def __init__(self, n):
        self.uf = [i for i in range(n)]

    def get_root(self, x):
        root = x
        while self.uf[root] != root:
            root = self.uf[root]

        while self.uf[x] != root:
            temp = self.uf[x]
            self.uf[x] = root
            x = temp

        return root
    
    def join(self, x, y):
        rX = self.get_root(x)
        rY = self.get_root(y)

        if rX == rY:
            return
        
        self.uf[rX] = rY

def main():
    n = int(input())

    for _ in range(n):
        m = int(input())
        r = int(input())

        uf = UF(m)

        for i in range(r):
            a, b = map(int, input().split())

            uf.join(a, b)

        tracker = set()

        for i in range(m):
            tracker.add(uf.get_root(i))

        print(len(tracker) - 1)

if __name__ == '__main__':
    main()