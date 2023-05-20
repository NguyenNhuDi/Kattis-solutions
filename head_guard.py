#Head Guard
import sys

while True:
    input_ = sys.stdin.readline()
    if input_ == '':
        break
    
    array = list(str(input_))
    array.pop(-1)
    
    counter = 0
    
    prevC = '1'
    
    for c in array:
        if prevC != c and prevC != '1':
            print(counter,end="")
            print(prevC, end="")
            counter = 1
        else:
            counter += 1
        prevC = c

    print(counter,end="")
    print(prevC, end="")
    print()
