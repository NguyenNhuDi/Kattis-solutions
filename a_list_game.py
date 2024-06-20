def sieve():
    primes = [True for i in range(1000000)]
    primes[0] = False
    primes[1] = False

    out = []

    for i in range(2, 1000000):
        if primes[i]:
            for j in range(2 * i, 1000000, i):
                
                primes[j] = False

            out.append(i)


    return out


def main():
    num = int(input())

    out = 0

    primes = sieve()

    for i in range(len(primes)):
        if primes[i] > num: break

        while num % primes[i] == 0:
            out += 1
            num /= primes[i]

    if num != 1:
        out += 1

    print(out)



main()