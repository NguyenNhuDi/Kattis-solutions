from sys import stdin
import math

class fraction:
    def __init__(self, numer, denom):
        self.n = numer 
        self.d = denom
        self.a_gcd()

    def a_gcd(self):
        t = math.gcd(self.n, self.d)
        self.n //= t
        self.d //=t

    def __add__(self, other):
        self.n = self.n * other.d + other.n * self.d
        self.d *= other.d 
        return fraction(self.n, self.d)

    def __sub__(self, other):
        self.n = self.n * other.d - other.n * self.d
        self.d *= other.d 
        return fraction(self.n, self.d)

    def __mul__(self, other):
        self.n *= other.n
        self.d *= other.d
        return fraction(self.n, self.d)
    
    def __truediv__(self, other):
        self.n *= other.d
        self.d *= other.n
        return fraction(self.n, self.d)
    
    def __pow__(self, n):
        if n == 0:
            return fraction(1, 1)
        elif n % 2 == 0:
            return (fraction(self.n, self.d) * fraction(self.n, self.d)) ** (n // 2)
        
        return fraction(self.n, self.d) * ((fraction(self.n, self.d) * fraction(self.n, self.d)) ** ((n - 1) // 2))

    def __lt__(self, other):
        sn = self.n * other.d
        on = other.n * self.d
        return sn < on    

    def __gt__(self, other):
        sn = self.n * other.d
        on = other.n * self.d
        return sn > on        
    
    def __eq__(self, other):
        sn = self.n * other.d
        on = other.n * self.d
        return sn == on  

    


def main():
    with open("data.txt", "w") as f:
        f.write("ABC")

    with open("data.txt", "w") as f:
        f.write("DEF")

    with open("data.txt", "r") as f:
        print(f.read())
    # n = int(input())

    # lines = [[int(x) for x in input().split()] for i in range(n)]

    # maxi = -1

    # for i in range(n):
    #     x1, y1, x2, y2

if __name__ == '__main__':
    main()