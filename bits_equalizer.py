import math
import queue

def main():
    n = int(input())

    for i in range(n):
        s = input()
        t = input()

        z, o, q, oE, zE = 0, 0, 0, 0, 0

        for j, c in enumerate(s):
            if c == '0':
                z -= 1
            elif c == '1':
                o -= 1
            else:
                q += 1

            if t[j] == '0':
                z += 1
            else:
                o += 1

            if t[j] != s[j]:
                if s[j] =='0':
                    zE += 1
                elif s[j] == '1':
                    oE += 1
            
        # check for impossible case
        if z + o < q or o < 0:
            print(f'Case {i + 1}: -1')
            continue
            
        swaps = min(oE, zE)
        err = (oE - swaps) + (zE - swaps)

        ans = swaps + err + q

        print(f'Case {i + 1}: {int(ans)}')
main()
