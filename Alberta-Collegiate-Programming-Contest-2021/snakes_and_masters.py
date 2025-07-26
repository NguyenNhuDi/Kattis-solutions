#snakes and masters

def fib(x):
    if x == 1 or x == 2:
        return x
    
    i = 1
    j = 2

    for _ in range(x-2):
        t = i + j
        i = j
        j = t
    return j


def main():

    x = int(input())

    print(fib(x) % 1000000)


main()
