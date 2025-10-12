from sys import stdin

def main():
    n = int(input())

    out = []
    for i in range(n):
        inpoo = [int(x) for x in input().split()]

        temp = []
        for j, cost in enumerate(inpoo):
            if cost > 0:
                temp.append((cost, j, i))
        
        sorted(temp)
        
        for data in temp:
            out.append(data)
    print(len(out))
    for c, end, start in out:
        print(f'{start + 1} {end + 1} {c}')
        
if __name__ == '__main__':
    main()
    