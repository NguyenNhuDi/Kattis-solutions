import sys


sys.setrecursionlimit(10**9)

class UF:
    def __init__(self, n):
        self.n = n
        self.tree = list(range(n))
        self.s = [1 for i in range(n)]

    def get_root(self, x):
        root = self.tree[x]

        if self.tree[root] != root:
            self.tree[x] = self.get_root(root)
            return self.tree[x]
        
        return root


    def join(self, x, y):
        px = self.get_root(x)
        py = self.get_root(y)

        if px == py:
            return
        
        self.tree[px] = py
        self.s[py] += self.s[px]

def main():
    n, m = [int(i) for i in input().split()]
    
    uf = UF(n)

    
    for _ in range(m):
        i, j = [int(x) - 1 for x in input().split()]
        uf.join(i, j)

    pr = 0.0
    for i in range(n):
        if uf.tree[i] != i:
            continue
        if uf.s[i] == 1:
            continue
        pr += (uf.s[i] * (uf.s[i] - 1)) / (n * (n - 1))
    print(pr)
main()
