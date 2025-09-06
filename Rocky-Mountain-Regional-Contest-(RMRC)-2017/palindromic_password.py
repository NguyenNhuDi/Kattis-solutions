from sys import stdin

def is_palindrome(x):
    x = str(x)
    for i in range(3):
        if x[i] != x[-(i + 1)]:
            return False
    return True

def main():
    palindromes =[i for i in range(100000, 1000000) if is_palindrome(i)]
    n = int(input())

    for i in range(n):
        num = int(input())

        ans = 0
        mini = 0xffffffffffffffffffffff

        for i, pali in enumerate(palindromes):
            diff = abs(num - pali)
            if diff < mini:
                ans = i
                mini = diff
        print(palindromes[ans])

if __name__ == '__main__':
    main()