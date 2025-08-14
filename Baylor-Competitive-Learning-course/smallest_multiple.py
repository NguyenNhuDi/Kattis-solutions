from sys import stdin

MAXI = 65536

def sieve():
    nums = [True for i in range(MAXI + 1)]
    primes = []

    for i in range(2, MAXI + 1):
        if nums[i]:
            primes.append(i)

        for j in range(i * 2, MAXI + 1, i):
            nums[j] = False

    return primes


def main():
    primes = sieve()

    for line in stdin:
        nums = set([int(x) for x in line.split('\n')[0].split()])

        tracker = {}

        for num in nums:
            temp = num
            for p in primes:
                if p * p > temp:
                    break
                count = 0

                while temp % p == 0:
                    count += 1
                    temp //= p
                if p in tracker:
                    tracker[p] = max(tracker[p], count)
                else:
                    tracker[p] = count

            if temp > 1:
                if temp in tracker:
                    tracker[temp] = max(tracker[temp], 1)
                else:
                    tracker[temp] = 1

        out = 1

        for x in tracker:
            out *= (x ** tracker[x])
        print(int(out))




if __name__ == '__main__':
    main()