import math
import queue

def main():
    n = int(input())

    vars = {}
    heights = [set() for i in range(n)]

    noPrint = False
    depth = 0
    for i in range(n):
        inpoo = input().split()

        if noPrint:
            continue

        if len(inpoo) == 1:

            if inpoo[0] == '{':
                depth += 1
            else:
                
                for v in heights[depth]:

                    if v in vars:
                        del vars[v][depth]

                        if len(vars[v]) == 0:
                            del vars[v]

                heights[depth] = set()

                depth -= 1

        elif len(inpoo) == 2:
            _, var = inpoo

            if var in vars:
                mLen = max(vars[var])
                print(vars[var][mLen])
            else:
                print('UNDECLARED')
           
        elif len(inpoo) == 3:
            _, var, vType = inpoo

            if var not in vars:
                vars[var] = {
                    depth : vType
                }

            else:
                if depth in vars[var]:
                    print('MULTIPLE DECLARATION')
                    noPrint = True
                    continue
                
                vars[var][depth] = vType



            heights[depth].add(var)


       
main()
