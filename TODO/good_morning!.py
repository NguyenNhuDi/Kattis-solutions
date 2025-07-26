#Good Morning!
allNum = set()

def buildNum(number,digit):
    
    if number > 200:
        return

    if digit == 1 or digit == 4 or digit == 2 or digit == 5:
        #dont pick
        buildNum(number,digit+3)
        buildNum(number,digit+1)      

        #pick
        number *= 10
        number += digit

        if(number <= 200):
            allNum.add(number)

        buildNum(number,digit)
        buildNum(number,digit + 3)
        buildNum(number,digit + 1)

    if digit == 8:
        buildNum(number,digit+1)
        buildNum(number,0)

        #pick
        number *= 10
        number += digit

        if(number <= 200):
            allNum.add(number)

        buildNum(number,digit)
        buildNum(number,0)
        buildNum(number,digit + 1)

    if digit == 7:
        buildNum(number,digit+1)
        number *= 10
        number += digit

        if(number <= 200):
            allNum.add(number)

        buildNum(number,digit)
        buildNum(number,digit + 1)

    if digit == 3 or digit == 6:
        buildNum(number,digit+3)

        number *= 10
        number += digit

        if(number <= 200):
            allNum.add(number)

        buildNum(number,digit)
        buildNum(number,digit + 3)

    if digit == 9:
        number *= 10
        number += digit

        if(number <= 200):
            allNum.add(number)
        buildNum(number,9)
    if digit == 0:
        
        number *= 10
        number += digit
        if(number <= 200):
            allNum.add(number)
        if number != 0:
            buildNum(number,0)

buildNum(0,1)


n = int(input())

for i in range(n):
    a = int(input())
    c = 100000
    out = -1
    for j in allNum:
        diff = abs(j - a)
        if diff < c:
            c = diff
            out = j

    print(out) 
