#Code to Save Lives
n = int(input())

for i in range(n):
    x = [int(j) for j in input().split()]
    y = [int(j) for j in input().split()]
    
    first_num = 0
    second_num = 0
    counter = len(x)-1
    for digit in x:
        first_num += digit * 10 ** counter
        counter -= 1
    
    counter = len(y)-1
    
    for digit in y:
        second_num += digit * 10 ** counter
        counter -= 1
        
    sum = first_num + second_num
    out = [int(digit) for digit in str(sum)]
    
    print(*out, sep=" ")
    
