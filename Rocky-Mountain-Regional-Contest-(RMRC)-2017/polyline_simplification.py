from sys import stdin
import heapq

class triangle:
    def __init__(self, a, p):
        self.a = a
        self.p = p

    def __lt__(self, other):
        if self.a == other.a:
            return self.p[1] < other.p[1]
        return self.a < other.a

def area(x, y):
    return 0.5 * abs(x[0] * y[1] - x[1] * y[0])

def diff(x, y):
    return [x[0] - y[0], x[1] - y[1]]

def main():
    n, m = map(int, input().split())
    k = n - m
    points = [[int(x) for x in input().split()] for i in range(n + 1)]

    pq = []


    for i in range(1, n):
        l = points[i - 1]
        m = points[i]
        r = points[i + 1]

        a = diff(l, m)
        b = diff(r, m)

        heapq.heappush(pq, triangle(area(a, b), [i - 1, i, i + 1]))


    dead = set()

    
    while k > 0:
        l, m, r = pq[0].p
        heapq.heappop(pq)
        if l in dead or m in dead or r in dead:
            continue
        
        k -=1
        print(m)
        dead.add(m)
        # for t in pq:
        #     print(t.a, t.p)
        # go left
        if l > 0:
            nl = l - 1

            while nl in dead:
                nl -= 1

                if nl < 0:
                    break

            if nl >= 0:
                nm = l
                nr = r

                lp = points[nl]
                mp = points[nm]
                rp = points[nr]

                a = diff(lp, mp)
                b = diff(rp, mp)

                heapq.heappush(pq, triangle(area(a, b), [nl, nm, nr]))

        # go right 
        if r < n:
            nr = r + 1

            while nr in dead:
                nr += 1

                if nr > n:
                    break

            if nr <= n:
                nm = r
                nl = l

                lp = points[nl]
                mp = points[nm]
                rp = points[nr]

                a = diff(lp, mp)
                b = diff(rp, mp)

                heapq.heappush(pq, triangle(area(a, b), [nl, nm, nr]))
            

if __name__ == '__main__':
    main()