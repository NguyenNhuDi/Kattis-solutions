n = int(input())

numbers = [int(input()) for i in range(n)]

for num in numbers:
    print(f'{num} is even' if num % 2 == 0 else f'{num} is odd')
