import math
import queue

# def check_const()

def solve(equations, depths):

    for k in range(1, 1001):
        dMap = {}
        fSol = True

        for i, d in enumerate(depths):
            t, c = equations[i]

            if d not in dMap:
                dMap[d] = t * k + c
            else:
                if t * k + c != dMap[d]:
                    fSol = False
                    break
           
        if fSol:
            return k

    return -1


def main():
    n = int(input())

    equations = []
    depths = []
    stack = []
    for _ in range(n):
        inpoo = input()

        if inpoo[-1] == '{':
            depths.append(len(stack))
            stack.append(1)
        else:
            stack.pop()
            depths.append(len(stack))


        nS = 0
        nT = 0

        for i in inpoo[:-1]:
            if i == 's':
                nS += 1
            else:
                nT += 1
        equations.append((nT, nS))


    print(solve(equations, depths))

main()