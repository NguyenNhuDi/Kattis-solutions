import math
import queue

def join(x, y, roots, sets):
    rX, rY = roots[x], roots[y]

    if rX == rY:
        return
    
    if len(sets[rX]) >= len(sets[rY]):
        for i in sets[rY]:
            sets[rX].add(i)
            roots[i] = rX
        
        sets[rY] = set()
    else:
        for i in sets[rX]:
            sets[rY].add(i)
            roots[i] = rY

        sets[rX] = set()


def mX_Y(x, y, roots, sets):
    rX, rY = roots[x], roots[y]


    if rX == rY:
        return
    sets[rX].remove(x)
    sets[rY].add(x)

    roots[x] = rY

def gSum(x, roots, sets):
    return sum(sets[roots[x]])

def gSize(x, roots, sets):
    return len(sets[roots[x]])

def main():
   
   
   while True:

        try:
            n, m = (int(x) for x in input().split())

            roots = [i for i in range(n+1)]
            sets = [{i} for i in range(n+1)]

            for _ in range(m):

                inpoo = [int(x) for x in input().split()]

                if len(inpoo) == 2:
                    x = int(inpoo[1])

                    print(f'{gSize(x, roots, sets)} {gSum(x, roots, sets)}')
                else:
                    op, x, y = inpoo

                    if op == 1:
                        join(x, y, roots, sets)
                    else:
                        mX_Y(x, y, roots, sets)
        except EOFError:
            break

                # print(roots, sets)
main()
