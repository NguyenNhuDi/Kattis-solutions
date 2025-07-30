from sys import stdin

def main():
    n = 1
    while(n > 0):
        n = int(input())

        if n > 0:
            arr = []
        
            for i in range(n):
                l, r = input().split()
                h, m = map(int, l.split(':'))
                
                if h == 12:
                    h = 0

                if 'p.m' in r:
                    h += 12
                
                arr.append((h, m))

            arr.sort(key=lambda x : (x[0], x[1]))
            for item in arr:
                h, m = item
                id = "a.m."
                if h >= 12:
                    id = "p.m."
                    if h > 12:
                        h -= 12
                
                if h == 0:
                    h += 12

                if m >= 10:
                    print(f'{h}:{m} {id}')
                else:
                    print(f'{h}:0{m} {id}')
            print()

if __name__ == '__main__':
    main()